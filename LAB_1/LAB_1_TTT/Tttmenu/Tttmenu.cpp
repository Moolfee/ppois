#include "Tttmenu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

void Tttmenu::mainmenu() {
    char dir = ' ';
    while (dir != 0x1B) {
        system("cls");
        std::cout << "1 - Начать игру\n2 - Изменить размер поля\n\nEsc - Выход";
        dir = _getch();
        system("cls");
        switch (dir) {
        case '1': return;
        case '2': sizechange(); break;
        case 0x1B: break;
        default:
            std::cout << "Попробуйте ещё...";
            Sleep(750);
        }
    }
}

void Tttmenu::sizechange() {
    std::cout << "Введите ширину (>=3): ";
    while (!(std::cin >> width) || width < 3) {
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Некорректное значение. Повторите: ";
    }

    std::cout << "Введите высоту (>=3): ";
    while (!(std::cin >> height) || height < 3) {
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Некорректное значение. Повторите: ";
    }
}
