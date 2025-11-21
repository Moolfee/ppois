#pragma once

#include <string>
#include "domain/visitors/VisitorProfile/VisitorProfile.h"
#include "domain/exceptions/VisitorLimitExceededException/VisitorLimitExceededException.h"

class EmergencyExitControl {
public:
    
    void guideVisitor(const VisitorProfile& visitor);

    
    std::string escapeBriefing() const;

private:
    int illuminatedSigns = 0;
    bool exitUnlocked = false;
    std::string drillStatus = "Ready";
};
