#pragma once

#include <memory>
#include <string>
class ExcursionPlan;

class ExperienceBundle {
public:
  void configureExperienceBundle(const std::shared_ptr<ExcursionPlan> &partner,
                                 int delta);

  void addPerk(const std::string &perkName);

  std::string bundleSummary() const;

  std::string describeExperienceBundle() const;

private:
  std::string statusLabel = "ExperienceBundleSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;
};
