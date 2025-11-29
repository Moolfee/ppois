#pragma once

#include <memory>
#include <string>
class TravelAgent;

class VisaApplication {
public:
  void configureVisaApplication(const std::shared_ptr<TravelAgent> &partner,
                                int delta);

  void attachDocument(const std::string &docType);

  std::string auditTrail() const;

  std::string describeVisaApplication() const;

private:
  std::string statusLabel = "VisaApplicationSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;
};
