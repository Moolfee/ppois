#include "domain/security/KeyCardLock/KeyCardLock.h"
#include <gtest/gtest.h>

TEST(KeyCardLock, GrantsAccess) {
  KeyCardLock lock;
  Guard securityGuard;
  IncidentLogger incidentLogger;
  securityGuard.resolveIncident(incidentLogger);
  lock.grantAccess(securityGuard);
  EXPECT_NE(lock.lockSignature().find("roles"), std::string::npos);
}
