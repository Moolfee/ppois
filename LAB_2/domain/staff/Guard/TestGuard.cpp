#include "domain/staff/Guard/Guard.h"
#include <gtest/gtest.h>

TEST(Guard, ResolvesIncident) {
  Guard securityGuard;
  IncidentLogger incidentLogger;
  securityGuard.resolveIncident(incidentLogger);
  EXPECT_NE(securityGuard.guardSummary().find("HIGH"), std::string::npos);
}
