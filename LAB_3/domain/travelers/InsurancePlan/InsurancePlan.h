#pragma once

#include <memory>
#include <string>
class TravelPolicy;

class InsurancePlan {
public:
  void configureInsurancePlan(const std::shared_ptr<TravelPolicy> &partner,
                              int delta);

  void addCoverage(const std::string &coverage);

  bool coversEmergency() const;

  std::string describeInsurancePlan() const;

private:
  std::string statusLabel = "InsurancePlanSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelPolicy> linkedPartner = nullptr;
};
