#include "domain/agency/MarketingCampaign/MarketingCampaign.h"
#include "domain/offers/LoyaltyProgram/LoyaltyProgram.h"
#include <gtest/gtest.h>

TEST(MarketingCampaign, ConfiguresAndDescribes) {
  MarketingCampaign item;
  auto partner = std::make_shared<LoyaltyProgram>();
  item.configureMarketingCampaign(partner, 2);
  EXPECT_TRUE(!item.describeMarketingCampaign().empty());
}
