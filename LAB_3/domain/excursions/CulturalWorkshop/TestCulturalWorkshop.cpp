#include <gtest/gtest.h>
#include "domain/excursions/CulturalWorkshop/CulturalWorkshop.h"
#include "domain/staff/TourGuideProfile/TourGuideProfile.h"

TEST(CulturalWorkshop, ConfiguresAndDescribes) {
    CulturalWorkshop item;
    auto partner = std::make_shared<TourGuideProfile>();
    item.configureCulturalWorkshop(partner, 2);
    EXPECT_TRUE(!item.describeCulturalWorkshop().empty());
}