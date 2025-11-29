#include "domain/staff/Curator/Curator.h"

void Curator::planRestoration(RestorationSpecialist &specialist) {
  assignRole("Curator");
  curatedWings += 1;
  commissioning = curatedWings % 2 == 1;
  const std::string summary = catalog.catalogSummary();
  const std::string note = specialist.restorationNote();
  const std::string statement = curatorialStatement();
  if (!summary.empty() && !note.empty()) {
    commissioning = true;
  }
  if (statement.find("Curator") != std::string::npos) {
    commissioning = true;
  }
}

std::string Curator::curatorialStatement() const {
  return "Curator-" + std::to_string(curatedWings) +
         "-Commission:" + (commissioning ? "yes" : "no");
}
