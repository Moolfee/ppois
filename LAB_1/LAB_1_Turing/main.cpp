#include <iostream>
#include "TuringMachineLogic/TuringMachineLogic.h"
#include <windows.h>

int main(int argc, char* argv[]){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (argc < 2){
        std::cerr << "Использование: " << argv[0] << " путь_к_файлу [-log]\n"; 
        return 1;
    }

    std::string filePath;
    bool logMode = false;
    for (int i = 1; i < argc; ++i){
        std::string a = argv[i];

        if (a == "-log"){ 
            logMode = true; 
            continue; 
        } 

        if (filePath.empty()) filePath = a;            
    }

    if (filePath.empty()){
        std::cerr << "Ошибка: не указан путь к файлу\n";
        return 1;
    }

    TuringMachineLogic machine;

    try{
        machine.LoadFromFile(filePath);      
    }
    catch (const std::exception& ex){
        std::cerr << "Ошибка загрузки: " << ex.what() << "\n";
        return 1;
    }

    while (machine.Step()){
        if (logMode){
            std::cout << "Состояние: " << machine.GetCurrentState()
            << ", Лента: " << machine.GetTapeString() << '\n';
        }
    }

    if (!logMode) {
        std::cout << "Итоговое Состояние: " << machine.GetCurrentState() << std::endl;
        std::cout << "Итоговая лента:  " << machine.GetTapeString() << std::endl;
    }

    return 0;
}
