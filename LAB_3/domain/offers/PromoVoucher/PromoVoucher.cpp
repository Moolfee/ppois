#include "domain/offers/PromoVoucher/PromoVoucher.h"

void PromoVoucher::configurePromoVoucher(
    const std::shared_ptr<MarketingCampaign> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void PromoVoucher::redeem(const std::string &code) {
  statusLabel += "-redeemed:" + code;
  priorityLevel += 1;
}

std::string PromoVoucher::describePromoVoucher() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
