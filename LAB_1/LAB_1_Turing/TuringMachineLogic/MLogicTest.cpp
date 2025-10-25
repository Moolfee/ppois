#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

#include "TuringMachineLogic.h"

static void WriteTempFile(const std::string& fileName, const std::string& content) {
    std::ofstream out(fileName);
    out << content;
    out.close();
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

    EXPECT_TRUE(machine.Step());
    EXPECT_TRUE(machine.Step());
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