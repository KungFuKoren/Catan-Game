// Junction.cpp
#include "Junction.hpp"
#include "Road.hpp"
#include <iostream>

Junction::Junction(const std::string& id) : id(id), type("EMPTY"), occPlayer(nullptr) {}

const std::string& Junction::getId() const {
    return id;
}

void Junction::addLand(Land* land) {
    if (lands.size() < 3) {
        lands.push_back(land);
    } else {
        std::cerr << "Error: Junction already connected to maximum number of lands." << std::endl;
    }
}

const std::vector<Land*>& Junction::getLands() const {
    return lands;
}

void Junction::addRoad(Road* road) {
    bool found = false;
    for (Road* r : roads) {
        if (r == road) {
            found = true;
            break;
        }
    }
    if (!found) {
        if (roads.size() < 3) {
            roads.push_back(road);
        } 
    } else {
        std::cerr << "Error: Road is already connected to this junction." << std::endl;
    }
}

const std::vector<Road*>& Junction::getRoads() const {
    return roads;
}

bool Junction::isOccupied() const {
    return occPlayer != nullptr;
}

void Junction::setOccupied(Player* player) {
    if (occPlayer == nullptr) {
        setVillage();
        player->addPoints(1);
        occPlayer = player;
    } else {
        std::cerr << "Already occupied" << std::endl;
    }
}

Player* Junction::getOccPlayer() const {
    if(isOccupied()){
         return occPlayer;
    }
    return nullptr;
}

const std::string& Junction::getType() const {
    return type;
}

void Junction::setVillage() {
    type = "Village";
}

void Junction::setCity(Player* player) {
    if (getOccPlayer() == player) {
        if (type == "Village") {
            type = "City";
            player->addPoints(1);
        }
    } else {
        std::cerr << "Can't upgrade" << std::endl;
    }
}
