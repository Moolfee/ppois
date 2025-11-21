#pragma once

#include <string>
#include "domain/security/IncidentLogger/IncidentLogger.h"
#include "domain/exceptions/EquipmentFailureException/EquipmentFailureException.h"

class SecurityDrone {
public:
    
    void reportSweep(bool hardwareHealthy);

    
    std::string droneStatus() const;

private:
    std::string droneId = "Scout-1";
    IncidentLogger onboardLogger = {};
    bool activePatrol = false;
};
