#pragma once

#include <memory>
#include <string>
class ExcursionPlan;

class ScenicRoute {
public:
  void configureScenicRoute(const std::shared_ptr<ExcursionPlan> &partner,
                            int delta);

  std::string describeScenicRoute() const;

private:
  std::string statusLabel = "ScenicRouteSeed";
  int priorityLevel = 1;
  std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;

  std::string internalNote() const;
};
