
#include "Catan.hpp"

Catan::Catan(Player* player1, Player* player2, Player* player3) {
    players[0] = player1;
    players[1] = player2;
    players[2] = player3;
}

Player* Catan::getPlayer(int index) const {
    if (index >= 0 && index < 3) {
        return players[index];
    } else {
        return nullptr; // Index out of bounds
    }
}
Player* Catan::ChooseStartingPlayer(){
    return players[0];
}

Board* Catan::getBoard(){
    Board& board = Board::getInstance();
    return &board;
    }

void Catan::startGame(){
    std::string junc;
    std::string junc1;
    std::string junc2;
    Board* board = getBoard();
    const std::vector<Junction*>& junctions = board->getJunctions();

    for(Player* player : players){
        std::cout<<player->getName() << " Turn to choose"<<std::endl;
        bool flagA = false;
        bool flagB = false;
        while(!flagA && !flagB){

            std::cout<<player->getName() << " Place 2 settlements and roads"<<std::endl;
            std::cout<<"Pick first Junction"<<std::endl;
            std::cin>>junc;
            flagA = player->placeSettlement(junc , board);
            if(flagA){
                for(Junction* junction : junctions){
                    if(junction->getId() == junc){
                        const std::vector<Land*>& lands = junction->getLands();
                        for(Land* land : lands){
                            if(land->getType() == "Mountains"){
                                player->addIron(1);
                            }
                            if(land->getType() == "Forest"){
                                player->addWood(1);
                            }
                            if(land->getType() == "Farm"){
                                player->addSheep(1);
                            }
                            if(land->getType() == "Fields"){
                                player->addWheat(1);
                            }
                            if(land->getType() == "Hills"){
                                player->addBrick(1);
                            }
                        }
                    }
                }
            }
            
            std::cout<<"Place a road next to the settlement"<<std::endl;
            std::cout<<"Enter two Junctions"<<std::endl;
            std::cin>>junc1;
            
            std::cout<<"Enter second junction"<<std::endl;
            std::cin>>junc2;
             flagB = player->placeRoad(junc1 , junc2 ,board);
        }
        flagA = false;
        flagB = false;            
        while(!flagA && !flagB){

            std::cout<<"Pick Second Junction"<<std::endl;
            std::cin>>junc;
            flagA = player->placeSettlement(junc , board);
            if(flagA){
                for(Junction* junction : junctions){
                    if(junction->getId() == junc){
                        const std::vector<Land*>& lands = junction->getLands();
                        for(Land* land : lands){
                            if(land->getType() == "Mountains"){
                                player->addIron(1);
                            }
                            if(land->getType() == "Forest"){
                                player->addWood(1);
                            }
                            if(land->getType() == "Farm"){
                                player->addSheep(1);
                            }
                            if(land->getType() == "Fields"){
                                player->addWheat(1);
                            }
                            if(land->getType() == "Hills"){
                                player->addBrick(1);
                            }
                        }
                    }
                }
            }
            
            std::cout<<"Place a road next to the settlement"<<std::endl;
            std::cout<<"Enter two Junctions"<<std::endl;
            std::cin>>junc;
            std::cout<<"Enter second junction"<<std::endl;
            std::cin>>junc1;
            flagB = player->placeRoad(junc , junc1 ,board);
        }    
    }
}
Player* Catan::getPlaying() {
    // Static variable to keep track of the current player's index
    static int currentPlayerIndex = 0;

    // Get the current player
    Player* currentPlayer = players[currentPlayerIndex];

    // Move to the next player
    currentPlayerIndex = (currentPlayerIndex + 1) % 3; // Assuming 3 players

    return currentPlayer;
}


