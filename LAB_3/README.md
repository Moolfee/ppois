TravelAgencyProfile 3 2 → TravelPolicy  
BranchOffice 3 2 → TravelAgencyProfile  
MarketingCampaign 3 2 → LoyaltyProgram  
PartnerAirline 3 2 → FlightTicket  
PartnerHotel 3 2 → ResortProfile  
ExperienceBundle 3 2 → ExcursionPlan  
LoyaltyProgram 3 2 → FrequentFlyerAccount  
ScheduleBoard 3 2 → TrainPass  
TravelPolicy 3 2 → ComplianceOfficer  
EmployeeProfile 3 2 → TravelAgencyProfile  
TravelAgent 3 2 → TouristProfile  
TourGuideProfile 3 2 → ExcursionPlan  
AgencyManager 3 2 → BranchOffice  
HotelManager 3 2 → PartnerHotel  
AirlineManager 3 2 → PartnerAirline  
TransportCoordinator 3 2 → AirportTransfer  
ComplianceOfficer 3 2 → TravelPolicy  
TouristProfile 3 2 → InsurancePlan  
FamilyBooking 3 2 → TravelAgent  
CorporateClient 3 2 → Invoice  
SoloBackpacker 3 2 → ExcursionPlan  
InsurancePlan 3 2 → TravelPolicy  
VisaApplication 3 2 → TravelAgent  
FrequentFlyerAccount 3 2 → PartnerAirline  
ResortProfile 3 2 → ResortRoom  
ResortRoom 3 2 → MealPlan  
MealPlan 3 2 → PartnerHotel  
ExcursionPlan 3 2 → TourGuideProfile  
ScenicRoute 3 2 → ExcursionPlan  
CulturalWorkshop 3 2 → TourGuideProfile  
AdventureActivity 3 2 → TouristProfile  
CruisePackage 3 2 → MealPlan  
AirportTransfer 3 2 → FlightTicket  
CityPass 3 2 → ExcursionPlan  
FlightTicket 3 2 → TravelAgent  
TrainPass 3 2 → TravelAgent  
PaymentGateway 3 2 → Invoice  
Invoice 3 2 → PaymentGateway  

## Исключения (12)
BookingConflictException 3 2 → ScheduleBoard, TravelAgent  
PaymentFailureException 3 2 → PaymentGateway, Invoice  
PassportValidationException 3 2 → VisaApplication, TravelAgent  
SeatUnavailableException 3 2 → FlightTicket, TrainPass  
WeatherCancellationException 3 2 → ScenicRoute, CruisePackage  
ResortOverbookingException 3 2 → ResortProfile, BranchOffice  
GuideUnavailableException 3 2 → TourGuideProfile, ExcursionPlan  
VehicleBreakdownException 3 2 → AirportTransfer, TransportCoordinator  
HealthClearanceException 3 2 → AdventureActivity, InsurancePlan  
VisaDenialException 3 2 → VisaApplication, TouristProfile  
LostLuggageException 3 2 → PartnerAirline, AirportTransfer  
PolicyBreachException 3 2 → ComplianceOfficer, TravelPolicy  

- Поля: 150
- Поведения: 100
- Ассоциации: 50
- Исключения: 12
