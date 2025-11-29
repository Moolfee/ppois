#pragma once

#include <memory>
#include <string>
class TouristProfile;

class TravelAgent {
public:
  void configureTravelAgent(const std::shared_ptr<TouristProfile> &partner,
                            int delta);

  void assignClient(const std::string &clientName);

  std::string bookingSummary() const;

  std::string describeTravelAgent() const;

private:
  std::string statusLabel = "TravelAgentSeed";
  int priorityLevel = 1;
  std::shared_ptr<TouristProfile> linkedPartner = nullptr;
};
