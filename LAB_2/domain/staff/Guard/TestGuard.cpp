#include <gtest/gtest.h>
#include "domain/staff/Guard/Guard.h"

TEST(Guard, ResolvesIncident) {
    Guard securityGuard;
    IncidentLogger incidentLogger;
    securityGuard.resolveIncident(incidentLogger);
    EXPECT_NE(securityGuard.guardSummary().find("HIGH"), std::string::npos);
}