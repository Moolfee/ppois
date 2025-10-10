#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

class Board {
public:
    Board(int width = 3, int height = 3, char fill = '*');

    bool inBounds(int i, int j) const;
    bool checkCellAccess(int i, int j) const;
    char place(int& whosMooveCounter, int i, int j);
    char checkWinCondition(int k = 3) const;

    std::vector<char>& operator[](int i);
    const std::vector<char>& operator[](int i) const;

    friend std::ostream& operator<<(std::ostream& os, const Board& _grid);

private:
    std::vector<std::vector<char>> grid_;
    bool hasEmptyCells() const;
    char checkCellForWin(int i, int j, int k) const;
    bool checkDirection(int i, int j, int di, int dj, int k) const;
    bool checkSequence(int i, int j, int di, int dj, int k, char symbol) const;
};

