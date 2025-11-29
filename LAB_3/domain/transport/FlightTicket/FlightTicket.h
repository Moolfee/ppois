#pragma once

#include <memory>
#include <string>
class TravelAgent;

class FlightTicket {
public:
  void configureFlightTicket(const std::shared_ptr<TravelAgent> &partner,
                             int delta);

  std::string describeFlightTicket() const;

private:
  std::string statusLabel = "FlightTicketSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;

  std::string internalNote() const;
};
