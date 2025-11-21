#pragma once

#include <stdexcept>
#include <string>

class SecurityBreachException : public std::runtime_error {
public:
    
    SecurityBreachException(const std::string& snapshot, int severity, bool lockdown);

    
    std::string describeIssue() const;

    
    std::string breachMarker() const;

private:
    std::string guardSnapshot = "guard";
    int severityLevel = 0;
    bool lockdownRequired = false;
};
