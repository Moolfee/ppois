#pragma once

#include "domain/visitors/VisitorProfile/VisitorProfile.h"
#include <string>
#include <vector>

class MembershipProgram {
public:
  void enrollVisitor(const VisitorProfile &visitor);

  std::string membershipSnapshot() const;

private:
  int activeMembers = 0;
  double monthlyRevenue = 0.0;
  std::vector<std::string> tierNames = {};
};
