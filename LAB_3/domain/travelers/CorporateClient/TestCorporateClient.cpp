#include "domain/finance/Invoice/Invoice.h"
#include "domain/travelers/CorporateClient/CorporateClient.h"
#include <gtest/gtest.h>

TEST(CorporateClient, ConfiguresAndDescribes) {
  CorporateClient item;
  auto partner = std::make_shared<Invoice>();
  item.configureCorporateClient(partner, 2);
  EXPECT_TRUE(!item.describeCorporateClient().empty());
}

TEST(CorporateClient, RenegotiatesTermsAndBillingProfile) {
  CorporateClient client;
  client.renegotiateTerms(3);
  EXPECT_NE(client.billingProfile().find("tier"), std::string::npos);
}
