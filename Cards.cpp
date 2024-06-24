//Wasimshebalny@gmail.com
#include "Cards.hpp"
#include <string>

using namespace ariel;

Card::Card() {} // Default constructor for Card.

Card::Card(Card &c) : type(c.type) {} // Copy constructor for Card.

Card::~Card() {} // Virtual destructor for Card.

string Card::getCardType() const {
    return type; // Get the type of the card.
}

Wood::Wood() { type = "Wood"; } // Constructor for Wood.

string Wood::getCardType() const {
    return type; // Get the type of the wood card.
}

Grains::Grains() { type = "Grains"; } // Constructor for Grains.

string Grains::getCardType() const {
    return type; // Get the type of the grains card.
}

Wool::Wool() { type = "Wool"; } // Constructor for Wool.

string Wool::getCardType() const {
    return type; // Get the type of the wool card.
}

Ore::Ore() { type = "Ore"; } // Constructor for Ore.

string Ore::getCardType() const {
    return type; // Get the type of the ore card.
}

Brick::Brick() { type = "Brick"; } // Constructor for Brick.

string Brick::getCardType() const {
    return type; // Get the type of the brick card.
}
