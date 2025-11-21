#pragma once

#include <string>
#include <memory>
class TravelAgent;

class TrainPass {
public:
    
    void configureTrainPass(const std::shared_ptr<TravelAgent>& partner, int delta);

    
    std::string describeTrainPass() const;

private:
    std::string statusLabel = "TrainPassSeed";
    int priorityLevel = 1;
    std::shared_ptr<TravelAgent> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
