#include <gtest/gtest.h>
#include "domain/exceptions/EquipmentFailureException/EquipmentFailureException.h"

TEST(EquipmentFailureException, DescribesEquipmentIssue) {
    EquipmentFailureException exceptionInstance("Drone", 404, true);
    EXPECT_NE(exceptionInstance.describeIssue().find("Drone"), std::string::npos);
    EquipmentFailureException observeInstance("Camera", 100, false);
    EXPECT_NE(observeInstance.describeIssue().find("observe"), std::string::npos);
}