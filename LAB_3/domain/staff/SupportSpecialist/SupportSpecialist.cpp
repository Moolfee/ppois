#include "domain/staff/SupportSpecialist/SupportSpecialist.h"

void SupportSpecialist::configureSupportSpecialist(
    const std::shared_ptr<TravelAgent> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void SupportSpecialist::resolveTicket(const std::string &issueCode) {
  statusLabel += "-ticket:" + issueCode;
  priorityLevel += 1;
}

std::string SupportSpecialist::describeSupportSpecialist() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
