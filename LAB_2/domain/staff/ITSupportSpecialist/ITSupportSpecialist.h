#pragma once

#include <string>
#include "domain/visitors/AudioGuide/AudioGuide.h"

class ITSupportSpecialist {
public:
    
    void patchAudioGuide(AudioGuide& guide);

    
    std::string supportDigest() const;

private:
    std::string technicianName = "HelpDesk";
    int resolvedTickets = 0;
    bool nightShift = false;
};
