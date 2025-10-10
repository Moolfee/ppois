#include "Tape.h"

Tape::Tape(const std::string& initial) : headIndex(0){
    for (char c : initial) 
        cells.push_back(c); 
    if (cells.empty()) 
        cells.push_back(BLANK); 
}

char Tape::GetCurrentSymbol() const{
    return cells[headIndex]; 
}

void Tape::WriteSymbol(char symbol){
    cells[headIndex] = symbol; 
}

void Tape::MoveLeft(){
    if (headIndex == 0){           
        cells.push_front(BLANK);       
    }
    else{
        --headIndex;            
    }
}

void Tape::MoveRight(){
    if (headIndex == static_cast<int>(cells.size()) - 1){ 
        cells.push_back(BLANK);
        ++headIndex;                
    }
    else{
        ++headIndex;                
    }
}

std::string Tape::ToString() const{    
    int left = 0;
    int right = static_cast<int>(cells.size()) - 1;
    while (left <= right && cells[left] == BLANK) 
        ++left;
    while (right >= left && cells[right] == BLANK) 
        --right;
    if (left > right) 
        return std::string(1, BLANK);
    std::string out; out.reserve(right - left + 1);
    for (int i = left; i <= right; ++i) 
        out.push_back(cells[i]);
    return out;
}