void Catan::turn(){
    int number = rollDice();
    std::cout<<"Number rolled : " << number<<std::endl;
    Player* player = getPlaying();
    Board* board  = getBoard();
    const std::vector<Land*>& lands = board->getLands();
    for(Land* land : lands){
        if(land->getNumber() == number ){
            const std::array<Junction*, 6>& junctions = land->getJunctions();
            for(Junction* junc : junctions){
                if(junc->isOccupied()){
                    if(junc->getType() == "Village"){
                        if(land->getType() == "Mountains"){
                            junc->getOccPlayer()->addIron(1);
                        }
                        if(land->getType() == "Forest"){
                            junc->getOccPlayer()->addWood(1);
                        }
                        if(land->getType() == "Farm"){
                            junc->getOccPlayer()->addSheep(1);
                        }
                        if(land->getType() == "Fields"){
                            junc->getOccPlayer()->addWheat(1);
                        }
                        if(land->getType() == "Hills"){
                            junc->getOccPlayer()->addBrick(1);
                        }
                    }
                    if(junc->getType() == "City"){
                        if(land->getType() == "Mountains"){
                            junc->getOccPlayer()->addIron(2);
                        }
                        if(land->getType() == "Forest"){
                            junc->getOccPlayer()->addWood(2);
                        }
                        if(land->getType() == "Farm"){
                            junc->getOccPlayer()->addSheep(2);
                        }
                        if(land->getType() == "Fields"){
                            junc->getOccPlayer()->addWheat(2);
                        }
                        if(land->getType() == "Hills"){
                            junc->getOccPlayer()->addBrick(2);
                        }
                    }
                }
            }
        }
    }
    std::cout<<player->getName() << " Choose what to do:" << std::endl;
    bool active = true;
    while(active){
        int num = 0;
        if(player->getBrick() >= 1 && player->getWood() >= 1){
            std::cout<<"You can buy a road"<<std::endl;
            std::cout<<"Press 1 to buy a Road 0 otherwise"<<std::endl;
            std::cin>>num;
            if(num == 1){
                std::string junc1;
                std::string junc2;
                std::cout<< "enter two junctions to create a road"<<std::endl;
                std::cin>>junc1;
                std::cin>>junc2;
                
                if(player->buyRoad(junc1 , junc2 , board)){
                    num = 0;
                    continue;
                }
                else{
                    std::cout<<"Couldnt place road"<<std::endl;
                }
                num = 0;
            }

        }
        if(player->getBrick() >= 1 && player->getWood() >= 1 && player->getWheat() >= 1 && player->getSheep() >=1){
            std::cout<<"You can buy a Village"<<std::endl;
            std::cout<<"Press 2 to buy a Vilage 0 otherwise"<<std::endl;
            std::cin>>num;
            if(num == 2){
                std::string junc1;
                std::cout<<"Enter a junction for a village"<<std::endl;
                std::cin>>junc1;
                Junction* junc = getJunction(board , junc1);
                if(junc != nullptr){
                    if(player->buySettelment(junc , board)){
                        std::cout<<"Village was placed"<<std::endl;
                        num =0;
                        continue;
                    }
                }
                else{
                    std::cout<<"couldnt place road"<<std::endl;
                }
            num = 0;
            }

        }
        if(player->getWheat() >= 1 && player->getSheep() >=1 && player->getIron() >= 1){
            std::cout<<"You can buy a Development Card"<<std::endl;
            std::cout<<"Press 3 to buy a Card 0 otherwise"<<std::endl;
            std::cin>>num;
            if(num == 3){
                if(player->buyDevCard(board)){
                    num = 0;
                    continue;
                }
            }
            num = 0;
        }
        if(player->getWheat() >= 2 && player->getIron() >=3){
            std::cout<<"You can upgrade to a City"<<std::endl;
            std::cout<<"Press 4 to buy a City 0 otherise"<<std::endl;
            std::cin>>num;
            std::string junc1;
            std::cout<<"Enter a junction for a village"<<std::endl;
            std::cin>>junc1;
            Junction* junc = getJunction(board , junc1);
            if(num == 4){
                if(player->buyCity(junc)){
                    num = 0;
                    continue;
                }
            }
            std::cout<<"Coulndt place City"<<std::endl;
            num = 0;
        }
        int doYou;
        std::cout<<"if you wish to end your turn press 1"<<std::endl;
        std::cin>>doYou;
        if(doYou == 1){
            active = false;
        }
       



    }
    

}
Junction* Catan::getJunction(Board* board , std::string id){
    const std::vector<Junction*> junctions = board->getJunctions();
    for(Junction* junction : junctions){
        if(junction->getId() == id){
            return junction;
        }
    }
    return nullptr;
}

int Catan::rollDice(){
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(0)));
    
    // Roll two dice
    int die1 = (std::rand() % 6) + 1;
    int die2 = (std::rand() % 6) + 1;
    
    // Return the sum of the two dice
    return die1 + die2;
}

bool Catan::gameEnded(){
    for(Player* playerA : players){
        if(playerA->getPoints() == 10){
            std::cout<<"Game ended player "<< playerA->getName() << " Won"<<std::endl;
            return true; 
        }
    }
    return false;
}