#include <iostream>
#include <typeinfo> // For typeid
#include "Board.hpp"
#include "Junction.hpp"
#include "Road.hpp"
#include "Land.hpp" // Include Land.hpp to use Land class
#include "Player.hpp"
#include "Catan.hpp"



int main() {
    

    // Create a player
    Player* play1 = new Player("Steve");
    Player* play2 = new Player("Reuven");
    Player* play3 = new Player("Manny");

    Catan* game = new Catan(play1 , play2 ,play3);
    
    Board* board = game->getBoard();
    const std::vector<Junction*> junctions = board->getJunctions();
    // play1->addBrick(2);
    // play1->addWood(2);
    // play1->addWheat(4);
    // play1->addSheep(1);
    // play1->addIron(3);

    // bool sett = play1->buySettelment(junctions[19] , board);
    // bool city = play1->buyCity(junctions[19]);
    // bool failcity = play1->buyCity(junctions[20]);
    // std::cout<< city << " now fail " << failcity << std::endl;
    // if(junctions[19]->getOccPlayer() != nullptr){
    //     std::cout<<junctions[19]->getOccPlayer()->getName()<<std::endl;

    // }
    // bool is = play1->buyRoad("Junction 19" , "Junction 20" , board);
    // std::cout<<is<<sett <<std::endl;

    game->startGame();
    game->turn();
    game->turn();
    game->turn();



    return 0;
}
