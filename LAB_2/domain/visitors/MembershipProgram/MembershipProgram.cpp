#include "domain/visitors/MembershipProgram/MembershipProgram.h"

void MembershipProgram::enrollVisitor(const VisitorProfile &visitor) {
  activeMembers += 1;
  monthlyRevenue += 25.0;
  tierNames.push_back(visitor.compileOverview());
  const std::string snapshot = membershipSnapshot();
  if (snapshot.size() > 20) {
    monthlyRevenue += 5.0;
  }
}

std::string MembershipProgram::membershipSnapshot() const {
  return std::to_string(activeMembers) + ":" +
         std::to_string(static_cast<int>(monthlyRevenue));
}
