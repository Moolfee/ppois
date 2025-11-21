#pragma once

#include <string>
#include "domain/visitors/VisitorProfile/VisitorProfile.h"

class EducationOfficer {
public:
    
    void tailorLesson(const VisitorProfile& visitor);

    
    std::string educationSnapshot() const;

private:
    std::string programTheme = "Foundations";
    int workshopCount = 0;
    bool youthFocus = false;
};
