#include "domain/security/CameraNetwork/CameraNetwork.h"


void CameraNetwork::recalibrateAngles(int blindSpots) {
    zones.push_back("Blind-" + std::to_string(blindSpots));
    if (blindSpots >= activeCameras) {
        activeCameras = blindSpots + 1;
    }
    hdEnabled = blindSpots < 3;
}


std::string CameraNetwork::describeCoverage() const {
    return std::to_string(activeCameras) + " cams-" + (hdEnabled ? "HD" : "SD");
}