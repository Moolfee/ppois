#pragma once

#include <memory>
#include <string>
class ExcursionPlan;

class SoloBackpacker {
public:
  void configureSoloBackpacker(const std::shared_ptr<ExcursionPlan> &partner,
                               int delta);

  std::string describeSoloBackpacker() const;

private:
  std::string statusLabel = "SoloBackpackerSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;
};
