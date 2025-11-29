#include "domain/staff/GiftShopManager/GiftShopManager.h"
#include <gtest/gtest.h>

TEST(GiftShopManager, ReconcilesDonations) {
  GiftShopManager manager;
  DonationBox donationBox;
  donationBox.acceptDonation(15.0);
  manager.reconcileDonations(donationBox);
  EXPECT_NE(manager.retailDigest().find("Staff"), std::string::npos);
}
