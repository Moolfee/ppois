#pragma once

#include <string>
#include "domain/staff/StaffMember/StaffMember.h"
#include "domain/operations/CleaningSchedule/CleaningSchedule.h"
#include "domain/gallery/Painting/Painting.h"

class Caretaker : public StaffMember {
public:
    
    void refreshPainting(Painting& painting);

    
    std::string caretakerNote() const;

private:
    CleaningSchedule cleaningPlan = {};
    bool ladderCertified = false;
    int completedRounds = 0;
};
