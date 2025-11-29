#pragma once

#include "domain/exceptions/VisitorLimitExceededException/VisitorLimitExceededException.h"
#include "domain/gallery/GalleryMap/GalleryMap.h"
#include <string>
#include <vector>

class VisitorProfile {
public:
  void logGuideInteraction(const std::string &guideName);

  std::string compileOverview() const;

private:
  std::string visitorName = "Guest";
  std::vector<std::string> interestTags = {};
  GalleryMap activeMap = {};
};
