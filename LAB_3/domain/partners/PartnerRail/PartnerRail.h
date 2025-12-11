#pragma once

#include <memory>
#include <string>
class TrainPass;

class PartnerRail {
public:
  void configurePartnerRail(const std::shared_ptr<TrainPass> &partner,
                            int delta);

  void addRoute(const std::string &routeCode);

  std::string describePartnerRail() const;

private:
  std::string statusLabel = "PartnerRailSeed";
  int priorityLevel = 1;
  std::shared_ptr<TrainPass> linkedPartner = nullptr;
};
