#pragma once
#include <string>
#include <map>
#include "../State/State.h"
#include "../Tape/Tape.h"

class TuringMachineLogic {
private:
    Tape tape;                       
    std::map<std::string, State> states; 
    std::string currentState;        

    
    void EnsureStateExists(const std::string& name);               
    bool ParseRuleLine(const std::string& line);                  
    void ParseInitialTape(const std::string& line);               

public:
    TuringMachineLogic();
    void LoadFromFile(const std::string& filename); 
    bool Step();                     
    std::string GetCurrentState() const; 
    std::string GetTapeString() const;
    ~TuringMachineLogic() = default;
};
