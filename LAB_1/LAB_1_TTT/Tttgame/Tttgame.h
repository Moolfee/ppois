#pragma once
#include "../Board/Board.h"
#include "../Tttmenu/Tttmenu.h"

class Tttgame : public Tttmenu {
public:
    Tttgame(int w = 3, int h = 3);
    void game();

protected:
    bool placementHandler(Board& board, int& whosMooveCounter);
    void checkAccessHandler(Board& board);
    void checkCellsUnitHandler(Board& board);
    bool cellSelection(const Board board, int& i, int& j);
};
