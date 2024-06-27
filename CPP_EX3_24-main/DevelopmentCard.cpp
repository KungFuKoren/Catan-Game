#include "DevelopmentCard.hpp"

// Implementation of DevelopmentCard

DevelopmentCard::DevelopmentCard() {
    // Constructor implementation (if needed)
}

DevelopmentCard::~DevelopmentCard() {
    // Virtual destructor implementation (if needed)
}

// Implementation of BonusPoint

BonusPoint::BonusPoint() {
    // Constructor implementation (if needed)
}

BonusPoint::BonusPoint(const BonusPoint& other) {
    // Copy constructor implementation (if needed)
}

DevelopmentCard* BonusPoint::clone() const {
    return new BonusPoint(*this); // Clone implementation
}

std::string BonusPoint::getType() const {
    return "BonusPoint"; // getType implementation
}

// Implementation of YearofPlenty

YearofPlenty::YearofPlenty() {
    // Constructor implementation (if needed)
}

YearofPlenty::YearofPlenty(const YearofPlenty& other) {
    // Copy constructor implementation (if needed)
}

DevelopmentCard* YearofPlenty::clone() const {
    return new YearofPlenty(*this); // Clone implementation
}

std::string YearofPlenty::getType() const {
    return "YearofPlenty"; // getType implementation
}

// Implementation of Knight

Knight::Knight() {
    // Constructor implementation (if needed)
}

Knight::Knight(const Knight& other) {
    // Copy constructor implementation (if needed)
}

DevelopmentCard* Knight::clone() const {
    return new Knight(*this); // Clone implementation
}

std::string Knight::getType() const {
    return "Knight"; // getType implementation
}

// Implementation of Monopoly

Monopoly::Monopoly() {
    // Constructor implementation (if needed)
}

Monopoly::Monopoly(const Monopoly& other) {
    // Copy constructor implementation (if needed)
}

DevelopmentCard* Monopoly::clone() const {
    return new Monopoly(*this); // Clone implementation
}

std::string Monopoly::getType() const {
    return "Monopoly"; // getType implementation
}

// Implementation of BuildRoads

BuildRoads::BuildRoads() {
    // Constructor implementation (if needed)
}

BuildRoads::BuildRoads(const BuildRoads& other) {
    // Copy constructor implementation (if needed)
}

DevelopmentCard* BuildRoads::clone() const {
    return new BuildRoads(*this); // Clone implementation
}

std::string BuildRoads::getType() const {
    return "BuildRoads"; // getType implementation
}
