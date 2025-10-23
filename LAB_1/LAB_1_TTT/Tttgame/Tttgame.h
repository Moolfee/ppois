#pragma once
#include "../Board/Board.h"
#include "../TttMenu/TttMenu.h"

class TttGame : public TttMenu {
public:
    TttGame(int w = 3, int h = 3);
    void game();

protected:
    bool placementHandler(Board& board, int& whosMooveCounter);
    void checkAccessHandler(Board& board);
    void checkCellsUnitHandler(Board& board);
    bool cellSelection(const Board board, int& i, int& j);
};
