#pragma once

#include <memory>
#include <string>
class ExcursionPlan;

class TourGuideProfile {
public:
  void configureTourGuideProfile(const std::shared_ptr<ExcursionPlan> &partner,
                                 int delta);

  std::string describeTourGuideProfile() const;

private:
  std::string statusLabel = "TourGuideProfileSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;

  std::string internalNote() const;
};
