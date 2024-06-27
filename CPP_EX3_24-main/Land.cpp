// Land.cpp
#include "Land.hpp"
#include "Junction.hpp"

Land::Land(Junction* junction1, Junction* junction2, Junction* junction3, 
           Junction* junction4, Junction* junction5, Junction* junction6)
    : number(0), type("Empty"), junctions{junction1, junction2, junction3, junction4, junction5, junction6}
{
    // Validate that none of the junctions is null
    for (auto junction : junctions) {
        if (!junction) {
            throw std::invalid_argument("Junction pointer cannot be null");
        }
    }

    // Add this Land to each junction
    for (auto junction : junctions) {
        junction->addLand(this);
    }
}

void Land::setType(const std::string& name) {
    if (type == "Empty") { // Only allow changing type if it's currently "Empty"
        if(name == "Mountains" || name == "Forest" || name == "Farm" || name == "Fields" || name == "Hills" || name == "Desert") {
            type = name;
        } else {
            std::cerr << "Invalid type of land" << std::endl;
        }
    }
}
std::string Land::getType() const {
    return type;
}

void Land::setNumber(int num) {
    number = num;
}

int Land::getNumber() {
    return number;
}

const std::array<Junction*, 6>& Land::getJunctions() const {
    return junctions;
}
