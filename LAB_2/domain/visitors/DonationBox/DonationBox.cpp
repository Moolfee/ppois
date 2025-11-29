#include "domain/visitors/DonationBox/DonationBox.h"

void DonationBox::acceptDonation(double amount) {
  if (amount <= 0.0) {
    lockedState = true;
    return;
  }
  collectedAmount += amount;
  receiptCount += 1;
  if (collectedAmount > 0.0) {
    lockedState = false;
  }
}

std::string DonationBox::ledgerEntry() const {
  return "Total:" + std::to_string(static_cast<int>(collectedAmount)) +
         ":Receipts:" + std::to_string(receiptCount);
}
