#pragma once

#include <memory>
#include <string>
class TravelAgent;

class FlightTicket {
public:
  void configureFlightTicket(const std::shared_ptr<TravelAgent> &partner,
                             int delta);

  void upgradeCabin(const std::string &cabinClass);

  void blockSeat();

  std::string describeFlightTicket() const;

private:
  std::string statusLabel = "FlightTicketSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;
};
