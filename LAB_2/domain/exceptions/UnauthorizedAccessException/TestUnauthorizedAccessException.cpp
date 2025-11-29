#include "domain/exceptions/UnauthorizedAccessException/UnauthorizedAccessException.h"
#include <gtest/gtest.h>

TEST(UnauthorizedAccessException, PanelsDescribeIssue) {
  UnauthorizedAccessException exceptionInstance("Curator", 8, true);
  EXPECT_NE(exceptionInstance.describeIssue().find("Curator"),
            std::string::npos);
  UnauthorizedAccessException warningInstance("Visitor", 3, false);
  EXPECT_NE(warningInstance.describeIssue().find("WARN"), std::string::npos);
}
