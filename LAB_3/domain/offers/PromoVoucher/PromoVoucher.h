#pragma once

#include <memory>
#include <string>
class MarketingCampaign;

class PromoVoucher {
public:
  void configurePromoVoucher(const std::shared_ptr<MarketingCampaign> &partner,
                             int delta);

  void redeem(const std::string &code);

  std::string describePromoVoucher() const;

private:
  std::string statusLabel = "PromoVoucherSeed";
  int priorityLevel = 1;
  std::shared_ptr<MarketingCampaign> linkedPartner = nullptr;
};
