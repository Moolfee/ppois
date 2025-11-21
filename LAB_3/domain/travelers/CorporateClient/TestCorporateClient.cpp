#include <gtest/gtest.h>
#include "domain/travelers/CorporateClient/CorporateClient.h"
#include "domain/finance/Invoice/Invoice.h"

TEST(CorporateClient, ConfiguresAndDescribes) {
    CorporateClient item;
    auto partner = std::make_shared<Invoice>();
    item.configureCorporateClient(partner, 2);
    EXPECT_TRUE(!item.describeCorporateClient().empty());
}