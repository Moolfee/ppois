#include "domain/finance/Invoice/Invoice.h"
#include "domain/finance/PaymentGateway/PaymentGateway.h"
#include <gtest/gtest.h>

TEST(Invoice, ConfiguresAndDescribes) {
  Invoice item;
  auto partner = std::make_shared<PaymentGateway>();
  item.configureInvoice(partner, 2);
  EXPECT_TRUE(!item.describeInvoice().empty());
}

TEST(Invoice, RecordsPaymentAndReportsStatus) {
  Invoice item;
  item.recordPayment(150.0);
  EXPECT_NE(item.paymentStatus().find("paid"), std::string::npos);
  item.recordPayment(0.0);
  EXPECT_NE(item.paymentStatus().find("underpaid"), std::string::npos);
}
