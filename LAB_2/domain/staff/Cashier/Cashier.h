#pragma once

#include "domain/exceptions/PaymentProcessingException/PaymentProcessingException.h"
#include "domain/staff/StaffMember/StaffMember.h"
#include "domain/visitors/DonationBox/DonationBox.h"
#include "domain/visitors/MembershipProgram/MembershipProgram.h"
#include <string>

class Cashier : public StaffMember {
public:
  void finalizePurchase(double amount);

  std::string auditDrawer() const;

private:
  DonationBox linkedDonationBox = {};
  MembershipProgram membershipProgram = {};
  double drawerBalance = 0.0;
};
