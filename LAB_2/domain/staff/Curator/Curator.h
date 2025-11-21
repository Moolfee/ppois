#pragma once

#include <string>
#include "domain/staff/StaffMember/StaffMember.h"
#include "domain/gallery/ArtworkCatalog/ArtworkCatalog.h"
#include "domain/staff/RestorationSpecialist/RestorationSpecialist.h"

class Curator : public StaffMember {
public:
    
    void planRestoration(RestorationSpecialist& specialist);

    
    std::string curatorialStatement() const;

private:
    ArtworkCatalog catalog = {};
    int curatedWings = 0;
    bool commissioning = false;
};
