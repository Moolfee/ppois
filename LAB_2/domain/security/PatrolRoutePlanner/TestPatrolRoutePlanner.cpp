#include "domain/security/PatrolRoutePlanner/PatrolRoutePlanner.h"
#include <gtest/gtest.h>

TEST(PatrolRoutePlanner, IntegratesMap) {
  PatrolRoutePlanner planner;
  GalleryMap galleryMap;
  galleryMap.updateWing("North");
  planner.integrateMap(galleryMap);
  EXPECT_NE(planner.routeDigest().find("points"), std::string::npos);
}
