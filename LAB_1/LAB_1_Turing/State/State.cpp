#include "State.h"

State::State(const std::string& n) : name(n) {}

void State::AddTransition(char read, char write, char move, const std::string& next) {
    writeMap[read] = write;
    moveMap[read] = move;
    nextMap[read] = next;
}

bool State::HasTransition(char read) const {
    return writeMap.find(read) != writeMap.end();
}

char State::GetWrite(char read) const {
    return writeMap.at(read);
}

char State::GetMove(char read) const {
    return moveMap.at(read);
}

std::string State::GetNext(char read) const {
    return nextMap.at(read);
}

std::string State::GetName() const {
    return name;
}
