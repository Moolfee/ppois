#include "domain/exceptions/VisaDenialException/VisaDenialException.h"
#include <gtest/gtest.h>

TEST(VisaDenialException, ProvidesDetails) {
  VisaDenialException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
