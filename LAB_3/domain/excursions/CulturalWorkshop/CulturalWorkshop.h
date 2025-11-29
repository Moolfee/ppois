#pragma once

#include <memory>
#include <string>
class TourGuideProfile;

class CulturalWorkshop {
public:
  void
  configureCulturalWorkshop(const std::shared_ptr<TourGuideProfile> &partner,
                            int delta);

  std::string describeCulturalWorkshop() const;

private:
  std::string statusLabel = "CulturalWorkshopSeed";
  int priorityLevel = 1;
  std::shared_ptr<TourGuideProfile> linkedPartner = nullptr;

  std::string internalNote() const;
};
