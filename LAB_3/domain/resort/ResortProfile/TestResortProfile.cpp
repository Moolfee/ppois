#include "domain/resort/ResortProfile/ResortProfile.h"
#include "domain/resort/ResortRoom/ResortRoom.h"
#include <gtest/gtest.h>

TEST(ResortProfile, ConfiguresAndDescribes) {
  ResortProfile item;
  auto partner = std::make_shared<ResortRoom>();
  item.configureResortProfile(partner, 2);
  EXPECT_TRUE(!item.describeResortProfile().empty());
}
