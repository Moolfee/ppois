#include "domain/security/SecurityDrone/SecurityDrone.h"
#include <gtest/gtest.h>

TEST(SecurityDrone, HandlesHealthyAndFaultyHardware) {
  SecurityDrone securityDrone;
  securityDrone.reportSweep(true);
  EXPECT_NE(securityDrone.droneStatus().find("active"), std::string::npos);

  bool failureRaised = false;
  try {
    securityDrone.reportSweep(false);
  } catch (const EquipmentFailureException &) {
    failureRaised = true;
  }
  EXPECT_TRUE(failureRaised);
}
