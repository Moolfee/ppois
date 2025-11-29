#include "domain/offers/LoyaltyProgram/LoyaltyProgram.h"
#include "domain/travelers/FrequentFlyerAccount/FrequentFlyerAccount.h"
#include <gtest/gtest.h>

TEST(LoyaltyProgram, ConfiguresAndDescribes) {
  LoyaltyProgram item;
  auto partner = std::make_shared<FrequentFlyerAccount>();
  item.configureLoyaltyProgram(partner, 2);
  EXPECT_TRUE(!item.describeLoyaltyProgram().empty());
}

TEST(LoyaltyProgram, AwardsMilesAndUpgradesTier) {
  LoyaltyProgram program;
  program.awardBonusMiles(300);
  EXPECT_NE(program.tier().find("silver"), std::string::npos);
  program.awardBonusMiles(300);
  EXPECT_NE(program.tier().find("gold"), std::string::npos);
}
