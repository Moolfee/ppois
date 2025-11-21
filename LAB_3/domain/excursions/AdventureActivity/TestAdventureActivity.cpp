#include <gtest/gtest.h>
#include "domain/excursions/AdventureActivity/AdventureActivity.h"
#include "domain/travelers/TouristProfile/TouristProfile.h"

TEST(AdventureActivity, ConfiguresAndDescribes) {
    AdventureActivity item;
    auto partner = std::make_shared<TouristProfile>();
    item.configureAdventureActivity(partner, 2);
    EXPECT_TRUE(!item.describeAdventureActivity().empty());
}