#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

#include "State.h"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}