#include <gtest/gtest.h>
#include "domain/exceptions/GuideUnavailableException/GuideUnavailableException.h"

TEST(GuideUnavailableException, ProvidesDetails) {
    GuideUnavailableException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}