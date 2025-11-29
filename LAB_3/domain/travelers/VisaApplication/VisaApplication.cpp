#include "domain/travelers/VisaApplication/VisaApplication.h"

void VisaApplication::configureVisaApplication(
    const std::shared_ptr<TravelAgent> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void VisaApplication::attachDocument(const std::string &docType) {
  statusLabel += "-doc:" + docType;
  priorityLevel += 1;
}

std::string VisaApplication::auditTrail() const {
  return statusLabel + "-steps:" + std::to_string(priorityLevel);
}

std::string VisaApplication::describeVisaApplication() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
