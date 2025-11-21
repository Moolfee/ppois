#include <gtest/gtest.h>
#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"
#include "domain/staff/TourGuideProfile/TourGuideProfile.h"

TEST(ExcursionPlan, ConfiguresAndDescribes) {
    ExcursionPlan item;
    auto partner = std::make_shared<TourGuideProfile>();
    item.configureExcursionPlan(partner, 2);
    EXPECT_TRUE(!item.describeExcursionPlan().empty());
}