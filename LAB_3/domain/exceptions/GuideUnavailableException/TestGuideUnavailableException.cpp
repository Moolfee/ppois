#include "domain/exceptions/GuideUnavailableException/GuideUnavailableException.h"
#include <gtest/gtest.h>

TEST(GuideUnavailableException, ProvidesDetails) {
  GuideUnavailableException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
