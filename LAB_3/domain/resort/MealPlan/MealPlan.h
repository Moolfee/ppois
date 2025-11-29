#pragma once

#include <memory>
#include <string>
class PartnerHotel;

class MealPlan {
public:
  void configureMealPlan(const std::shared_ptr<PartnerHotel> &partner,
                         int delta);

  std::string describeMealPlan() const;

private:
  std::string statusLabel = "MealPlanSeed";
  int priorityLevel = 1;
  std::shared_ptr<PartnerHotel> linkedPartner = nullptr;

  std::string internalNote() const;
};
