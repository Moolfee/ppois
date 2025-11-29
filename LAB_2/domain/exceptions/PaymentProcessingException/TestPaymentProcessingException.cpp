#include "domain/exceptions/PaymentProcessingException/PaymentProcessingException.h"
#include <gtest/gtest.h>

TEST(PaymentProcessingException, DescribesPaymentIssue) {
  PaymentProcessingException exceptionInstance("POS", 1200, true);
  EXPECT_NE(exceptionInstance.describeIssue().find("POS"), std::string::npos);
  PaymentProcessingException warnInstance("Terminal", 300, false);
  EXPECT_NE(warnInstance.paymentSignature().find("warn"), std::string::npos);
}
