#pragma once

#include <memory>
#include <string>
class PartnerAirline;

class AirlineManager {
public:
  void configureAirlineManager(const std::shared_ptr<PartnerAirline> &partner,
                               int delta);

  std::string describeAirlineManager() const;

private:
  std::string statusLabel = "AirlineManagerSeed";
  int priorityLevel = 1;
  std::shared_ptr<PartnerAirline> linkedPartner = nullptr;
};
