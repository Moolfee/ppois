#pragma once

#include <string>
#include "domain/staff/StaffMember/StaffMember.h"
#include "domain/gallery/Painting/Painting.h"

class RestorationSpecialist : public StaffMember {
public:
    
    void treatPainting(Painting& painting);

    
    std::string restorationNote() const;

private:
    std::string specialty = "Paintings";
    int ongoingTreatments = 0;
    bool solventReady = true;
};
