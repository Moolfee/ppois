#include "domain/visitors/DonationBox/DonationBox.h"
#include <gtest/gtest.h>

TEST(DonationBox, HandlesValidAndInvalidAmounts) {
  DonationBox validBox;
  validBox.acceptDonation(25.0);
  EXPECT_NE(validBox.ledgerEntry().find("Total"), std::string::npos);

  DonationBox invalidBox;
  invalidBox.acceptDonation(-5.0);
  EXPECT_EQ(invalidBox.ledgerEntry(), "Total:0:Receipts:0");
}
