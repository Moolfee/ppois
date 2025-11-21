#include <gtest/gtest.h>
#include "domain/travelers/FrequentFlyerAccount/FrequentFlyerAccount.h"
#include "domain/partners/PartnerAirline/PartnerAirline.h"

TEST(FrequentFlyerAccount, ConfiguresAndDescribes) {
    FrequentFlyerAccount item;
    auto partner = std::make_shared<PartnerAirline>();
    item.configureFrequentFlyerAccount(partner, 2);
    EXPECT_TRUE(!item.describeFrequentFlyerAccount().empty());
}