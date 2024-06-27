#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "DevelopmentCard.hpp"
#include "Junction.hpp"
#include "Board.hpp" // Ensure Board is included
#include "Land.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <limits.h>

class Land; // Forward declare Land
class Board; // Forward declare Board

class Player {
public:
    // Constructor
    explicit Player(const std::string& name);

    // Comparison operator
    bool operator==(const Player& other) const;

    // Getter for player's name
    const std::string& getName() const;

    // Resource methods
    int getWheat() const;
    int getSheep() const;
    int getIron() const;
    int getBrick() const;
    int getWood() const;
    void addWheat(int amount);
    void addSheep(int amount);
    void addIron(int amount);
    void addBrick(int amount);
    void addWood(int amount);
    void addKnight(int amount);

    // Points methods
    int getPoints() const;
    void addPoints(int amount);
    bool placeSettlement(const std::string& id, Board* board);
    bool placeRoad(const std::string& idA, const std::string& idB, Board* board);
    bool buySettelment(Junction* junc, Board* board);
    bool buyCity(Junction* junc);
    bool buyRoad(const std::string& A, const std::string& B, Board* board);
    bool buyDevCard(Board* board);
    void tooManyCards();

    // Development card methods
    int getDevelopmentCardCount() const;
    void addDevelopmentCard(DevelopmentCard* card);
    const std::vector<DevelopmentCard*>& getDevelopmentCards() const;

    // Methods for owned lands
    void addOwnedLand(Land* land);
    const std::vector<Land*>& getOwnedLands() const;

    // Destructor
    ~Player();

private:
    std::string name;
    std::vector<Land*> ownedLands;
    int wheat;
    int sheep;
    int iron;
    int brick;
    int wood;
    int points;
    int knights;
    std::vector<DevelopmentCard*> developmentCards; // Store development cards
};

#endif // PLAYER_HPP
