#include "Tttgame.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

Tttgame::Tttgame(int width, int height) {
    this->width = (width >= 3 ? width : 3);
    this->height = (height >= 3 ? height : 3);
}

void Tttgame::game() { 
    mainmenu();
    Board board(width, height, '*');

    char choosedMenuOption = ' ';
    int whosMooveCounter = 0;

    while (choosedMenuOption != 0x1B) {
        system("cls");
        std::cout << board << "\n���: " << ((whosMooveCounter % 2 == 0) ? 'X' : 'O') << "\n"
            << "1 - ������� ���\n2 - ��������� ����������� ����\n3 - ���������� ���������� ������\n\nEsc - �����\n";

        choosedMenuOption = _getch();
        system("cls");
        switch (choosedMenuOption) { 
        case '1': {
            if (placementHandler(board, whosMooveCounter))
                return;
            break;
        }
        case '2': {
            checkAccessHandler(board);
            break;
        }
        case '3': {
            checkCellsUnitHandler(board);
            break;
        }
        case 0x1B: break;
        default:
            std::cout << "���������� ���...\n";
            Sleep(750);
        }
    }
}

bool Tttgame::placementHandler(Board& board, int& whosMooveCounter) {
    int i, j;
    std::cout << "������ ����� :" << ((whosMooveCounter % 2 == 0) ? 'X' : 'O') << " (i j): ";
    cellSelection(board, i, j);
    char resultboof = board.place(whosMooveCounter, i, j);
    if (resultboof == 'X' || resultboof == 'O' || resultboof == 'D') {
        system("cls");
        std::cout << board;
        if (resultboof == 'D')
            std::cout << "\n�����!\n";
        else
            std::cout << "\n�������: " << resultboof << "\n";
        Sleep(750);
        return 1;
    }
    return 0;
}

void Tttgame::checkAccessHandler(Board& board) {
    int i, j;

    std::cout << "������� ���������� ������ ������: ";
    std::cin >> i >> j;
    board.checkCellAccess(i, j) ? std::cout << "������ ��������\n" : std::cout << "������ ������ ��� ��� ����\n";
    Sleep(750);
}

void Tttgame::checkCellsUnitHandler(Board& board) {
    int i, j;
    std::cout << "������� ���������� ������ ������: ";
    while (std::cin >> i >> j) {
        if (!board.inBounds(i, j)) {
            std::cout << "������ ��� ����, ���������� ��� ���:\n";
            continue;
        }
        break;
    }
    char cellvalue = board[i][j];

    if (cellvalue == 'X' || cellvalue == 'O')
        std::cout << "� ������ ���������: " << cellvalue << "\n";
    else std::cout << "������ �����\n";
    Sleep(750);
}

bool Tttgame::cellSelection(const Board board, int& i, int& j) {
    int icheckboof, jcheckboof;
    std::cout << "������� ���������� ������ ������: ";
    while (std::cin >> icheckboof >> jcheckboof) {
        if (board.checkCellAccess(icheckboof, jcheckboof)) {
            i = icheckboof;
            j = jcheckboof;
            return 1;
        }
        std::cout << "������ ����������, ���������� ��� ���:\n";
        Sleep(750);
    }
    return 0;
}