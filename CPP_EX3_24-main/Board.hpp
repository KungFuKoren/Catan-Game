#ifndef BOARD_HPP
#define BOARD_HPP

#include <algorithm> // For std::shuffle
#include <random>    // For random number generation
#include <chrono>    // For seeding the random number generator
#include <vector>
#include "Land.hpp"
#include "Junction.hpp"
#include "Road.hpp" // Include Road.hpp here
#include "DevelopmentCard.hpp"

class Player;

class Board {
private:
    Board(); // Constructor for singleton
    ~Board(); // Destructor for singleton

    static Board* instance;
    std::vector<DevelopmentCard*> cards;
    std::vector<Land*> lands;
    std::vector<Junction*> junctions;
    std::vector<Road*> roads; // Now Road is recognized

    void setDevCards();
    void setLands();
    void createPlayers();
    void createBoard();
    void createJunctions();

public:
    static Board& getInstance();

    DevelopmentCard* giveCard();
    const std::vector<DevelopmentCard*>& getCards() const;
    const std::vector<Land*>& getLands() const;
    const std::vector<Junction*>& getJunctions() const;
    const std::vector<Road*>& getRoads() const;

    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
};

#endif // BOARD_HPP
