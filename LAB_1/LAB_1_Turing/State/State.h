#pragma once
#include <string>
#include <vector>

class State{
public:
    struct Transition{
        char read;            
        char write;           
        char move;            
        std::string next;   
    };

private:
    std::string name;       
    std::vector<Transition> transitions; 

public:
    explicit State(const std::string& name); 
    const std::string& GetName() const;      
    void AddTransition(char read, char write, char move, const std::string& next); 
    const Transition* FindTransition(char readSymbol) const; 
    ~State() = default;
};
