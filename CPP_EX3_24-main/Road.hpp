#ifndef ROAD_HPP
#define ROAD_HPP

// Forward declare necessary classes
class Junction;
class Player;

class Road {
private:
    Junction* sideA;
    Junction* sideB;
    bool isFree;
    Player* occPlayer;

public:
    Road(Junction* sideA, Junction* sideB, bool isFree = true);
    Junction* getSideA() const;
    Junction* getSideB() const;
    bool isRoadFree() const;
    void setOccupied(Player* player);
    Player* getOccPlayer() const;

    // Add operator== to compare two Road objects
    bool operator==(const Road& other) const;
};

#endif // ROAD_HPP
