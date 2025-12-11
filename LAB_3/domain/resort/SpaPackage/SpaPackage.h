#pragma once

#include <memory>
#include <string>
class ResortProfile;

class SpaPackage {
public:
  void configureSpaPackage(const std::shared_ptr<ResortProfile> &partner,
                           int delta);

  void addTreatment(const std::string &treatment);

  std::string describeSpaPackage() const;

private:
  std::string statusLabel = "SpaPackageSeed";
  int priorityLevel = 1;
  std::shared_ptr<ResortProfile> linkedPartner = nullptr;
};
