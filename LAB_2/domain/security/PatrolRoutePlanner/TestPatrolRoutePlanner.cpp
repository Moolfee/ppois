#include <gtest/gtest.h>
#include "domain/security/PatrolRoutePlanner/PatrolRoutePlanner.h"

TEST(PatrolRoutePlanner, IntegratesMap) {
    PatrolRoutePlanner planner;
    GalleryMap galleryMap;
    galleryMap.updateWing("North");
    planner.integrateMap(galleryMap);
    EXPECT_NE(planner.routeDigest().find("points"), std::string::npos);
}