#pragma once

#include <stdexcept>
#include <string>

class EquipmentFailureException : public std::runtime_error {
public:
    
    EquipmentFailureException(const std::string& device, int code, bool ground);

    
    std::string describeIssue() const;

    
    std::string equipmentStamp() const;

private:
    std::string deviceName = "device";
    int failureCode = 0;
    bool requiresGrounding = false;
};
