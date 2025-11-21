#include <gtest/gtest.h>
#include "domain/staff/TourGuide/TourGuide.h"

TEST(TourGuide, ConductsTour) {
    TourGuide tourGuide;
    VisitorProfile visitorProfile;
    tourGuide.conductTour(visitorProfile);
    EXPECT_NE(tourGuide.narrativeBeat().find("groups"), std::string::npos);
}