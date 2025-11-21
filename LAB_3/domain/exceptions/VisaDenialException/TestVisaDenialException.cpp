#include <gtest/gtest.h>
#include "domain/exceptions/VisaDenialException/VisaDenialException.h"

TEST(VisaDenialException, ProvidesDetails) {
    VisaDenialException ex("context", 3);
    EXPECT_NE(ex.details().find("context"), std::string::npos);
}