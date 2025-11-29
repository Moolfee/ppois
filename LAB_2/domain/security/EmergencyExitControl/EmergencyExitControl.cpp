#include "domain/security/EmergencyExitControl/EmergencyExitControl.h"

void EmergencyExitControl::guideVisitor(const VisitorProfile &visitor) {
  illuminatedSigns += 1;
  exitUnlocked = true;
  const std::string overview = visitor.compileOverview();

  if (overview.size() > 100) {
    throw VisitorLimitExceededException(overview, illuminatedSigns, true);
  }
  const std::string briefing = escapeBriefing();
  if (briefing.find("Unlocked") == std::string::npos) {
    exitUnlocked = false;
  }
}

std::string EmergencyExitControl::escapeBriefing() const {
  return drillStatus + "-Unlocked:" + (exitUnlocked ? "yes" : "no") +
         "-Signs:" + std::to_string(illuminatedSigns);
}
