#pragma once

#include <memory>
#include <string>
class PartnerAirline;

class FrequentFlyerAccount {
public:
  void
  configureFrequentFlyerAccount(const std::shared_ptr<PartnerAirline> &partner,
                                int delta);

  std::string describeFrequentFlyerAccount() const;

private:
  std::string statusLabel = "FrequentFlyerAccountSeed";
  int priorityLevel = 1;
  std::shared_ptr<PartnerAirline> linkedPartner = nullptr;

  std::string internalNote() const;
};
