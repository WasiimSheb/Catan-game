//Wasimshebalny@gmail.com
#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>

namespace ariel {

class DevelopmentCard {
public:
  DevelopmentCard(); // Default constructor
  virtual ~DevelopmentCard(); // Virtual destructor

  virtual DevelopmentCard *copyCard() const = 0; // Creates and returns a new instance of the same type as the calling object
  virtual std::string getType() const = 0; // Returns the type of the card
};

class VictoryPoint : public DevelopmentCard {
public:
  VictoryPoint(); // Default constructor for Victory Point card
  DevelopmentCard *copyCard() const override; // Creates a deep copy of the Victory Point card
  std::string getType() const override; // Returns the type of the Victory Point card ("victory point card")
};

class YearOfPlenty : public DevelopmentCard {
public:
  YearOfPlenty(); // Default constructor for Year of Plenty card
  DevelopmentCard *copyCard() const override; // Creates a deep copy of the Year of Plenty card
  std::string getType() const override; // Returns the type of the Year of Plenty card ("year of plenty card")
};

class Knight : public DevelopmentCard {
public:
  Knight(); // Default constructor for Knight card
  DevelopmentCard *copyCard() const override; // Creates a deep copy of the Knight card
  std::string getType() const override; // Returns the type of the Knight card ("knight card")
};

class Monopoly : public DevelopmentCard {
public:
  Monopoly(); // Default constructor for Monopoly card
  DevelopmentCard *copyCard() const override; // Creates a deep copy of the Monopoly card
  std::string getType() const override; // Returns the type of the Monopoly card ("monopoly card")
};

class RoadBuilding : public DevelopmentCard {
public:
  RoadBuilding(); // Default constructor for Road Building card
  DevelopmentCard *copyCard() const override; // Creates a deep copy of the Road Building card
  std::string getType() const override; // Returns the type of the Road Building card ("road building card")
};

} // namespace ariel

#endif // DEVELOPMENT_CARD_HPP
