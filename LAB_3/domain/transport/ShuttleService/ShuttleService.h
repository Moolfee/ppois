#pragma once

#include <memory>
#include <string>
class AirportTransfer;

class ShuttleService {
public:
  void configureShuttleService(const std::shared_ptr<AirportTransfer> &partner,
                               int delta);

  void logRide(const std::string &rideId);

  std::string describeShuttleService() const;

private:
  std::string statusLabel = "ShuttleServiceSeed";
  int priorityLevel = 1;
  std::shared_ptr<AirportTransfer> linkedPartner = nullptr;
};
