#pragma once

#include <string>
#include <vector>
#include "domain/visitors/VisitorProfile/VisitorProfile.h"

class MembershipProgram {
public:
    
    void enrollVisitor(const VisitorProfile& visitor);

    
    std::string membershipSnapshot() const;

private:
    int activeMembers = 0;
    double monthlyRevenue = 0.0;
    std::vector<std::string> tierNames = {};
};
