#include <gtest/gtest.h>
#include "domain/staff/Cashier/Cashier.h"

TEST(Cashier, FinalizesPurchase) {
    Cashier cashier;
    cashier.finalizePurchase(20.0);
    EXPECT_NE(cashier.auditDrawer().find("drawer"), std::string::npos);
}

TEST(Cashier, RejectsInvalidSale) {
    Cashier cashier;
    bool exceptionRaised = false;
    try {
        cashier.finalizePurchase(-3.0);
    } catch (const PaymentProcessingException&) {
        exceptionRaised = true;
    }
    EXPECT_TRUE(exceptionRaised);
}