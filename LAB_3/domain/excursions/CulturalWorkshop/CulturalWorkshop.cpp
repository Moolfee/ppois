#include "domain/excursions/CulturalWorkshop/CulturalWorkshop.h"

void CulturalWorkshop::configureCulturalWorkshop(
    const std::shared_ptr<TourGuideProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string CulturalWorkshop::describeCulturalWorkshop() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string CulturalWorkshop::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
