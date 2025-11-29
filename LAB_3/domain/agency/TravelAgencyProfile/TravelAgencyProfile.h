#pragma once

#include <memory>
#include <string>
class TravelPolicy;

class TravelAgencyProfile {
public:
  void
  configureTravelAgencyProfile(const std::shared_ptr<TravelPolicy> &partner,
                               int delta);

  void openMarket(const std::string &regionCode);

  void pauseMarket();

  std::string describeTravelAgencyProfile() const;

private:
  std::string statusLabel = "TravelAgencyProfileSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelPolicy> linkedPartner = nullptr;
};
