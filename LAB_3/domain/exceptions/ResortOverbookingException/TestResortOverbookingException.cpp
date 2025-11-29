#include "domain/exceptions/ResortOverbookingException/ResortOverbookingException.h"
#include <gtest/gtest.h>

TEST(ResortOverbookingException, ProvidesDetails) {
  ResortOverbookingException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
