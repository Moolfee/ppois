#pragma once

#include "domain/visitors/VisitorProfile/VisitorProfile.h"
#include <string>

class EducationOfficer {
public:
  void tailorLesson(const VisitorProfile &visitor);

  std::string educationSnapshot() const;

private:
  std::string programTheme = "Foundations";
  int workshopCount = 0;
  bool youthFocus = false;
};
