#pragma once

#include <string>
#include "domain/staff/StaffMember/StaffMember.h"
#include "domain/security/PatrolRoutePlanner/PatrolRoutePlanner.h"
#include "domain/security/IncidentLogger/IncidentLogger.h"

class Guard : public StaffMember {
public:
    
    void resolveIncident(IncidentLogger& logger);

    
    std::string guardSummary() const;

private:
    PatrolRoutePlanner assignedPlanner = {};
    bool armored = false;
    int alertnessScore = 60;
};
