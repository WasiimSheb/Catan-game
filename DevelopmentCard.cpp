//Wasimshebalny@gmail.com
#include "DevelopmentCard.hpp"

namespace ariel {

DevelopmentCard::DevelopmentCard() {
  // Default constructor
}

DevelopmentCard::~DevelopmentCard() {
  // Virtual destructor
}

VictoryPoint::VictoryPoint() {
  // Default constructor for Victory Point card
}

DevelopmentCard *VictoryPoint::copyCard() const {
  // Creates a deep copy of the Victory Point card
  return new VictoryPoint(*this);
}

std::string VictoryPoint::getType() const {
  // Returns the type of the Victory Point card ("victory point card")
  return "victory point card";
}

YearOfPlenty::YearOfPlenty() {
  // Default constructor for Year of Plenty card
}

DevelopmentCard *YearOfPlenty::copyCard() const {
  // Creates a deep copy of the Year of Plenty card
  return new YearOfPlenty(*this);
}

std::string YearOfPlenty::getType() const {
  // Returns the type of the Year of Plenty card ("year of plenty card")
  return "year of plenty card";
}

Knight::Knight() {
  // Default constructor for Knight card
}

DevelopmentCard *Knight::copyCard() const {
  // Creates a deep copy of the Knight card
  return new Knight(*this);
}

std::string Knight::getType() const {
  // Returns the type of the Knight card ("knight card")
  return "knight card";
}

Monopoly::Monopoly() {
  // Default constructor for Monopoly card
}

DevelopmentCard *Monopoly::copyCard() const {
  // Creates a deep copy of the Monopoly card
  return new Monopoly(*this);
}

std::string Monopoly::getType() const {
  // Returns the type of the Monopoly card ("monopoly card")
  return "monopoly card";
}

RoadBuilding::RoadBuilding() {
  // Default constructor for Road Building card
}

DevelopmentCard *RoadBuilding::copyCard() const {
  // Creates a deep copy of the Road Building card
  return new RoadBuilding(*this);
}

std::string RoadBuilding::getType() const {
  // Returns the type of the Road Building card ("road building card")
  return "road building card";
}

} // namespace ariel
