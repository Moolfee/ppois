#pragma once

#include <memory>
#include <string>
class TravelAgent;

class SupportSpecialist {
public:
  void configureSupportSpecialist(const std::shared_ptr<TravelAgent> &partner,
                                  int delta);

  void resolveTicket(const std::string &issueCode);

  std::string describeSupportSpecialist() const;

private:
  std::string statusLabel = "SupportSpecialistSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;
};
