#include <gtest/gtest.h>
#include "domain/exceptions/ClimateAlertException/ClimateAlertException.h"

TEST(ClimateAlertException, DescribesClimateIssue) {
    ClimateAlertException exceptionInstance("HVAC", 60, true);
    EXPECT_NE(exceptionInstance.describeIssue().find("HVAC"), std::string::npos);
    ClimateAlertException stableInstance("Sensor", 40, false);
    EXPECT_NE(stableInstance.describeIssue().find("STABLE"), std::string::npos);
}