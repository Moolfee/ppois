#include "domain/travelers/CorporateClient/CorporateClient.h"

void CorporateClient::configureCorporateClient(
    const std::shared_ptr<Invoice> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void CorporateClient::renegotiateTerms(int step) {
  priorityLevel += step;
  statusLabel += "-renegotiated";
}

std::string CorporateClient::billingProfile() const {
  return statusLabel + "-tier:" + std::to_string(priorityLevel);
}

std::string CorporateClient::describeCorporateClient() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
