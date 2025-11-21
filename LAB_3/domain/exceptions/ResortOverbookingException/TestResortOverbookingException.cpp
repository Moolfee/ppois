#include <gtest/gtest.h>
#include "domain/exceptions/ResortOverbookingException/ResortOverbookingException.h"

TEST(ResortOverbookingException, ProvidesDetails) {
    ResortOverbookingException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}