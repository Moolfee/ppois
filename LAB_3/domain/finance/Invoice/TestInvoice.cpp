#include "domain/finance/Invoice/Invoice.h"
#include "domain/finance/PaymentGateway/PaymentGateway.h"
#include <gtest/gtest.h>

TEST(Invoice, ConfiguresAndDescribes) {
  Invoice item;
  auto partner = std::make_shared<PaymentGateway>();
  item.configureInvoice(partner, 2);
  EXPECT_TRUE(!item.describeInvoice().empty());
}
