#pragma once

#include <memory>
#include <string>
class FlightTicket;

class RideShare {
public:
  void configureRideShare(const std::shared_ptr<FlightTicket> &partner,
                          int delta);

  void schedulePickup(const std::string &pickupCode);

  std::string describeRideShare() const;

private:
  std::string statusLabel = "RideShareSeed";
  int priorityLevel = 1;
  std::shared_ptr<FlightTicket> linkedPartner = nullptr;
};
