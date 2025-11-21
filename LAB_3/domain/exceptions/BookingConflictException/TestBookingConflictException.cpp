#include <gtest/gtest.h>
#include "domain/exceptions/BookingConflictException/BookingConflictException.h"

TEST(BookingConflictException, ProvidesDetails) {
    BookingConflictException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}