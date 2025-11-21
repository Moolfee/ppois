#include <gtest/gtest.h>
#include "domain/gallery/InventoryTracker/InventoryTracker.h"

TEST(InventoryTracker, FlagsInconsistency) {
    InventoryTracker tracker;
    tracker.flagInconsistency("Art-1");
    EXPECT_NE(tracker.trackerDigest("Art-1").find("Art-1"), std::string::npos);
}