#include "Player.hpp"
#include "Land.hpp"
#include "DevelopmentCard.hpp"

// Constructor initializing the player with a name and setting resources to zero
Player::Player(const std::string& name)
    : name(name), wheat(0), sheep(0), iron(0), brick(0), wood(0), points(0), knights(0) {
}

// Destructor to clean up dynamically allocated development cards
Player::~Player() {
    for (DevelopmentCard* card : developmentCards) {
        delete card; // Free each dynamically allocated DevelopmentCard
    }
}

// Getter for player's name
const std::string& Player::getName() const {
    return name;
}

// Resource getter methods
int Player::getWheat() const {
    return wheat;
}

int Player::getSheep() const {
    return sheep;
}

int Player::getIron() const {
    return iron;
}

int Player::getBrick() const {
    return brick;
}

int Player::getWood() const {
    return wood;
}

// Resource addition methods
void Player::addWheat(int amount) {
    wheat += amount;
}

void Player::addSheep(int amount) {
    sheep += amount;
}

void Player::addIron(int amount) {
    iron += amount;
}

void Player::addBrick(int amount) {
    brick += amount;
}

void Player::addWood(int amount) {
    wood += amount;
}

// Points methods
int Player::getPoints() const {
    return points;
}

void Player::addPoints(int amount) {
    points += amount;
}

// Development card methods
int Player::getDevelopmentCardCount() const {
    return developmentCards.size(); // Return the number of development cards
}

void Player::addDevelopmentCard(DevelopmentCard* card) {
    developmentCards.push_back(card); // Add a development card to the vector
}

const std::vector<DevelopmentCard*>& Player::getDevelopmentCards() const {
    return developmentCards; // Return a const reference to the development cards vector
}

// Land management methods
void Player::addOwnedLand(Land* land) {
    ownedLands.push_back(land); // Add a land to the vector of owned lands
}

const std::vector<Land*>& Player::getOwnedLands() const {
    return ownedLands; // Return a const reference to the vector of owned lands
}

// Comparison operator
bool Player::operator==(const Player& other) const {
    return name == other.getName(); // Compare players by name
}


bool Player::placeSettlement(const std::string& id, Board* board) {
    const std::vector<Junction*> junctions = board->getJunctions();
    for(Junction* junction : junctions){
        if(junction->getId() == id && !junction->isOccupied()){
            const std::vector<Road*> roads = junction->getRoads();
            bool isOcc = false;
            for(Road* road : roads){
                if(road->getSideA()->isOccupied() || road->getSideB()->isOccupied()){
                    std::cout<<road->getSideA()->isOccupied()<< "AND" << road->getSideB()->isOccupied() << std::endl;
                    isOcc = true;
                    
                }
            }
            if(!isOcc){
                junction->setOccupied(this);
                return true;
            }
            else{
                std::cout<<"Cant place settlement - occupied junctions near"<<std::endl;
            }            
        }
        

    }
    return false;
}

bool Player::placeRoad(const std::string& idA, const std::string& idB, Board* board){
    const std::vector<Junction*> junctions = board->getJunctions();
    Junction* A;
    Junction* B;
    for(Junction* junction : junctions){
        if(junction->getId() == idA){
            A = junction;
        }
        if(junction->getId() == idB){
            B = junction;
        }
    }
    const std::vector<Road*> roads = board->getRoads();
    for(Road* road : roads){
        if((road->getSideA() == A && road->getSideB() == B) ||(road->getSideA() == B && road->getSideB() == A)){
            if(road->isRoadFree()){
               road->setOccupied(this);
                return true;

            }
        }
        const std::vector<Road*> junA = road->getSideA()->getRoads();
        const std::vector<Road*> junB = road->getSideB()->getRoads();
        // bool canPlace = false;
        for(Road* roadA : junA){
            if(roadA->getOccPlayer() == this && road->isRoadFree()){
                road->setOccupied(this);
                return true;
            }
        }
        for(Road* roadB : junB){
            if(roadB->getOccPlayer() == this && road->isRoadFree()){
                road->setOccupied(this);
                return true;
            }
        }
    }
    std::cout<<"Couldnt place road"<<std::endl;
    return false;
}
bool Player::buyRoad(const std::string& A, const std::string& B, Board* board){
    if(this->getWood() >= 1 && this->getBrick() <= 1){
        bool tryToPlace = placeRoad(A , B , board);
        if(tryToPlace){
            this->addBrick(-1);
            this->addWood(-1);
        }
        if(tryToPlace){
            return true;
        }
    }
    else{
        std::cout<<"not Enough resources"<<std::endl;
    }
    return false;
}

