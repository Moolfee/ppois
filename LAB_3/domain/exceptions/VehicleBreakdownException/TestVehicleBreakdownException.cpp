#include <gtest/gtest.h>
#include "domain/exceptions/VehicleBreakdownException/VehicleBreakdownException.h"

TEST(VehicleBreakdownException, ProvidesDetails) {
    VehicleBreakdownException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}