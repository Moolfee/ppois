#pragma once

#include <memory>
#include <string>
class ExcursionPlan;

class ExperienceBundle {
public:
  void configureExperienceBundle(const std::shared_ptr<ExcursionPlan> &partner,
                                 int delta);

  std::string describeExperienceBundle() const;

private:
  std::string statusLabel = "ExperienceBundleSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;

  std::string internalNote() const;
};
