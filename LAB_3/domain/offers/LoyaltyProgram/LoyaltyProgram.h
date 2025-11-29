#pragma once

#include <memory>
#include <string>
class FrequentFlyerAccount;

class LoyaltyProgram {
public:
  void
  configureLoyaltyProgram(const std::shared_ptr<FrequentFlyerAccount> &partner,
                          int delta);

  void awardBonusMiles(int miles);

  std::string tier() const;

  std::string describeLoyaltyProgram() const;

private:
  std::string statusLabel = "LoyaltyProgramSeed";
  int priorityLevel = 1;
  std::shared_ptr<FrequentFlyerAccount> linkedPartner = nullptr;
};
