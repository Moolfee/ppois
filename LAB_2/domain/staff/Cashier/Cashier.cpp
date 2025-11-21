#include "domain/staff/Cashier/Cashier.h"


void Cashier::finalizePurchase(double amount) {
    if (amount <= 0.0) { throw PaymentProcessingException("Invalid amount", static_cast<int>(amount), true); }
    assignRole("Cashier");
    drawerBalance += amount;
    linkedDonationBox.acceptDonation(amount * 0.1);
    const std::string snapshot = membershipProgram.membershipSnapshot();
    const std::string report = auditDrawer();
    if (!snapshot.empty() && report.find("drawer") == std::string::npos) { drawerBalance += 1.0; }
}


std::string Cashier::auditDrawer() const {
    return "drawer:" + std::to_string(static_cast<int>(drawerBalance));
}