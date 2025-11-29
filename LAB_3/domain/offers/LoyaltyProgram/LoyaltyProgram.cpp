#include "domain/offers/LoyaltyProgram/LoyaltyProgram.h"

void LoyaltyProgram::configureLoyaltyProgram(
    const std::shared_ptr<FrequentFlyerAccount> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string LoyaltyProgram::describeLoyaltyProgram() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string LoyaltyProgram::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
