#include <gtest/gtest.h>
#include "domain/staff/Caretaker/Caretaker.h"

TEST(Caretaker, RefreshesPainting) {
    Caretaker caretaker;
    Painting painting;
    ExhibitHall exhibitHall;
    painting.configureDisplay(exhibitHall);
    caretaker.refreshPainting(painting);
    EXPECT_NE(caretaker.caretakerNote().find("Ready"), std::string::npos);
}