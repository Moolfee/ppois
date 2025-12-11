#pragma once

#include <memory>
#include <string>
class ExperienceBundle;

class AddOnService {
public:
  void configureAddOnService(const std::shared_ptr<ExperienceBundle> &partner,
                             int delta);

  void attachPerk(const std::string &perkName);

  std::string describeAddOnService() const;

private:
  std::string statusLabel = "AddOnServiceSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExperienceBundle> linkedPartner = nullptr;
};
