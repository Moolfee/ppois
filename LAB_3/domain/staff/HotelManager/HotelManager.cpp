#include "domain/staff/HotelManager/HotelManager.h"

void HotelManager::configureHotelManager(
    const std::shared_ptr<PartnerHotel> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string HotelManager::describeHotelManager() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
