#pragma once

#include <string>
#include <vector>

class IncidentLogger {
public:
    
    void captureIncident(const std::string& details);

    
    std::string summarizeIncidents() const;

private:
    std::vector<std::string> events = {};
    int unresolvedCount = 0;
    bool notifyLeadership = false;
};
