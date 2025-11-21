#include <gtest/gtest.h>
#include "domain/exceptions/VisitorLimitExceededException/VisitorLimitExceededException.h"

TEST(VisitorLimitExceededException, DescribesVisitorIssue) {
    VisitorLimitExceededException exceptionInstance("Guide", 7, true);
    EXPECT_NE(exceptionInstance.describeIssue().find("Guide"), std::string::npos);
    VisitorLimitExceededException monitorInstance("Docent", 3, false);
    EXPECT_NE(monitorInstance.visitorFlag().find("monitor"), std::string::npos);
}