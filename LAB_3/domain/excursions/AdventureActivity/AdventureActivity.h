#pragma once

#include <memory>
#include <string>
class TouristProfile;

class AdventureActivity {
public:
  void
  configureAdventureActivity(const std::shared_ptr<TouristProfile> &partner,
                             int delta);

  std::string describeAdventureActivity() const;

private:
  std::string statusLabel = "AdventureActivitySeed";
  int priorityLevel = 1;
  std::shared_ptr<TouristProfile> linkedPartner = nullptr;

  std::string internalNote() const;
};
