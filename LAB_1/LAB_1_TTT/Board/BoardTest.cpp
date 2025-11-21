#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "Board.h"
#include "../TttGame/TttGame.h"

TEST(BoardTest, ConstructorValidSize) {
    EXPECT_NO_THROW(Board(3, 3));
    EXPECT_NO_THROW(Board(5, 5));
    EXPECT_NO_THROW(Board(1, 1));
}

TEST(BoardTest, ConstructorInvalidSize) {
    EXPECT_THROW(Board(0, 3), std::invalid_argument);
    EXPECT_THROW(Board(3, 0), std::invalid_argument);
    EXPECT_THROW(Board(-1, -1), std::invalid_argument);
}

TEST(BoardTest, InBoundsValid) {
    Board b(3, 3);
    EXPECT_TRUE(b.inBounds(0, 0));
    EXPECT_TRUE(b.inBounds(2, 2));
    EXPECT_TRUE(b.inBounds(1, 1));
}

TEST(BoardTest, InBoundsInvalid) {
    Board b(3, 3);
    EXPECT_FALSE(b.inBounds(-1, 0));
    EXPECT_FALSE(b.inBounds(3, 3));
    EXPECT_FALSE(b.inBounds(0, 3));
    EXPECT_FALSE(b.inBounds(10, 10));
}

TEST(BoardTest, CheckCellAccessEmptyCell) {
    Board b(3, 3);
    EXPECT_TRUE(b.checkCellAccess(0, 0));
    EXPECT_TRUE(b.checkCellAccess(1, 1));
    EXPECT_TRUE(b.checkCellAccess(2, 2));
}

TEST(BoardTest, CheckCellAccessOccupiedCell) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0);
    EXPECT_FALSE(b.checkCellAccess(0, 0));
}

TEST(BoardTest, CheckCellAccessOutOfBounds) {
    Board b(3, 3);
    EXPECT_FALSE(b.checkCellAccess(-1, 0));
    EXPECT_FALSE(b.checkCellAccess(3, 3));
    EXPECT_FALSE(b.checkCellAccess(10, 10));
}

TEST(BoardTest, PlaceFirstMoveX) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0);

    EXPECT_EQ(b[0][0], 'X');
    EXPECT_EQ(counter, 1);
}

TEST(BoardTest, PlaceSecondMoveO) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0); 
    b.place(counter, 1, 1); 
    EXPECT_EQ(b[1][1], 'O');
    EXPECT_EQ(counter, 2);
}

TEST(BoardTest, PlaceInvalidMoveThrows) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0);
    EXPECT_THROW(b.place(counter, 0, 0), std::logic_error);
}

TEST(BoardTest, CheckWinConditionHorizontalWin) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0); 
    b.place(counter, 1, 0); 
    b.place(counter, 0, 1); 
    b.place(counter, 1, 1); 
    char result = b.place(counter, 0, 2);
    EXPECT_EQ(result, 'X');
}

TEST(BoardTest, CheckWinConditionVerticalWin) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0); 
    b.place(counter, 0, 1); 
    b.place(counter, 1, 0); 
    b.place(counter, 1, 1); 
    char result = b.place(counter, 2, 0); 
    EXPECT_EQ(result, 'X');
}

TEST(BoardTest, CheckWinConditionDiagonalWin) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0); 
    b.place(counter, 0, 1); 
    b.place(counter, 1, 1); 
    b.place(counter, 0, 2); 
    char result = b.place(counter, 2, 2); 
    EXPECT_EQ(result, 'X');
}

TEST(BoardTest, CheckWinConditionAntiDiagonalWin) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 2); 
    b.place(counter, 0, 1); 
    b.place(counter, 1, 1); 
    b.place(counter, 0, 0); 
    char result = b.place(counter, 2, 0); 
    EXPECT_EQ(result, 'X');
}

TEST(BoardTest, SingleCellBoardDraw) {
    Board b(1, 1);
    int counter = 0;
    char result = b.place(counter, 0, 0); 
    EXPECT_EQ(result, '*');
    EXPECT_EQ(b.checkWinCondition(), 'D');
}

TEST(BoardTest, CheckWinConditionGameContinues) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0);
    char result = b.checkWinCondition();
    EXPECT_EQ(result, '*');
}

TEST(BoardTest, CheckWinConditionEarlyGame) {
    Board b(3, 3);
    int counter = 0;
    b.place(counter, 0, 0);
    b.place(counter, 1, 1);
    char result = b.checkWinCondition();
    EXPECT_EQ(result, '*');
}

TEST(BoardTest, OperatorAccessWriteAndRead) {
    Board b(3, 3);
    b[0][0] = 'X';
    b[1][1] = 'O';
    EXPECT_EQ(b[0][0], 'X');
    EXPECT_EQ(b[1][1], 'O');
    EXPECT_EQ(b[2][2], '*');
}

TEST(BoardTest, OperatorAccessConst) {
    const Board b(3, 3);
        EXPECT_EQ(b[0][0], '*');
}

TEST(BoardTest, OutputStreamOperatorSmallBoard) {
    Board b(2, 2);
    std::stringstream ss;
    ss << b;
    std::string expected = "* *\n* *\n";
    EXPECT_EQ(ss.str(), expected);
}

