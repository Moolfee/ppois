#include "domain/partners/PartnerAirline/PartnerAirline.h"
#include "domain/travelers/FrequentFlyerAccount/FrequentFlyerAccount.h"
#include <gtest/gtest.h>

TEST(FrequentFlyerAccount, ConfiguresAndDescribes) {
  FrequentFlyerAccount item;
  auto partner = std::make_shared<PartnerAirline>();
  item.configureFrequentFlyerAccount(partner, 2);
  EXPECT_TRUE(!item.describeFrequentFlyerAccount().empty());
}