bool Player::buySettelment (Junction* junc , Board* board){
    if(this->getSheep() >= 1 && this->getBrick() >=  1 && this->getWood() >= 1 && this->getWheat() >=1){
        bool tryToPlace = placeSettlement(junc->getId() , board);
        std::cout<<tryToPlace<<std::endl;
        if(tryToPlace){
            this->addWheat(-1);
            this->addSheep(-1);
            this->addWood(-1);
            this->addBrick(-1);
            return true;
        }
    }
    else{
         std::cout<<"not Enough resources"<<std::endl;
    }
        return false;
}

bool Player::buyCity(Junction* junc){
    if(this->getIron() >= 3 && this->getWheat() >= 2 && junc->isOccupied()){
        if(junc->getOccPlayer() == this){
            junc->setCity(this);
            this->addIron(-3);
            this->addWheat(-2);
            return true;
        }
    }
    return false;
}
void Player::addKnight(int amount){
    knights += amount;
}

bool Player::buyDevCard(Board* board){
    DevelopmentCard* newCard = board->giveCard();
    if(this->getIron() >= 1 && this->getSheep() >= 1 && this->getWheat() >= 1 && newCard != nullptr){
        this->addSheep(-1);
        this->addIron(-1);
        this->addWheat(-1);
        if(newCard->getType() == "BonusPoint" ){
            this->addPoints(1);
        }
        if(newCard->getType() == "Knight"){
            addKnight(1);
        }
        return true;
    }
    std::cout<<"Couldnt buy card"<<std::endl;
    return false;

}

void Player::tooManyCards(){
    int wool = this->getSheep();
    int brick = this->getBrick();
    int wood = this->getWood();
    int iron = this->getIron();
    int wheat = this->getWheat();

    int numWool;
    int numBrick;
    int numWood;
    int numIron;
    int numWheat;


    int sum = wool + brick + wood + iron + wheat;
    int howMany = sum/2;
    bool flag = false;
    if(sum > 7){
        while(!flag){
            std::cout<<"Please pick " << howMany << " Cards to throw"<<std::endl;
            std::cout<<"You have " << wool << " Wool , How many would you like to throw?"<<std::endl;
            std::cin >> numWool;
            std::cout<<"You have " << brick << " Brick , How many would you like to throw?"<<std::endl;
            std::cin >> numBrick;
            std::cout<<"You have " << wood << " Wood , How many would you like to throw?"<<std::endl;
            std::cin >> numWood;
            std::cout<<"You have " << iron << " Iron , How many would you like to throw?"<<std::endl;
            std::cin >> numIron;
            std::cout<<"You have " << wheat << " Wheat , How many would you like to throw?"<<std::endl;
            std::cin >> numWheat;

            if(numBrick + numIron + numWheat + numWood +numWool == howMany && numBrick <= brick && numIron <=iron && numWheat <= wheat && numWood <= wood && numWool<= wool){
                flag = true;
                this->addBrick(-numBrick);
                this->addSheep(-numWool);
                this->addWood(-numWood);
                this->addIron(-numIron);
                this->addWheat(-numWheat);
                std::cout<<"Cards dropped"<<std::endl;
            }
            else{
                std::cout<<"Didnt drop enough or wrong input , try again !"<<std::endl;
            }
        }
        
    }
    
}


