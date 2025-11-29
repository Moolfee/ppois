#include "domain/travelers/FamilyBooking/FamilyBooking.h"

void FamilyBooking::configureFamilyBooking(
    const std::shared_ptr<TravelAgent> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void FamilyBooking::addTraveler(int count) {
  if (count > 0) {
    priorityLevel += count;
    statusLabel += "-group";
  }
}

bool FamilyBooking::requiresEscort() const { return priorityLevel > 4; }

std::string FamilyBooking::describeFamilyBooking() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
