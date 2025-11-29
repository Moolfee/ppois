#pragma once

#include <memory>
#include <string>
class TravelAgent;

class VisaApplication {
public:
  void configureVisaApplication(const std::shared_ptr<TravelAgent> &partner,
                                int delta);

  std::string describeVisaApplication() const;

private:
  std::string statusLabel = "VisaApplicationSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;

  std::string internalNote() const;
};
