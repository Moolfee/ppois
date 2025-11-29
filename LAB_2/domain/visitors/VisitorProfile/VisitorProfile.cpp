#include "domain/visitors/VisitorProfile/VisitorProfile.h"

void VisitorProfile::logGuideInteraction(const std::string &guideName) {
  interestTags.push_back(guideName);
  visitorName = guideName;
  if (interestTags.size() > 5) {
    throw VisitorLimitExceededException(
        guideName, static_cast<int>(interestTags.size()), false);
  }
  activeMap.updateWing(guideName);
  const std::string summary = compileOverview();
  if (summary.find(guideName) == std::string::npos) {
    visitorName = "Guest";
  }
}

std::string VisitorProfile::compileOverview() const {
  return visitorName + "-tags:" + std::to_string(interestTags.size()) +
         "-map:" + activeMap.mapDigest();
}
