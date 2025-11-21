#include <gtest/gtest.h>
#include "domain/gallery/ExhibitHall/ExhibitHall.h"

TEST(ExhibitHall, ConfiguresAtmosphere) {
    ExhibitHall exhibitHall;
    exhibitHall.configureAtmosphere(90);
    EXPECT_NE(exhibitHall.evaluateWelcomeTone().find("Atmosphere"), std::string::npos);
}