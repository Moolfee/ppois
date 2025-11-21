#pragma once

#include <string>
#include "domain/security/SecuritySystem/SecuritySystem.h"
#include "domain/exceptions/MaintenanceDelayException/MaintenanceDelayException.h"

class MaintenanceChief {
public:
    
    void auditSecuritySystem(SecuritySystem& system);

    
    std::string maintenanceMemo() const;

private:
    std::string chiefName = "Chief";
    int pendingTasks = 0;
    bool standbyGeneratorReady = true;
};
