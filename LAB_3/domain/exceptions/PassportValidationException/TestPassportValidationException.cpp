#include "domain/exceptions/PassportValidationException/PassportValidationException.h"
#include <gtest/gtest.h>

TEST(PassportValidationException, ProvidesDetails) {
  PassportValidationException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
