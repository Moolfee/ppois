#include "domain/excursions/AdventureActivity/AdventureActivity.h"

void AdventureActivity::configureAdventureActivity(
    const std::shared_ptr<TouristProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string AdventureActivity::describeAdventureActivity() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string AdventureActivity::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
