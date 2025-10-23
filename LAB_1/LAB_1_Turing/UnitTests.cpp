#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

#include "Tape/Tape.h"
#include "State/State.h"
#include "TuringMachineLogic/TuringMachineLogic.h"

static void WriteTempFile(const std::string& fileName, const std::string& content) {
    std::ofstream out(fileName);
    out << content;
    out.close();
}

TEST(TapeTest, InitializationAndCurrentSymbol) {
    Tape tape("ABC");
    EXPECT_EQ(tape.GetCurrentSymbol(), 'A');
    EXPECT_EQ(tape.ToString(), "ABC");
}

TEST(TapeTest, WriteAndGetCurrent) {
    Tape tape("XYZ");
    tape.WriteSymbol('K');
    EXPECT_EQ(tape.GetCurrentSymbol(), 'K');
    EXPECT_EQ(tape.ToString(), "KYZ");
}

TEST(TapeTest, MoveRightWithinBounds) {
    Tape tape("AB");
    tape.MoveRight();
    EXPECT_EQ(tape.GetCurrentSymbol(), 'B');
    tape.WriteSymbol('C');
    EXPECT_EQ(tape.ToString(), "AC");
}

TEST(TapeTest, MoveRightBeyondEnd) {
    Tape tape("Z");
    tape.MoveRight();
    EXPECT_EQ(tape.GetCurrentSymbol(), '_');
    EXPECT_EQ(tape.ToString(), "Z");
}

TEST(TapeTest, MoveLeftWithinBounds) {
    Tape tape("12");
    tape.MoveRight();
    tape.MoveLeft();
    EXPECT_EQ(tape.GetCurrentSymbol(), '1');
    EXPECT_EQ(tape.ToString(), "12");
}

TEST(TapeTest, MoveLeftBeyondStart) {
    Tape tape("G");
    tape.MoveLeft();
    EXPECT_EQ(tape.GetCurrentSymbol(), '_');
    EXPECT_EQ(tape.ToString(), "G");
    tape.WriteSymbol('H');
    EXPECT_EQ(tape.ToString(), "HG");
}

TEST(TapeTest, ToStringTrimsBlanks) {
    Tape tape("X");
    tape.MoveRight();
    tape.MoveLeft();
    EXPECT_EQ(tape.ToString(), "X");
}

TEST(TapeTest, EmptyInitialization) {
    Tape tape("");
    EXPECT_EQ(tape.GetCurrentSymbol(), '_');
    EXPECT_EQ(tape.ToString(), "_");
    tape.WriteSymbol('M');
    EXPECT_EQ(tape.ToString(), "M");
}

TEST(TapeTest, MultipleOperations) {
    Tape tape("X");
    tape.MoveRight();
    tape.WriteSymbol('Y');
    tape.MoveLeft();
    tape.WriteSymbol('Z');
    EXPECT_EQ(tape.ToString(), "ZY");
}

TEST(TapeTest, MiddleBlankCharacter) {
    Tape tape("A_B");
    EXPECT_EQ(tape.ToString(), "A_B");
    tape.MoveRight();
    tape.WriteSymbol('X');
    EXPECT_EQ(tape.ToString(), "AXB");
}

TEST(StateTest, NameAndTransitions) {
    State s("S");
    EXPECT_EQ(s.GetName(), "S");
    EXPECT_FALSE(s.HasTransition('a'));

    s.AddTransition('a', 'b', 'L', "T");
    EXPECT_TRUE(s.HasTransition('a'));
    EXPECT_EQ(s.GetWrite('a'), 'b');
    EXPECT_EQ(s.GetMove('a'), 'L');
    EXPECT_EQ(s.GetNext('a'), "T");
    EXPECT_FALSE(s.HasTransition('c'));
}

TEST(StateTest, MultipleTransitions) {
    State s("X");
    s.AddTransition('0', '1', 'R', "X");
    s.AddTransition('1', '0', 'L', "Y");

    EXPECT_TRUE(s.HasTransition('0'));
    EXPECT_TRUE(s.HasTransition('1'));
    EXPECT_EQ(s.GetWrite('0'), '1');
    EXPECT_EQ(s.GetNext('0'), "X");
    EXPECT_EQ(s.GetWrite('1'), '0');
    EXPECT_EQ(s.GetNext('1'), "Y");
}

TEST(StateTest, ReplaceTransition) {
    State s("S");
    s.AddTransition('x', 'y', 'R', "Z");
    EXPECT_EQ(s.GetWrite('x'), 'y');
    EXPECT_EQ(s.GetMove('x'), 'R');
    EXPECT_EQ(s.GetNext('x'), "Z");

    s.AddTransition('x', 'z', 'L', "W");
    EXPECT_EQ(s.GetWrite('x'), 'z');
    EXPECT_EQ(s.GetMove('x'), 'L');
    EXPECT_EQ(s.GetNext('x'), "W");
}

