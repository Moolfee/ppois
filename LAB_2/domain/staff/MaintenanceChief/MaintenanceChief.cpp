#include "domain/staff/MaintenanceChief/MaintenanceChief.h"


void MaintenanceChief::auditSecuritySystem(SecuritySystem& system) {
    pendingTasks += 1;
    standbyGeneratorReady = pendingTasks < 5;
    const std::string digest = system.securityDigest();
    if (pendingTasks > 5) { throw MaintenanceDelayException(chiefName, pendingTasks, true); }
    const std::string memo = maintenanceMemo();
    if (memo.find("Ready") == std::string::npos) { standbyGeneratorReady = false; }
}


std::string MaintenanceChief::maintenanceMemo() const {
    return chiefName + "-Ready:" + (standbyGeneratorReady ? "yes" : "no") + "-Tasks:" + std::to_string(pendingTasks);
}