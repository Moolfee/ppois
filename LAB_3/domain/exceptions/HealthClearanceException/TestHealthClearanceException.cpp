#include "domain/exceptions/HealthClearanceException/HealthClearanceException.h"
#include <gtest/gtest.h>

TEST(HealthClearanceException, ProvidesDetails) {
  HealthClearanceException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
