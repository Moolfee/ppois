#include <gtest/gtest.h>
#include "domain/staff/MaintenanceChief/MaintenanceChief.h"

TEST(MaintenanceChief, AuditsSecuritySystem) {
    MaintenanceChief chief;
    SecuritySystem system;
    Guard securityGuard;
    IncidentLogger incidentLogger;
    securityGuard.resolveIncident(incidentLogger);
    system.synchronizeGuard(securityGuard);
    chief.auditSecuritySystem(system);
    EXPECT_NE(chief.maintenanceMemo().find("Tasks"), std::string::npos);
}

TEST(MaintenanceChief, ThrowsWhenBacklogTooHigh) {
    MaintenanceChief chief;
    SecuritySystem system;
    Guard securityGuard;
    IncidentLogger incidentLogger;
    securityGuard.resolveIncident(incidentLogger);
    system.synchronizeGuard(securityGuard);
    bool exceptionRaised = false;
    try {
        for (int audit = 0; audit < 7; ++audit) {
            chief.auditSecuritySystem(system);
        }
    } catch (const MaintenanceDelayException&) {
        exceptionRaised = true;
    }
    EXPECT_TRUE(exceptionRaised);
}