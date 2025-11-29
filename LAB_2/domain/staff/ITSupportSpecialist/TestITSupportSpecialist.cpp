#include "domain/staff/ITSupportSpecialist/ITSupportSpecialist.h"
#include <gtest/gtest.h>

TEST(ITSupportSpecialist, PatchesAudioGuide) {
  ITSupportSpecialist specialist;
  AudioGuide audioGuide;
  specialist.patchAudioGuide(audioGuide);
  EXPECT_NE(specialist.supportDigest().find("tickets"), std::string::npos);
}
