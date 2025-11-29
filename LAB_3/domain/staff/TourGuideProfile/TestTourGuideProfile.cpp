#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"
#include "domain/staff/TourGuideProfile/TourGuideProfile.h"
#include <gtest/gtest.h>

TEST(TourGuideProfile, ConfiguresAndDescribes) {
  TourGuideProfile item;
  auto partner = std::make_shared<ExcursionPlan>();
  item.configureTourGuideProfile(partner, 2);
  EXPECT_TRUE(!item.describeTourGuideProfile().empty());
}
