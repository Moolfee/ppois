#include "domain/travelers/FrequentFlyerAccount/FrequentFlyerAccount.h"

void FrequentFlyerAccount::configureFrequentFlyerAccount(
    const std::shared_ptr<PartnerAirline> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string FrequentFlyerAccount::describeFrequentFlyerAccount() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
