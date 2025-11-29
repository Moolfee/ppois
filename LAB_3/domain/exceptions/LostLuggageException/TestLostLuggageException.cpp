#include "domain/exceptions/LostLuggageException/LostLuggageException.h"
#include <gtest/gtest.h>

TEST(LostLuggageException, ProvidesDetails) {
  LostLuggageException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
