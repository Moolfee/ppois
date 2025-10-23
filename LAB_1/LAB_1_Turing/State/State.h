#pragma once
#include <string>
#include <map>

class State{
private:
    std::map<char, char> writeMap;
    std::map<char, char> moveMap;
    std::map<char, std::string> nextMap;
    std::string name;

public:
    State(const std::string& n = "");
    void AddTransition(char read, char write, char move, const std::string& next);
    bool HasTransition(char read) const;
    char GetWrite(char read) const;
    char GetMove(char read) const;
    std::string GetNext(char read) const;
    std::string GetName() const;
};
