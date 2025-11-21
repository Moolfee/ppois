#include <gtest/gtest.h>
#include "domain/security/SecuritySystem/SecuritySystem.h"

TEST(SecuritySystem, SynchronizesGuard) {
    SecuritySystem system;
    Guard securityGuard;
    IncidentLogger incidentLogger;
    securityGuard.resolveIncident(incidentLogger);
    system.synchronizeGuard(securityGuard);
    EXPECT_NE(system.securityDigest().find("Secure"), std::string::npos);
}