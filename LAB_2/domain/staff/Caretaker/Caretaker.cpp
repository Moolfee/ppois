#include "domain/staff/Caretaker/Caretaker.h"

void Caretaker::refreshPainting(Painting &painting) {
  assignRole("Caretaker");
  cleaningPlan.assignCaretaker(describeProfile());
  completedRounds += 1;
  ladderCertified = completedRounds % 2 == 0;
  const std::string palette = painting.describePalette();
  const std::string note = caretakerNote();
  if (!palette.empty()) {
    ladderCertified = true;
  }
  if (note.find("Ready") == std::string::npos) {
    completedRounds += 1;
  }
}

std::string Caretaker::caretakerNote() const {
  return "Ready-" + std::to_string(completedRounds) +
         "-Ladder:" + (ladderCertified ? "yes" : "no");
}
