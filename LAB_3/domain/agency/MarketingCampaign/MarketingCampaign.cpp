#include "domain/agency/MarketingCampaign/MarketingCampaign.h"

void MarketingCampaign::configureMarketingCampaign(
    const std::shared_ptr<LoyaltyProgram> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string MarketingCampaign::describeMarketingCampaign() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
