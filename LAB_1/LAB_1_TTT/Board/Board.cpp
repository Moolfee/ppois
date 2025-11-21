#include "Board.h"
#include <algorithm>

Board::Board(int w, int h, char fill) {
    if (w < 1 || h < 1) throw std::invalid_argument("–азмер доски не может быть отрицательным или нулевым");
    grid_.assign(h, std::vector<char>(w, fill));
}

std::ostream& operator<<(std::ostream& os, const Board& b) {
    for (int i = 0; i < b.grid_.size(); ++i) {
        for (int j = 0; j < b.grid_[0].size(); ++j) {
            os << b.grid_[i][j];
            if (j + 1 < b.grid_[0].size()) os << ' ';
        }
        os << '\n';
    }
    return os;
}

std::vector<char>& Board::operator[](int i) { 
    return grid_[i]; 
}
const std::vector<char>& Board::operator[](int i) const {
    return grid_[i]; 
}

bool Board::inBounds(int i, int j) const {
    return (i >= 0 && i < grid_.size() && j >= 0 && j < grid_[0].size());
}

bool Board::checkCellAccess(int i, int j) const {
    if (!inBounds(i, j))
        return false;
    char c = grid_[i][j];
    return !(c == 'O' || c == 'X');
}

char Board::place(int& whoseMoveCounter, int i, int j) {
    if (!checkCellAccess(i, j)) throw std::logic_error("Ќевозможно сделать ход в этой клетке");

    grid_[i][j] = (whoseMoveCounter % 2 == 0) ? 'X' : 'O';
    ++whoseMoveCounter;
    if (whoseMoveCounter < 5)
        return '*';
    return checkWinCondition(3);
}

char Board::checkWinCondition(int k) const {
    if (k < 3) k = 3;

    if (!hasEmptyCells()) {
        return 'D';
    }

    for (int i = 0; i < grid_.size(); ++i) {
        for (int j = 0; j < grid_[0].size(); ++j) {
            char result = checkCellForWin(i, j, k);
            if (result != '\0') {
                return result;
            }
        }
    }

    return '*';
}

bool Board::hasEmptyCells() const {
    for (const auto& row : grid_) {
        for (char cell : row) {
            if (cell == '*') {
                return true;
            }
        }
    }
    return false;
}

char Board::checkCellForWin(int i, int j, int k) const {
    char c = grid_[i][j];
    if (c == '*' || (c != 'X' && c != 'O')) {
        return '\0';
    }

    static const int directions[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };

    for (const auto& dir : directions) {
        if (checkDirection(i, j, dir[0], dir[1], k)) {
            return c;
        }
    }

    return '\0';
}

bool Board::checkDirection(int i, int j, int di, int dj, int k) const {
    int ei = i + (k - 1) * di;
    int ej = j + (k - 1) * dj;

    if (!inBounds(ei, ej)) {
        return false;
    }

    return checkSequence(i, j, di, dj, k, grid_[i][j]);
}

bool Board::checkSequence(int i, int j, int di, int dj, int k, char symbol) const {
    for (int step = 1; step < k; ++step) {
        int ni = i + step * di;
        int nj = j + step * dj;

        if (!inBounds(ni, nj) || grid_[ni][nj] != symbol) {
            return false;
        }
    }
    return true;
}