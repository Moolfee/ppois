#include "State.h"

State::State(const std::string& name) : name(name){ }

const std::string& State::GetName() const{
    return name;
}

void State::AddTransition(char read, char write, char move, const std::string& next){
    Transition t;
    t.read = read;
    t.write = write;
    t.move = move;
    t.next = next;
    transitions.push_back(t);
}

const State::Transition* State::FindTransition(char readSymbol) const{
    for (const auto& t : transitions){
        if (t.read == readSymbol) return &t;
    }
    return nullptr;
}
