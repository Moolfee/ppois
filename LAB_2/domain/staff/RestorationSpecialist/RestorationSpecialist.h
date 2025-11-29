#pragma once

#include "domain/gallery/Painting/Painting.h"
#include "domain/staff/StaffMember/StaffMember.h"
#include <string>

class RestorationSpecialist : public StaffMember {
public:
  void treatPainting(Painting &painting);

  std::string restorationNote() const;

private:
  std::string specialty = "Paintings";
  int ongoingTreatments = 0;
  bool solventReady = true;
};
