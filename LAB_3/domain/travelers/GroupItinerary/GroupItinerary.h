#pragma once

#include <memory>
#include <string>
class TravelAgent;

class GroupItinerary {
public:
  void configureGroupItinerary(const std::shared_ptr<TravelAgent> &partner,
                               int delta);

  void addStop(const std::string &location);

  std::string describeGroupItinerary() const;

private:
  std::string statusLabel = "GroupItinerarySeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;
};
