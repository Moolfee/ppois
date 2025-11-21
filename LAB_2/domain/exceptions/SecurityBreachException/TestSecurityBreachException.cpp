#include <gtest/gtest.h>
#include "domain/exceptions/SecurityBreachException/SecurityBreachException.h"

TEST(SecurityBreachException, DescribesBreachIssue) {
    SecurityBreachException exceptionInstance("LOW-20", 2, false);
    EXPECT_NE(exceptionInstance.describeIssue().find("LOW"), std::string::npos);
    SecurityBreachException lockInstance("HIGH-30", 4, true);
    EXPECT_NE(lockInstance.breachMarker().find("lock"), std::string::npos);
}