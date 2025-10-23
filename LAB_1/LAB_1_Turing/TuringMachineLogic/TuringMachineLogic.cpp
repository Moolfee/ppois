#include "TuringMachineLogic.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

TuringMachineLogic::TuringMachineLogic() : tape(std::string("")), currentState(""){ }

void TuringMachineLogic::EnsureStateExists(const std::string& name){
    states.try_emplace(name, name);
}

void TuringMachineLogic::ParseInitialTape(const std::string& line){
    tape = Tape(line);
}

bool TuringMachineLogic::ParseRuleLine(const std::string& line){
    std::istringstream iss(line);
    std::string stateName, nextState;
    char readSym = 0, writeSym = 0, direction = 0;

    if (!(iss >> stateName >> readSym >> writeSym >> direction >> nextState)){
        return false;
    }

    EnsureStateExists(stateName);
    EnsureStateExists(nextState);
    
    auto it = states.find(stateName);
    if (it == states.end()) 
        return false; 
    it->second.AddTransition(readSym, writeSym, direction, nextState);
    return true;
}

void TuringMachineLogic::LoadFromFile(const std::string& filename){
    std::ifstream in(filename);
    if (!in) 
        throw std::runtime_error("Не удалось открыть файл: " + filename);

    std::string line;
    bool initialSet = false;
    bool firstRuleFound = false;

    while (std::getline(in, line)){       
        if (!line.empty() && (line.back() == '\r' || line.back() == '\n'))
            line.pop_back();
        bool onlySpaces = true;
        for (char c : line) 
            if (!isspace(static_cast<unsigned char>(c))){ 
                onlySpaces = false; 
                break; 
            }
        if (onlySpaces) continue;

        if (!initialSet){
            ParseInitialTape(line);        
            initialSet = true;
            continue;
        }

        if (ParseRuleLine(line)){
            if (!firstRuleFound){
                std::istringstream iss(line);
                std::string stateName;
                iss >> stateName;
                currentState = stateName;
                firstRuleFound = true;
            }
            continue;
        }        
    }
}

bool TuringMachineLogic::Step() {
    if (currentState.empty())
        return false;

    auto it = states.find(currentState);
    if (it == states.end())
        return false;

    char cur = tape.GetCurrentSymbol();

    if (!it->second.HasTransition(cur))
        return false;

    char write = it->second.GetWrite(cur);
    char move = it->second.GetMove(cur);
    std::string next = it->second.GetNext(cur);

    tape.WriteSymbol(write);

    if (move == 'L')
        tape.MoveLeft();
    else if (move == 'R')
        tape.MoveRight();

    currentState = next;
    return true;
}

std::string TuringMachineLogic::GetCurrentState() const{
    return currentState; 
} 
std::string TuringMachineLogic::GetTapeString() const{
    return tape.ToString(); 
}
