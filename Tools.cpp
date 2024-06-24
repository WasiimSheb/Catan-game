//Wasimshebalny@gmail.com
#include "Tools.hpp"
#include <stdexcept>

using namespace ariel;

// Initializes the player to nullptr.
GameTools::GameTools() : player(nullptr) {}

// Destructor.
GameTools::~GameTools() {}

// Default constructor.
Road::Road() {}

// Destructor.
Road::~Road() {}

// Constructor for Road that sets the player.
// @param p Pointer to the player who owns this road.
Road::Road(Player *p) {
   this->player = p;
}

// Get the player who owns this road.
// @return Pointer to the player.
Player *Road::getPlayer() { 
  return this->player; 
}

// Get the type of the tool.
// @return The type of the tool as a string.
string Road::getType() { 
  return "Road";
}

// Constructor for City that sets the player.
City::City(Player *p) { 
  this->player = p; 
}

// Default constructor.
City::City() {}

// Destructor.
City::~City() {}

// Get the type of the tool.
// @return The type of the tool as a string.
string City::getType() {
   return "City";
}

// Get the player who owns this city.
// @return Pointer to the player.
Player *City::getPlayer() { 
  return this->player;
}

// Constructor for Settlement that sets the player.
Settlement::Settlement(Player *p) { 
  this->player = p; 
}

// Default constructor.
Settlement::Settlement() {}

// Destructor.
Settlement::~Settlement() {}

// Get the type of the tool.
// @return The type of the tool as a string.
string Settlement::getType() { 
  return "Settlement"; 
}

// Get the player who owns this settlement.
// @return Pointer to the player.
Player *Settlement::getPlayer() {
    if (this->player != nullptr) {
        return this->player;
    }
    throw logic_error("invalid owner");
}
