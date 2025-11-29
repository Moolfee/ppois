#include "domain/travelers/SoloBackpacker/SoloBackpacker.h"

void SoloBackpacker::configureSoloBackpacker(
    const std::shared_ptr<ExcursionPlan> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string SoloBackpacker::describeSoloBackpacker() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string SoloBackpacker::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
