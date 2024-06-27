// Road.cpp
#include "Road.hpp"
#include "Junction.hpp"

Road::Road(Junction* sideA, Junction* sideB, bool isFree) 
    : sideA(sideA), sideB(sideB), isFree(isFree) ,occPlayer(nullptr) 
{
    // Validate that neither junction is null
    if (!sideA || !sideB) {
        throw std::invalid_argument("Junction pointers cannot be null");
    }

    // Add this road to the junctions
    sideA->addRoad(this);
    sideB->addRoad(this);
}

Junction* Road::getSideA() const {
    return sideA;
}

Junction* Road::getSideB() const {
    return sideB;
}

bool Road::isRoadFree() const {
    return isFree;
}
void Road::setOccupied(Player* player){
    if(isFree && (sideA->getOccPlayer() == player || sideB->getOccPlayer() == player )){
        isFree = false;
        occPlayer = player;
    }
}
Player* Road::getOccPlayer() const{
    return occPlayer;
}


bool Road::operator==(const Road& other) const {
    // Ensure both sides of the roads match regardless of order
    return (sideA == other.sideA && sideB == other.sideB) || (sideA == other.sideB && sideB == other.sideA);
}
