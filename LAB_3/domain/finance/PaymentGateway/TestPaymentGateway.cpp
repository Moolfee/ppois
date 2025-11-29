#include "domain/finance/Invoice/Invoice.h"
#include "domain/finance/PaymentGateway/PaymentGateway.h"
#include <gtest/gtest.h>

TEST(PaymentGateway, ConfiguresAndDescribes) {
  PaymentGateway item;
  auto partner = std::make_shared<Invoice>();
  item.configurePaymentGateway(partner, 2);
  EXPECT_TRUE(!item.describePaymentGateway().empty());
}
