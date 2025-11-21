#include "TttMenu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

void TttMenu::mainmenu() {
    char dir = ' ';
    while (dir != 0x1B) {
        system("cls");
        std::cout << "1 -  \n2 -   \n\nEsc - ";
        dir = _getch();
        system("cls");
        switch (dir) {
        case '1': return;
        case '2': sizechange(); break;
        case 0x1B: break;
        default:
            std::cout << " ...";
            Sleep(750);
        }
    }
}

void TttMenu::sizechange() {
    std::cout << "  (>=3): ";
    while (!(std::cin >> width) || width < 3) {
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << " . : ";
    }

    std::cout << "  (>=3): ";
    while (!(std::cin >> height) || height < 3) {
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << " . : ";
    }
}