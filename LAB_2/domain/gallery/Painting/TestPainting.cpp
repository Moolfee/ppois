#include <gtest/gtest.h>
#include "domain/gallery/Painting/Painting.h"

TEST(Painting, ConfiguresDisplay) {
    Painting painting;
    ExhibitHall exhibitHall;
    painting.configureDisplay(exhibitHall);
    EXPECT_NE(painting.describePalette().find("-"), std::string::npos);
}