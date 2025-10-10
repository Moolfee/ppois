#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

#include "Tape/Tape.h"
#include "State/State.h"
#include "MLogic/MLogic.h"

static void WriteTempFile(const std::string& fileName, const std::string& content){
    std::ofstream out(fileName);
    out << content;
    out.close();
}

TEST(TapeTest, InitializationAndCurrentSymbol){
    Tape tape("ABC");
    EXPECT_EQ(tape.GetCurrentSymbol(), 'A');
    EXPECT_EQ(tape.ToString(), "ABC");
}

TEST(TapeTest, WriteAndGetCurrent){
    Tape tape("XYZ");
    tape.WriteSymbol('K');
    EXPECT_EQ(tape.GetCurrentSymbol(), 'K');
    EXPECT_EQ(tape.ToString(), "KYZ");
}

TEST(TapeTest, MoveRightWithinBounds){
    Tape tape("AB");
    tape.MoveRight();
    EXPECT_EQ(tape.GetCurrentSymbol(), 'B');
    tape.WriteSymbol('C');
    EXPECT_EQ(tape.ToString(), "AC");
}

TEST(TapeTest, MoveRightBeyondEnd){
    Tape tape("Z");
    tape.MoveRight();
    EXPECT_EQ(tape.GetCurrentSymbol(), '_');
    EXPECT_EQ(tape.ToString(), "Z");
}

TEST(TapeTest, MoveLeftWithinBounds){
    Tape tape("12");
    tape.MoveRight();
    tape.MoveLeft();
    EXPECT_EQ(tape.GetCurrentSymbol(), '1');
    EXPECT_EQ(tape.ToString(), "12");
}

TEST(TapeTest, MoveLeftBeyondStart){
    Tape tape("G");
    tape.MoveLeft();
    EXPECT_EQ(tape.GetCurrentSymbol(), '_');
    EXPECT_EQ(tape.ToString(), "G");

    tape.WriteSymbol('H');
    EXPECT_EQ(tape.ToString(), "HG");
}

TEST(TapeTest, ToStringTrimsBlanks){
    Tape tape("X");
    tape.MoveRight();
    tape.MoveLeft();
    EXPECT_EQ(tape.ToString(), "X");
}

TEST(TapeTest, EmptyInitialization){
    Tape tape("");
    EXPECT_EQ(tape.GetCurrentSymbol(), '_');
    EXPECT_EQ(tape.ToString(), "_");

    tape.WriteSymbol('M');
    EXPECT_EQ(tape.ToString(), "M");
}

TEST(TapeTest, WriteBlankSymbol){
    Tape tape("A");
    tape.WriteSymbol('_');
    EXPECT_EQ(tape.ToString(), "_");
}

TEST(TapeTest, MultipleOperations){
    Tape tape("X");
    tape.MoveRight();
    tape.WriteSymbol('Y');
    tape.MoveLeft();
    tape.WriteSymbol('Z');
    EXPECT_EQ(tape.ToString(), "ZY");
}

TEST(TapeTest, MiddleBlankCharacter){
    Tape tape("A_B");
    EXPECT_EQ(tape.ToString(), "A_B");

    tape.MoveRight();
    tape.WriteSymbol('X');
    EXPECT_EQ(tape.ToString(), "AXB");
}

TEST(StateTest, NameAndTransitions){
    State s("S");
    EXPECT_EQ(s.GetName(), "S");
    EXPECT_EQ(s.FindTransition('a'), nullptr);

    s.AddTransition('a', 'b', 'L', "T");
    const State::Transition* tr = s.FindTransition('a');

    ASSERT_NE(tr, nullptr);
    EXPECT_EQ(tr->write, 'b');
    EXPECT_EQ(tr->move, 'L');
    EXPECT_EQ(tr->next, "T");
    EXPECT_EQ(s.FindTransition('c'), nullptr);
}

TEST(StateTest, MultipleTransitions){
    State s("X");
    s.AddTransition('0', '1', 'R', "X");
    s.AddTransition('1', '0', 'L', "Y");

    const State::Transition* tr0 = s.FindTransition('0');
    const State::Transition* tr1 = s.FindTransition('1');

    ASSERT_NE(tr0, nullptr);
    ASSERT_NE(tr1, nullptr);

    EXPECT_EQ(tr0->write, '1');
    EXPECT_EQ(tr0->next, "X");

    EXPECT_EQ(tr1->write, '0');
    EXPECT_EQ(tr1->next, "Y");
}

