#include "domain/partners/PartnerHotel/PartnerHotel.h"
#include "domain/resort/ResortProfile/ResortProfile.h"
#include <gtest/gtest.h>

TEST(PartnerHotel, ConfiguresAndDescribes) {
  PartnerHotel item;
  auto partner = std::make_shared<ResortProfile>();
  item.configurePartnerHotel(partner, 2);
  EXPECT_TRUE(!item.describePartnerHotel().empty());
}

TEST(PartnerHotel, SetsSeasonalRateAndConciergeLine) {
  PartnerHotel hotel;
  hotel.setSeasonalRate(3);
  EXPECT_NE(hotel.conciergeLine().find("vip"), std::string::npos);
}
