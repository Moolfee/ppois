#include <gtest/gtest.h>
#include "domain/exceptions/MaintenanceDelayException/MaintenanceDelayException.h"

TEST(MaintenanceDelayException, DescribesMaintenanceIssue) {
    MaintenanceDelayException exceptionInstance("Chief", 4, true);
    EXPECT_NE(exceptionInstance.describeIssue().find("Chief"), std::string::npos);
    MaintenanceDelayException crewInstance("Lead", 2, false);
    EXPECT_NE(crewInstance.maintenanceFlag().find("crew"), std::string::npos);
}