TEST(StateTest, MultipleSameSymbolTransitions){
    State s("S");
    s.AddTransition('x', 'y', 'R', "Z");
    s.AddTransition('x', 'z', 'L', "W");

    const State::Transition* tr = s.FindTransition('x');
    ASSERT_NE(tr, nullptr);
    EXPECT_EQ(tr->write, 'y');
    EXPECT_EQ(tr->next, "Z");
}

TEST(MLogicTest, NoRulesMachineStops){
    std::string fname = "test_nomove.txt";
    WriteTempFile(fname, "001\n");

    MLogic machine;
    EXPECT_NO_THROW(machine.LoadFromFile(fname));
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, SingleStepThenStop){
    std::string fname = "test_single_step.txt";
    std::string content = "0\nS0 0 1 R S1\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "S1");
    EXPECT_EQ(machine.GetTapeString(), "1");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, MoveLeftStep){
    std::string fname = "test_move_left.txt";
    std::string content = "0\nQ 0 1 L H\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "H");
    EXPECT_EQ(machine.GetTapeString(), "1");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, MultipleSteps){
    std::string fname = "test_multi_steps.txt";
    std::string content = "01\nA 0 1 R A\nA 1 0 R A\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "A");
    EXPECT_EQ(machine.GetTapeString(), "11");

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "A");
    EXPECT_EQ(machine.GetTapeString(), "10");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, TransitionToNewState){
    std::string fname = "test_state_change.txt";
    std::string content = "1\nS0 1 0 R S1\nS1 _ 1 R S2\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "S1");
    EXPECT_EQ(machine.GetTapeString(), "0");

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "S2");
    EXPECT_EQ(machine.GetTapeString(), "01");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, InitialBlank){
    std::string fname = "test_blank_initial.txt";
    std::string content = "_\nS _ 1 R E\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "E");
    EXPECT_EQ(machine.GetTapeString(), "1");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, InvertBits){
    std::string fname = "test_invert.txt";
    std::string content = "101\nS 1 0 R S\nS 0 1 R S\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "S");
    EXPECT_EQ(machine.GetTapeString(), "010");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, CycleStates){
    std::string fname = "test_cycle.txt";
    std::string content = "101\nA 1 1 R B\nB 0 0 R C\nC 1 1 R A\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "A");
    EXPECT_EQ(machine.GetTapeString(), "101");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, FileNotFound){
    MLogic machine;
    EXPECT_THROW(machine.LoadFromFile("nonexistent_file.txt"), std::runtime_error);
}

TEST(MLogicTest, UnknownSymbolStops){
    std::string fname = "test_unknown_symbol.txt";
    std::string content = "#\nS 0 1 R S\nS 1 0 R S\n"; 

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_FALSE(machine.Step());

    EXPECT_EQ(machine.GetTapeString(), "#");
    EXPECT_EQ(machine.GetCurrentState(), "S");

    std::remove(fname.c_str());
}


TEST(MLogicTest, BinaryToBlank){
    std::string fname = "test_binary.txt";
    std::string content = "0\nS 0 0 R S\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "0");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, MultiStateSequences){
    std::string fname = "test_multi_state.txt";
    std::string content = "01\nA 0 0 R B\nB 1 1 R C\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "01");
    EXPECT_EQ(machine.GetCurrentState(), "C");

    std::remove(fname.c_str());
}

TEST(MLogicTest, NumericCharacters){
    std::string fname = "test_numeric.txt";
    std::string content = "12\nN 1 9 R N\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "92");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, LetterTransition){
    std::string fname = "test_letter.txt";
    std::string content = "AB\nL A B R L\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "BB");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, LongMoves){
    std::string fname = "test_long.txt";
    std::string content = "ABC\nX A A R X\nX B B R X\nX C C R X\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "ABC");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, MultipleNumericWrite){
    std::string fname = "test_multi_num.txt";
    std::string content = "210\nA 2 3 R B\nB 1 4 R C\n";

    WriteTempFile(fname, content);
    MLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "340");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}



int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
