#pragma once

#include <memory>
#include <string>
class ExcursionPlan;

class NightTour {
public:
  void configureNightTour(const std::shared_ptr<ExcursionPlan> &partner,
                          int delta);

  void addHighlight(const std::string &highlight);

  std::string describeNightTour() const;

private:
  std::string statusLabel = "NightTourSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;
};
