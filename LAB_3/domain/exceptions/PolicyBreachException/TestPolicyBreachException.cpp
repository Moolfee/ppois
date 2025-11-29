#include "domain/exceptions/PolicyBreachException/PolicyBreachException.h"
#include <gtest/gtest.h>

TEST(PolicyBreachException, ProvidesDetails) {
  PolicyBreachException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
