#include <gtest/gtest.h>
#include "domain/staff/RestorationSpecialist/RestorationSpecialist.h"

TEST(RestorationSpecialist, TreatsPainting) {
    RestorationSpecialist specialist;
    Painting painting;
    specialist.treatPainting(painting);
    EXPECT_NE(specialist.restorationNote().find("Restorer"), std::string::npos);
}