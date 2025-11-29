#include "domain/gallery/InventoryTracker/InventoryTracker.h"
#include <gtest/gtest.h>

TEST(InventoryTracker, FlagsInconsistency) {
  InventoryTracker tracker;
  tracker.flagInconsistency("Art-1");
  EXPECT_NE(tracker.trackerDigest("Art-1").find("Art-1"), std::string::npos);
}
