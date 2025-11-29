#include "domain/offers/LoyaltyProgram/LoyaltyProgram.h"

void LoyaltyProgram::configureLoyaltyProgram(
    const std::shared_ptr<FrequentFlyerAccount> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void LoyaltyProgram::awardBonusMiles(int miles) {
  if (miles > 0) {
    priorityLevel += miles / 100;
    statusLabel += "-bonus";
  }
}

std::string LoyaltyProgram::tier() const {
  if (priorityLevel > 5) {
    return statusLabel + "-gold";
  }
  if (priorityLevel > 2) {
    return statusLabel + "-silver";
  }
  return statusLabel + "-basic";
}

std::string LoyaltyProgram::describeLoyaltyProgram() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
