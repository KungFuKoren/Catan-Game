// Board.cpp
#include "Board.hpp"
#include "Junction.hpp"
#include "Road.hpp"
#include "Land.hpp"
#include "Player.hpp"
#include "DevelopmentCard.hpp"
//initialize singleton instance.
Board* Board::instance = nullptr;

Board::Board() {
    createJunctions();
    createBoard();
    setLands();
    setDevCards();
}

Board::~Board() {
    // Clean up allocated memory
    for (auto land : lands)
        delete land;
    for (auto junction : junctions)
        delete junction;
    for (auto road : roads)
        delete road;
    for(auto card : cards)
        delete card;
}
//creates singleton
Board& Board::getInstance(){
    if(!instance){
        instance = new Board();
    }
    return *instance;
}


void Board::createJunctions() {
    for (int i = 0; i < 54; ++i) {
        Junction* junction = new Junction("Junction" + std::to_string(i + 1));
        junctions.push_back(junction);
    }
}
DevelopmentCard* Board::giveCard() {
    if (!cards.empty()) {
        DevelopmentCard* lastCard = cards.back();
        cards.pop_back(); // Remove the last card from the vector
        DevelopmentCard* cardCopy = lastCard; // Create a new card copy
        delete lastCard; // Free the memory of the original card
        return cardCopy;
    } else {
        std::cout<<"Card stack is empty"<<std::endl;
        // Return nullptr when no cards are available
        return nullptr;
    }
}


void Board::setDevCards() {
    std::string cardType[13] = {"knight", "knight", "knight", "bonus", "bonus", "bonus", "bonus", "yop", "yop", "road", "road", "monopoly", "monopoly"};

    // Shuffle the card types
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::shuffle(std::begin(cardType), std::end(cardType), rng);

    // Clear existing cards if needed (ensure proper memory management)
    for (auto card : cards) {
        delete card; // Free memory of existing cards
    }
    cards.clear(); // Clear the vector

    // Populate cards vector based on shuffled cardType
    for (int i = 0; i < 13; ++i) {
        if (cardType[i] == "knight") {
            DevelopmentCard* card = new Knight();
            cards.push_back(card);
        } else if (cardType[i] == "bonus") {
            DevelopmentCard* card = new BonusPoint();
            cards.push_back(card);
        } else if (cardType[i] == "yop") {
            DevelopmentCard* card = new YearofPlenty();
            cards.push_back(card);
        } else if (cardType[i] == "road") {
            DevelopmentCard* card = new BuildRoads();
            cards.push_back(card);
        } else if (cardType[i] == "monopoly") {
            DevelopmentCard* card = new Monopoly();
            cards.push_back(card);
        }
    }
}

void Board::setLands() {
    int numbers[18] = {10, 2, 9, 12, 6, 4, 10, 9, 11, 3, 8, 8, 3, 4, 5, 5, 6, 11};
    std::string landType[19] = {"Hills", "Hills", "Hills", "Forest", "Forest", "Forest", "Forest", "Mountains",
                                "Mountains", "Mountains", "Farm", "Farm", "Farm", "Farm", "Fields", "Fields",
                                "Fields", "Fields", "Desert"};

    // Use current time as a seed for the random number generator
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);

    // Shuffle lands vector
    std::shuffle(std::begin(landType), std::end(landType), rng);
    // Shuffle numbers array
    std::shuffle(std::begin(numbers), std::end(numbers), rng);
    int j = 0;
    for(int i = 0 ; i < 19 ; i++){
        if(landType[i] == "Desert"){
            lands[i]->setType("Desert");
            lands[i]->setNumber(0);
            continue;
        }
        if(lands[i] != nullptr){
            lands[i]->setType(landType[i]);
            lands[i]->setNumber(numbers[j]);
        } 
        else {
            std::cerr << "Error: Land at index " << i << " is not initialized." << std::endl;
            }
        j++;
        }
       
}



