#include <gtest/gtest.h>
#include "domain/exceptions/PolicyBreachException/PolicyBreachException.h"

TEST(PolicyBreachException, ProvidesDetails) {
    PolicyBreachException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}