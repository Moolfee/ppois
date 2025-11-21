#pragma once

#include <stdexcept>
#include <string>

class InventoryMismatchException : public std::runtime_error {
public:
    
    InventoryMismatchException(const std::string& identifier, int count, bool overnight);

    
    std::string describeIssue() const;

    
    std::string inventoryToken() const;

private:
    std::string identifierToken = "id";
    int mismatchCount = 0;
    bool requiresOvernight = false;
};
