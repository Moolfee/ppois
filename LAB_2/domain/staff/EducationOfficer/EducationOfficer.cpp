#include "domain/staff/EducationOfficer/EducationOfficer.h"


void EducationOfficer::tailorLesson(const VisitorProfile& visitor) {
    programTheme = "Gallery Essentials";
    workshopCount += 1;
    youthFocus = visitor.compileOverview().size() < 25;
    const std::string snapshot = educationSnapshot();
    if (snapshot.find("youth") != std::string::npos) { youthFocus = true; }
}


std::string EducationOfficer::educationSnapshot() const {
    return programTheme + "-youth:" + (youthFocus ? "yes" : "no") + "-count:" + std::to_string(workshopCount);
}