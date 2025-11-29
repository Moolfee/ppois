#include "domain/exceptions/BookingConflictException/BookingConflictException.h"
#include <gtest/gtest.h>

TEST(BookingConflictException, ProvidesDetails) {
  BookingConflictException ex("context", 3);
  EXPECT_NE(ex.details().find("context"), std::string::npos);
}
