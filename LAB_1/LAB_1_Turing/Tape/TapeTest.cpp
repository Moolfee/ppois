#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

#include "Tape.h"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
