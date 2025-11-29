#pragma once

#include <memory>
#include <string>
class MealPlan;

class ResortRoom {
public:
  void configureResortRoom(const std::shared_ptr<MealPlan> &partner, int delta);

  std::string describeResortRoom() const;

private:
  std::string statusLabel = "ResortRoomSeed";
  int priorityLevel = 1;
  std::shared_ptr<MealPlan> linkedPartner = nullptr;

  std::string internalNote() const;
};