TEST(BoardTest, OutputStreamOperatorAfterMoves) {
    Board b(2, 2);
    int counter = 0;
    b.place(counter, 0, 0); 
    b.place(counter, 1, 1); 

    std::stringstream ss;
    ss << b;
    std::string result = ss.str();
    EXPECT_TRUE(result.find('X') != std::string::npos);
    EXPECT_TRUE(result.find('O') != std::string::npos);
}


TEST(BoardTest, LargeBoardWinCondition) {
    Board b(10, 10);
    int counter = 0;
    b.place(counter, 5, 5); 
    b.place(counter, 6, 6); 
    b.place(counter, 5, 6); 
    b.place(counter, 6, 7); 
    char result = b.place(counter, 5, 7); 
    EXPECT_EQ(result, 'X');
}

TEST(BoardTest, RectangularBoard) {
    Board b(4, 3);
    EXPECT_TRUE(b.inBounds(0, 0));
    EXPECT_TRUE(b.inBounds(2, 3));
    EXPECT_FALSE(b.inBounds(3, 0));
    EXPECT_FALSE(b.inBounds(0, 4));
}


TEST(BoardTest, SingleCellBoard) {
    Board b(1, 1);
    int counter = 0; 
    char result = b.place(counter, 0, 0);  
    EXPECT_EQ(result, '*'); 
    EXPECT_EQ(b.checkWinCondition(), 'D');
    EXPECT_FALSE(b.checkCellAccess(0, 0));
}

TEST(BoardTest, CustomFillCharacter) {
    Board b(2, 2, '-');
    EXPECT_EQ(b[0][0], '-');
    EXPECT_EQ(b[1][1], '-');
}

TEST(BoardTest, MultipleMovesOrder) {
    Board b(3, 3);
    int counter = 0;

    b.place(counter, 0, 0); 
    EXPECT_EQ(b[0][0], 'X');

    b.place(counter, 0, 1); 
    EXPECT_EQ(b[0][1], 'O');

    b.place(counter, 0, 2); 
    EXPECT_EQ(b[0][2], 'X');

    EXPECT_EQ(counter, 3);
}

TEST(BoardTest, WinConditionWithDifferentK) {
    Board b(5, 5);
    int counter = 0;

    b.place(counter, 1, 1); 
    b.place(counter, 2, 2); 
    b.place(counter, 1, 2); 
    b.place(counter, 2, 3); 
    b.place(counter, 1, 3); 
    b.place(counter, 2, 4); 

    char result = b.place(counter, 1, 4); 
    EXPECT_EQ(result, 'X');
}

TEST(BoardTest, NoWinWithSmallK) {
    Board b(3, 3);
    int counter = 0;

    b.place(counter, 0, 0); 
    b.place(counter, 1, 1); 

    
    char result = b.checkWinCondition(2);
    EXPECT_EQ(result, '*'); 
}

TEST(BoardTest, CheckAllCellsOccupied) {
    Board b(2, 2);
    int counter = 0;

    b.place(counter, 0, 0); 
    b.place(counter, 0, 1); 
    b.place(counter, 1, 0); 

    char placeResult = b.place(counter, 1, 1); 
    EXPECT_EQ(placeResult, '*'); 

    EXPECT_EQ(b.checkWinCondition(), 'D');
}

TEST(BoardTest, EarlyGameReturnsStar) {
    Board b(3, 3);
    int counter = 0;    
    char result1 = b.place(counter, 0, 0);
    EXPECT_EQ(result1, '*');

    char result2 = b.place(counter, 1, 1); 
    EXPECT_EQ(result2, '*');

    char result3 = b.place(counter, 0, 1); 
    EXPECT_EQ(result3, '*');

    char result4 = b.place(counter, 1, 0); 
    EXPECT_EQ(result4, '*');
}

TEST(BoardTest, FiveMovesStartsCheckingWin) {
    Board b(3, 3);
    int counter = 0; 
    b.place(counter, 0, 0); 
    b.place(counter, 1, 1); 
    b.place(counter, 0, 1); 
    b.place(counter, 1, 0); 
 
    char result = b.place(counter, 0, 2); 
    EXPECT_EQ(result, 'X');
}

TEST(BoardTest, CheckWinWithCustomK) {
    Board b(5, 5);
    int counter = 0;

    b.place(counter, 0, 0); 
    b.place(counter, 1, 1); 
    b.place(counter, 0, 1); 
    b.place(counter, 2, 2); 
    b.place(counter, 0, 2); 
    b.place(counter, 3, 3); 

    char result = b.checkWinCondition(4); 
    EXPECT_EQ(result, '*'); 
}

TEST(BoardTest, CheckWinWithKLessThanThree) {
    Board b(3, 3);
    char result = b.checkWinCondition(2);
    EXPECT_EQ(result, '*'); 
}

TEST(BoardTest, SmallBoardDraw) {
    Board b(2, 2);
    int counter = 0;

    b.place(counter, 0, 0); 
    b.place(counter, 0, 1); 
    b.place(counter, 1, 0); 
    
    char placeResult = b.place(counter, 1, 1); 
    EXPECT_EQ(placeResult, '*');

    EXPECT_EQ(b.checkWinCondition(), 'D');
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}