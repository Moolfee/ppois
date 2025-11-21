#include <gtest/gtest.h>
#include "domain/exceptions/LoanAgreementException/LoanAgreementException.h"

TEST(LoanAgreementException, DescribesLoanIssue) {
    LoanAgreementException exceptionInstance("Partner", 1, false);
    EXPECT_NE(exceptionInstance.describeIssue().find("Partner"), std::string::npos);
    LoanAgreementException freezeInstance("Museum", 2, true);
    EXPECT_NE(freezeInstance.loanFlag().find("freeze"), std::string::npos);
}