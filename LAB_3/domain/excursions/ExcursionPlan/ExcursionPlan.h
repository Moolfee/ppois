#pragma once

#include <string>
#include <memory>
class TourGuideProfile;

class ExcursionPlan {
public:
    
    void configureExcursionPlan(const std::shared_ptr<TourGuideProfile>& partner, int delta);

    
    std::string describeExcursionPlan() const;

private:
    std::string statusLabel = "ExcursionPlanSeed";
    int priorityLevel = 1;
    std::shared_ptr<TourGuideProfile> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