TEST(MLogicTest, NoRulesMachineStops) {
    std::string fname = "test_nomove.txt";
    WriteTempFile(fname, "001\n");

    TuringMachineLogic machine;
    EXPECT_NO_THROW(machine.LoadFromFile(fname));
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, SingleStepThenStop) {
    std::string fname = "test_single_step.txt";
    std::string content = "0\nS0 0 1 R S1\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "S1");
    EXPECT_EQ(machine.GetTapeString(), "1");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, MoveLeftStep) {
    std::string fname = "test_move_left.txt";
    std::string content = "0\nQ 0 1 L H\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "H");
    EXPECT_EQ(machine.GetTapeString(), "1");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, MultipleSteps) {
    std::string fname = "test_multi_steps.txt";
    std::string content = "01\nA 0 1 R A\nA 1 0 R A\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
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

TEST(MLogicTest, TransitionToNewState) {
    std::string fname = "test_state_change.txt";
    std::string content = "1\nS0 1 0 R S1\nS1 _ 1 R S2\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
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

TEST(MLogicTest, InitialBlank) {
    std::string fname = "test_blank_initial.txt";
    std::string content = "_\nS _ 1 R E\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "E");
    EXPECT_EQ(machine.GetTapeString(), "1");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, InvertBits) {
    std::string fname = "test_invert.txt";
    std::string content = "101\nS 1 0 R S\nS 0 1 R S\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "S");
    EXPECT_EQ(machine.GetTapeString(), "010");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, FileNotFound) {
    TuringMachineLogic machine;
    EXPECT_THROW(machine.LoadFromFile("nonexistent_file_for_tests.txt"), std::runtime_error);
}

TEST(MLogicTest, UnknownSymbolStops) {
    std::string fname = "test_unknown_symbol.txt";
    std::string content = "#\nS 0 1 R S\nS 1 0 R S\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);
    EXPECT_FALSE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "#"); 
    EXPECT_EQ(machine.GetCurrentState(), "S");

    std::remove(fname.c_str());
}

TEST(MLogicTest, IgnoreInvalidRuleLines) {
    std::string fname = "test_ignore_invalid.txt";
    std::string content = "101\ninvalid_line\nS 1 0 R S\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    EXPECT_NO_THROW(machine.LoadFromFile(fname));
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "001");

    std::remove(fname.c_str());
}

TEST(MLogicTest, LastRuleOverrides) {
    std::string fname = "test_last_rule_overrides.txt";
    std::string content = "a\nS a x R S\nS a y R HALT\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "HALT");
    EXPECT_EQ(machine.GetTapeString(), "y");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, ParseExtraSpaces) {
    std::string fname = "test_extra_spaces.txt";
    std::string content = "1\n   S    1   0    R    S   \n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "0");

    std::remove(fname.c_str());
}

TEST(MLogicTest, StartStateIsFirstValidRule) {
    std::string fname = "test_start_state_first_rule.txt";
    std::string content = "1\nA 1 1 R B\nB 1 1 R C\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);
    EXPECT_EQ(machine.GetCurrentState(), "A");

    std::remove(fname.c_str());
}

TEST(MLogicTest, MultipleDifferentSymbolTransitions) {
    std::string fname = "test_multi_symbol.txt";
    std::string content = "01\nS 0 9 R S\nS 1 8 R S\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "98");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, NextStateCreatedEvenIfNoRules) {
    std::string fname = "test_next_state_exists.txt";
    std::string content = "1\nS 1 0 R T\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetCurrentState(), "T");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, CycleThenHaltOnBlank) {
    std::string fname = "test_cycle_then_halt.txt";
    std::string content = "1\nA 1 1 R B\nB _ _ R HALT\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());   // A -> B (moves right onto blank)
    EXPECT_TRUE(machine.Step());   // B on blank -> HALT
    EXPECT_EQ(machine.GetCurrentState(), "HALT");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}

TEST(MLogicTest, ComplexNumericSequence) {
    std::string fname = "test_complex_numeric.txt";
    std::string content = "210\nA 2 3 R B\nB 1 4 R C\nC 0 0 R HALT\n";
    WriteTempFile(fname, content);

    TuringMachineLogic machine;
    machine.LoadFromFile(fname);

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
    EXPECT_EQ(machine.GetTapeString(), "340");
    EXPECT_EQ(machine.GetCurrentState(), "HALT");
    EXPECT_FALSE(machine.Step());

    std::remove(fname.c_str());
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
