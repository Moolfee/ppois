#pragma once

#include <memory>
#include <string>
class ExcursionPlan;

class CityPass {
public:
  void configureCityPass(const std::shared_ptr<ExcursionPlan> &partner,
                         int delta);

  void activateDay(int dayIndex);

  bool isActive() const;

  std::string describeCityPass() const;

private:
  std::string statusLabel = "CityPassSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;
};
