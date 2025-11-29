#pragma once

#include <memory>
#include <string>
class FlightTicket;

class PartnerAirline {
public:
  void configurePartnerAirline(const std::shared_ptr<FlightTicket> &partner,
                               int delta);

  void publishSchedule(const std::string &season);

  bool hasAlliance() const;

  std::string describePartnerAirline() const;

private:
  std::string statusLabel = "PartnerAirlineSeed";
  int priorityLevel = 1;
  std::shared_ptr<FlightTicket> linkedPartner = nullptr;
};
