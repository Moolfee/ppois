#include <gtest/gtest.h>
#include "domain/staff/ITSupportSpecialist/ITSupportSpecialist.h"

TEST(ITSupportSpecialist, PatchesAudioGuide) {
    ITSupportSpecialist specialist;
    AudioGuide audioGuide;
    specialist.patchAudioGuide(audioGuide);
    EXPECT_NE(specialist.supportDigest().find("tickets"), std::string::npos);
}