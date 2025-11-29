#pragma once

#include "domain/visitors/DonationBox/DonationBox.h"
#include <string>

class GiftShopManager {
public:
  void reconcileDonations(const DonationBox &box);

  std::string retailDigest() const;

private:
  std::string managerName = "RetailLead";
  double registerBalance = 0.0;
  int staffOnDuty = 1;
};
