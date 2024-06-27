#ifndef CATAN_HPP
#define CATAN_HPP
#include <regex> 
#include <cstdlib>   // For std::rand() and std::srand()
#include <ctime>     // For std::time()
#include <iostream>

#include "Board.hpp"
#include "Junction.hpp"
#include "Road.hpp"
#include "Land.hpp"
#include "DevelopmentCard.hpp"
#include "Player.hpp" // Assuming Player class is defined

class Catan {
private:
    Player* players[3]; // Array to hold 3 players
    int rollDice();
    Player* getPlaying();
    Junction* getJunction(Board* board , std::string id);

public:
    Catan(Player* player1, Player* player2, Player* player3); // Constructor
    Player* ChooseStartingPlayer();
    Player* getPlayer(int index) const; // Getter for individual players
    Board* getBoard();
    void startGame();
    void turn();
    bool gameEnded();


    
};

#endif // CATAN_HPP