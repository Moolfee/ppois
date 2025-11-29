#pragma once

#include <string>

class DonationBox {
public:
  void acceptDonation(double amount);

  std::string ledgerEntry() const;

private:
  double collectedAmount = 0.0;
  int receiptCount = 0;
  bool lockedState = false;
};
