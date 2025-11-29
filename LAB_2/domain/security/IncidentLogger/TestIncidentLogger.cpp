#include "domain/security/IncidentLogger/IncidentLogger.h"
#include <gtest/gtest.h>

TEST(IncidentLogger, CapturesIncident) {
  IncidentLogger logger;
  logger.captureIncident("Door forced");
  EXPECT_NE(logger.summarizeIncidents().find("alert"), std::string::npos);
  logger.captureIncident("Glass broken");
  logger.captureIncident("Door forced again");
  EXPECT_NE(logger.summarizeIncidents().find("alert-on"), std::string::npos);
}
