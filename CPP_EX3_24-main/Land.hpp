#ifndef LAND_HPP
#define LAND_HPP

#include <string>
#include <array>
#include <cstddef>
#include <stdexcept>

class Junction; // Forward declaration

class Land {
public:
    // Constructor that takes exactly 6 Junction pointers
    Land(Junction* junction1, Junction* junction2, Junction* junction3, 
         Junction* junction4, Junction* junction5, Junction* junction6);

    void setNumber(int num);
    int getNumber();

    std::string getType() const;
    void setType(const std::string& type);
    
    // Immutable operation: Cannot modify junctions
    const std::array<Junction*, 6>& getJunctions() const;

private:
    int number;
    std::string type;
    std::array<Junction*, 6> junctions; // Fixed-size array of junction pointers
};

#endif // LAND_HPP
