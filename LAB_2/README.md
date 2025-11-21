AccessPanel 3 2 → StaffMember, UnauthorizedAccessException
AlarmBeacon 3 2 → EmergencyExitControl
ArtworkCatalog 3 2 → Painting, Curator, InventoryTracker, ArtworkLoanAgreement
ArtworkLoanAgreement 3 2 → Painting, LoanAgreementException, InventoryTracker
ArtworkNotFoundException 3 2 → ArtworkCatalog, InventoryTracker
AudioGuide 3 2 → TourGuide, ITSupportSpecialist
CameraNetwork 3 2 → SecuritySystem, SecurityDrone
Caretaker 3 2 → StaffMember, CleaningSchedule, Painting, MaintenanceChief
Cashier 3 2 → StaffMember, DonationBox, MembershipProgram, PaymentProcessingException
CleaningSchedule 3 2 → Caretaker, MaintenanceChief
ClimateAlertException 3 2 → ClimateControl, MaintenanceChief
ClimateControl 3 2 → ExhibitHall, MaintenanceChief, Statue
Curator 3 2 → StaffMember, ArtworkCatalog, RestorationSpecialist
DonationBox 3 2 → Cashier, GiftShopManager
EducationOfficer 3 2 → StaffMember, VisitorProfile, EventCoordinator
EmergencyExitControl 3 2 → VisitorProfile, AlarmBeacon, VisitorLimitExceededException
EquipmentFailureException 3 2 → SecurityDrone, MaintenanceChief
EventCoordinator 3 2 → StaffMember, EventSchedule, EducationOfficer, SchedulingConflictException
EventSchedule 3 2 → EventCoordinator, EducationOfficer
ExhibitHall 3 2 → LightingSystem, ClimateControl, Painting, Caretaker
GalleryMap 3 2 → VisitorProfile, PatrolRoutePlanner
GiftShopManager 3 2 → DonationBox, Cashier
Guard 3 2 → StaffMember, PatrolRoutePlanner, IncidentLogger, SecuritySystem
IncidentLogger 3 2 → Guard, SecurityDrone, SecuritySystem
InvalidTicketException 3 2 → TicketingAgent, EventCoordinator
InventoryMismatchException 3 2 → InventoryTracker, Curator
InventoryTracker 3 2 → ArtworkCatalog, InventoryMismatchException, Curator, SecuritySystem
ITSupportSpecialist 3 2 → StaffMember, AudioGuide, MaintenanceChief
KeyCardLock 3 2 → Guard, SecuritySystem
LightingSystem 3 2 → ExhibitHall, MaintenanceChief
LoanAgreementException 3 2 → ArtworkLoanAgreement, InventoryTracker
MaintenanceChief 3 2 → StaffMember, SecuritySystem, MaintenanceDelayException
MaintenanceDelayException 3 2 → MaintenanceChief, SecuritySystem, Curator
MembershipProgram 3 2 → VisitorProfile, Cashier
MotionSensorGrid 3 2 → SecuritySystem, MaintenanceChief
Painting 3 2 → ExhibitHall, Caretaker, RestorationSpecialist
PatrolRoutePlanner 3 2 → GalleryMap, Guard
PaymentProcessingException 3 2 → Cashier, GiftShopManager
RestorationSpecialist 3 2 → StaffMember, Painting, Curator
SchedulingConflictException 3 2 → EventCoordinator, EducationOfficer
SecurityBreachException 3 2 → SecuritySystem, MaintenanceChief
SecurityDrone 3 2 → IncidentLogger, EquipmentFailureException, SecuritySystem
SecuritySystem 3 2 → CameraNetwork, MotionSensorGrid, Guard, SecurityBreachException, MaintenanceChief
StaffMember 3 2 → Guard, TourGuide, Cashier, Caretaker, Curator, EventCoordinator, RestorationSpecialist, MaintenanceChief, ITSupportSpecialist, EducationOfficer
Statue 3 2 → ClimateControl, Caretaker
TicketingAgent 3 2 → InvalidTicketException, EventSchedule
TourGuide 3 2 → StaffMember, AudioGuide, VisitorProfile
UnauthorizedAccessException 3 2 → AccessPanel, SecuritySystem, Guard
VisitorLimitExceededException 3 2 → VisitorProfile, EmergencyExitControl
VisitorProfile 3 2 → GalleryMap, MembershipProgram, EducationOfficer, EmergencyExitControl

ArtworkNotFoundException 3 2 → ArtworkCatalog, InventoryTracker
UnauthorizedAccessException 3 2 → AccessPanel, SecuritySystem, Guard
ClimateAlertException 3 2 → ClimateControl, MaintenanceChief
InvalidTicketException 3 2 → TicketingAgent, EventCoordinator
PaymentProcessingException 3 2 → Cashier, GiftShopManager
EquipmentFailureException 3 2 → SecurityDrone, MaintenanceChief
SchedulingConflictException 3 2 → EventCoordinator, EducationOfficer
InventoryMismatchException 3 2 → InventoryTracker, Curator
SecurityBreachException 3 2 → SecuritySystem, MaintenanceChief
VisitorLimitExceededException 3 2 → VisitorProfile, EmergencyExitControl
LoanAgreementException 3 2 → ArtworkLoanAgreement, InventoryTracker
MaintenanceDelayException 3 2 → MaintenanceChief, SecuritySystem, Curator

- Поля: 150
- Поведения: 100
- Ассоциации: 72
- Исключения: 12
