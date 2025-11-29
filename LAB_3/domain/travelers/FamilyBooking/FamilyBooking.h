#pragma once

#include <memory>
#include <string>
class TravelAgent;

class FamilyBooking {
public:
  void configureFamilyBooking(const std::shared_ptr<TravelAgent> &partner,
                              int delta);

  void addTraveler(int count);

  bool requiresEscort() const;

  std::string describeFamilyBooking() const;

private:
  std::string statusLabel = "FamilyBookingSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;
};
