// Junction.hpp
#ifndef JUNCTION_HPP
#define JUNCTION_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Road.hpp"
#include "Land.hpp"
#include "Player.hpp"
class Player;
class Road; // Forward declaration

class Junction {
private:
    std::string id;
    std::string type;
    std::vector<Land*> lands;
    std::vector<Road*> roads;
    Player* occPlayer;
    void setVillage();

public:
    Junction(const std::string& id);
    const std::string& getId() const;
    void addLand(Land* land);
    const std::vector<Land*>& getLands() const;
    void addRoad(Road* road);
    const std::vector<Road*>& getRoads() const;
    bool isOccupied() const;
    void setOccupied(Player* player);
    Player* getOccPlayer() const;
     const std::string& getType() const;
     
     void setCity(Player* player);
};

#endif // JUNCTION_HPP
