#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>

// Abstract base class representing a generic development card
class DevelopmentCard {
public:
    // Default constructor
    DevelopmentCard();

    // Virtual destructor ensures derived class destructors are called
    virtual ~DevelopmentCard();

    // Pure virtual function for cloning a card (Prototype Pattern)
    virtual DevelopmentCard* clone() const = 0;

    // Pure virtual function to get the type of the card
    virtual std::string getType() const = 0;

    // Prevent copy construction
    DevelopmentCard(const DevelopmentCard&) = delete;

    // Prevent copy assignment
    DevelopmentCard& operator=(const DevelopmentCard&) = delete;
};

// Derived class representing a specific type of development card: BonusPoint
class BonusPoint : public DevelopmentCard {
public:
    // Constructor
    BonusPoint();

    // Copy constructor
    BonusPoint(const BonusPoint& other);

    // Implements the clone method
    DevelopmentCard* clone() const override;

    // Implements the getType method
    std::string getType() const override;
};

// Derived class representing a specific type of development card: YearofPlenty
class YearofPlenty : public DevelopmentCard {
public:
    // Constructor
    YearofPlenty();

    // Copy constructor
    YearofPlenty(const YearofPlenty& other);

    // Implements the clone method
    DevelopmentCard* clone() const override;

    // Implements the getType method
    std::string getType() const override;
};

// Derived class representing a specific type of development card: Knight
class Knight : public DevelopmentCard {
public:
    // Constructor
    Knight();

    // Copy constructor
    Knight(const Knight& other);

    // Implements the clone method
    DevelopmentCard* clone() const override;

    // Implements the getType method
    std::string getType() const override;
};

// Derived class representing a specific type of development card: Monopoly
class Monopoly : public DevelopmentCard {
public:
    // Constructor
    Monopoly();

    // Copy constructor
    Monopoly(const Monopoly& other);

    // Implements the clone method
    DevelopmentCard* clone() const override;

    // Implements the getType method
    std::string getType() const override;
};

// Derived class representing a specific type of development card: BuildRoads
class BuildRoads : public DevelopmentCard {
public:
    // Constructor
    BuildRoads();

    // Copy constructor
    BuildRoads(const BuildRoads& other);

    // Implements the clone method
    DevelopmentCard* clone() const override;

    // Implements the getType method
    std::string getType() const override;
};

#endif // DEVELOPMENT_CARD_HPP
