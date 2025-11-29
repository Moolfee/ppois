#pragma once

#include <memory>
#include <string>
class TravelPolicy;

class TravelAgencyProfile {
public:
  void
  configureTravelAgencyProfile(const std::shared_ptr<TravelPolicy> &partner,
                               int delta);

  std::string describeTravelAgencyProfile() const;

private:
  std::string statusLabel = "TravelAgencyProfileSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelPolicy> linkedPartner = nullptr;

  std::string internalNote() const;
};
