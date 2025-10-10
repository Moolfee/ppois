#pragma once
#include <string>
#include <deque>

class Tape{
private:
    std::deque<char> cells;               
    int headIndex;                        
    static constexpr char BLANK = '_';    

public:
    Tape() = delete;                      
    explicit Tape(const std::string& initial);
    char GetCurrentSymbol() const;        
    void WriteSymbol(char symbol);        
    void MoveLeft();                      
    void MoveRight();                     
    std::string ToString() const;         
    ~Tape() = default;
};
