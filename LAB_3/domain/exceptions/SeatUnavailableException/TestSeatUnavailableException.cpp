#include <gtest/gtest.h>
#include "domain/exceptions/SeatUnavailableException/SeatUnavailableException.h"

TEST(SeatUnavailableException, ProvidesDetails) {
    SeatUnavailableException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}