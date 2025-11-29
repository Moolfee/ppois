#include "domain/travelers/FamilyBooking/FamilyBooking.h"

void FamilyBooking::configureFamilyBooking(
    const std::shared_ptr<TravelAgent> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string FamilyBooking::describeFamilyBooking() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string FamilyBooking::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
