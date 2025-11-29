#include "domain/gallery/GalleryMap/GalleryMap.h"
#include <gtest/gtest.h>

TEST(GalleryMap, UpdatesWingAndMarksPrintStatus) {
  GalleryMap galleryMap;
  galleryMap.updateWing("South");
  EXPECT_NE(galleryMap.mapDigest().find("South"), std::string::npos);

  galleryMap.updateWing("ExtremelyLongWingIdentifierToTriggerDigestLimit");
  EXPECT_NE(galleryMap.mapDigest().find("print:no"), std::string::npos);
}
