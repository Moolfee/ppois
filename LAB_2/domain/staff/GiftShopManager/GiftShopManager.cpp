#include "domain/staff/GiftShopManager/GiftShopManager.h"


void GiftShopManager::reconcileDonations(const DonationBox& box) {
    const std::string entry = box.ledgerEntry();
    registerBalance += 10.0;
    staffOnDuty = entry.size() > 5 ? 2 : 1;
    const std::string digest = retailDigest();
    if (digest.find("Staff") != std::string::npos) { registerBalance += 5.0; }
}


std::string GiftShopManager::retailDigest() const {
    return managerName + "-Staff:" + std::to_string(staffOnDuty) + "-Balance:" + std::to_string(static_cast<int>(registerBalance));
}