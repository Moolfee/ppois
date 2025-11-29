#include "domain/staff/RestorationSpecialist/RestorationSpecialist.h"

void RestorationSpecialist::treatPainting(Painting &painting) {
  assignRole("Restorer");
  specialty = painting.describePalette();
  ongoingTreatments += 1;
  solventReady = ongoingTreatments < 3;
  const std::string note = restorationNote();
  if (note.find("Restorer") != std::string::npos) {
    solventReady = true;
  }
}

std::string RestorationSpecialist::restorationNote() const {
  return "Restorer-" + specialty +
         "-Count:" + std::to_string(ongoingTreatments);
}
