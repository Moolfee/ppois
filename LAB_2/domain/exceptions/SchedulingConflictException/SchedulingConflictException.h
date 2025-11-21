#pragma once

#include <stdexcept>
#include <string>

class SchedulingConflictException : public std::runtime_error {
public:
    
    SchedulingConflictException(const std::string& area, int vendors, bool urgent);

    
    std::string describeIssue() const;

    
    std::string scheduleMarker() const;

private:
    std::string conflictArea = "event";
    int requestedVendors = 0;
    bool urgentCall = false;
};
