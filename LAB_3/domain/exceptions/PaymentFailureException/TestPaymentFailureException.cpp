#include "domain/exceptions/PaymentFailureException/PaymentFailureException.h"
#include <gtest/gtest.h>

TEST(PaymentFailureException, ProvidesDetails) {
  PaymentFailureException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
