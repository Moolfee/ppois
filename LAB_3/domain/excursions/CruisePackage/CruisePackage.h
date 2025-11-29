#pragma once

#include <memory>
#include <string>
class MealPlan;

class CruisePackage {
public:
  void configureCruisePackage(const std::shared_ptr<MealPlan> &partner,
                              int delta);

  std::string describeCruisePackage() const;

private:
  std::string statusLabel = "CruisePackageSeed";
  int priorityLevel = 1;
  std::shared_ptr<MealPlan> linkedPartner = nullptr;

  std::string internalNote() const;
};
