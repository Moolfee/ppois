#include <gtest/gtest.h>
#include "domain/offers/LoyaltyProgram/LoyaltyProgram.h"
#include "domain/travelers/FrequentFlyerAccount/FrequentFlyerAccount.h"

TEST(LoyaltyProgram, ConfiguresAndDescribes) {
    LoyaltyProgram item;
    auto partner = std::make_shared<FrequentFlyerAccount>();
    item.configureLoyaltyProgram(partner, 2);
    EXPECT_TRUE(!item.describeLoyaltyProgram().empty());
}