void Board::createBoard(){

roads.push_back(new Road(junctions[0],junctions[13]));
roads.push_back(new Road(junctions[0],junctions[1]));
roads.push_back(new Road(junctions[1],junctions[2]));
roads.push_back(new Road(junctions[2],junctions[3]));
roads.push_back(new Road(junctions[3],junctions[4]));
roads.push_back(new Road(junctions[4],junctions[5]));
roads.push_back(new Road(junctions[5],junctions[6]));
roads.push_back(new Road(junctions[6],junctions[7]));
roads.push_back(new Road(junctions[7],junctions[8]));
roads.push_back(new Road(junctions[8],junctions[9]));
roads.push_back(new Road(junctions[9],junctions[10]));
roads.push_back(new Road(junctions[4],junctions[9]));
roads.push_back(new Road(junctions[1],junctions[11]));
roads.push_back(new Road(junctions[10],junctions[11]));
roads.push_back(new Road(junctions[11],junctions[12]));
roads.push_back(new Road(junctions[12],junctions[13]));
roads.push_back(new Road(junctions[13],junctions[14]));
roads.push_back(new Road(junctions[14],junctions[15]));
roads.push_back(new Road(junctions[15],junctions[16]));
roads.push_back(new Road(junctions[12],junctions[17]));
roads.push_back(new Road(junctions[16],junctions[17]));
roads.push_back(new Road(junctions[17],junctions[18]));
roads.push_back(new Road(junctions[10],junctions[19]));
roads.push_back(new Road(junctions[8],junctions[21]));
roads.push_back(new Road(junctions[7],junctions[22]));
roads.push_back(new Road(junctions[22],junctions[24]));
roads.push_back(new Road(junctions[23],junctions[24]));
roads.push_back(new Road(junctions[21],junctions[23]));
roads.push_back(new Road(junctions[20],junctions[21]));
roads.push_back(new Road(junctions[19],junctions[20]));
roads.push_back(new Road(junctions[18],junctions[19]));
roads.push_back(new Road(junctions[15],junctions[35]));
roads.push_back(new Road(junctions[35],junctions[36]));
roads.push_back(new Road(junctions[16],junctions[34]));
roads.push_back(new Road(junctions[18],junctions[32]));
roads.push_back(new Road(junctions[20],junctions[30]));
roads.push_back(new Road(junctions[23],junctions[28]));
roads.push_back(new Road(junctions[24],junctions[25]));
roads.push_back(new Road(junctions[25],junctions[26]));
roads.push_back(new Road(junctions[26],junctions[27]));
roads.push_back(new Road(junctions[28],junctions[27]));
roads.push_back(new Road(junctions[28],junctions[29]));
roads.push_back(new Road(junctions[29],junctions[30]));
roads.push_back(new Road(junctions[30],junctions[31]));
roads.push_back(new Road(junctions[31],junctions[32]));
roads.push_back(new Road(junctions[33],junctions[34]));
roads.push_back(new Road(junctions[33],junctions[34]));
roads.push_back(new Road(junctions[34],junctions[37]));
roads.push_back(new Road(junctions[37],junctions[38]));
roads.push_back(new Road(junctions[38],junctions[46]));
roads.push_back(new Road(junctions[33],junctions[39]));
roads.push_back(new Road(junctions[31],junctions[40]));
roads.push_back(new Road(junctions[29],junctions[41]));
roads.push_back(new Road(junctions[42],junctions[27]));
roads.push_back(new Road(junctions[42],junctions[43]));
roads.push_back(new Road(junctions[43],junctions[41]));
roads.push_back(new Road(junctions[44],junctions[41]));
roads.push_back(new Road(junctions[44],junctions[40]));
roads.push_back(new Road(junctions[45],junctions[40]));
roads.push_back(new Road(junctions[49],junctions[45]));
roads.push_back(new Road(junctions[45],junctions[39]));
roads.push_back(new Road(junctions[36],junctions[39]));
roads.push_back(new Road(junctions[37],junctions[36]));
roads.push_back(new Road(junctions[48],junctions[47]));
roads.push_back(new Road(junctions[49],junctions[48]));
roads.push_back(new Road(junctions[50],junctions[49]));
roads.push_back(new Road(junctions[50],junctions[51]));
roads.push_back(new Road(junctions[44],junctions[51]));
roads.push_back(new Road(junctions[52],junctions[51]));
roads.push_back(new Road(junctions[53],junctions[52]));
roads.push_back(new Road(junctions[53],junctions[43]));
roads.push_back(new Road(junctions[36],junctions[37]));







lands.push_back(new Land(junctions[39],junctions[46],junctions[47],junctions[48],junctions[49],junctions[45]));
lands.push_back(new Land(junctions[40],junctions[44],junctions[45],junctions[49],junctions[50],junctions[51]));
lands.push_back(new Land(junctions[41],junctions[43],junctions[44],junctions[51],junctions[52],junctions[53]));
lands.push_back(new Land(junctions[33],junctions[34],junctions[39],junctions[37],junctions[38],junctions[46]));
lands.push_back(new Land(junctions[31],junctions[32],junctions[33],junctions[39],junctions[40],junctions[45]));
lands.push_back(new Land(junctions[29],junctions[30],junctions[31],junctions[40],junctions[41],junctions[44]));
lands.push_back(new Land(junctions[27],junctions[28],junctions[29],junctions[41],junctions[42],junctions[43]));
lands.push_back(new Land(junctions[23],junctions[24],junctions[25],junctions[26],junctions[27],junctions[28]));
lands.push_back(new Land(junctions[20],junctions[21],junctions[23],junctions[28],junctions[29],junctions[30]));
lands.push_back(new Land(junctions[18],junctions[19],junctions[20],junctions[30],junctions[31],junctions[32]));
lands.push_back(new Land(junctions[16],junctions[17],junctions[18],junctions[32],junctions[33],junctions[34]));
lands.push_back(new Land(junctions[15],junctions[16],junctions[34],junctions[35],junctions[36],junctions[37]));
lands.push_back(new Land(junctions[12],junctions[13],junctions[14],junctions[15],junctions[16],junctions[17]));
lands.push_back(new Land(junctions[10],junctions[11],junctions[12],junctions[17],junctions[18],junctions[19]));
lands.push_back(new Land(junctions[8],junctions[9],junctions[10],junctions[19],junctions[20],junctions[21]));
lands.push_back(new Land(junctions[7],junctions[8],junctions[21],junctions[22],junctions[23],junctions[24]));
lands.push_back(new Land(junctions[0],junctions[1],junctions[2],junctions[11],junctions[12],junctions[13]));
lands.push_back(new Land(junctions[2],junctions[3],junctions[4],junctions[9],junctions[10],junctions[11]));
lands.push_back(new Land(junctions[4],junctions[5],junctions[6],junctions[7],junctions[8],junctions[9]));



















}
const std::vector<DevelopmentCard*>& Board::getCards() const {
    return cards;
}

const std::vector<Land*>& Board::getLands() const {
    return lands;
}

const std::vector<Junction*>& Board::getJunctions() const {
    return junctions;
}

const std::vector<Road*>& Board::getRoads() const {
    return roads;
}
