//Wasimshebalny@gmail.com
#ifndef CARDS_HPP
#define CARDS_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel {

    class Card {
    protected:
        string type; // The type of the resource card.

    public:
        Card(); // Default constructor for Card.
        Card(Card &c); // Copy constructor for Card.
        virtual ~Card(); // Virtual destructor for Card.
        virtual string getCardType() const; // Get the type of the card.
    };

    class Wood : public Card {
    public:
        Wood(); // Constructor for Wood.
        string getCardType() const override; // Get the type of the wood card.
    };

    class Grains : public Card {
    public:
        Grains(); // Constructor for Grains.
        string getCardType() const override; // Get the type of the grains card.
    };

    class Wool : public Card {
    public:
        Wool(); // Constructor for Wool.
        string getCardType() const override; // Get the type of the wool card.
    };

    class Ore : public Card {
    public:
        Ore(); // Constructor for Ore.
        string getCardType() const override; // Get the type of the ore card.
    };

    class Brick : public Card {
    public:
        Brick(); // Constructor for Brick.
        string getCardType() const override; // Get the type of the brick card.
    };

} // namespace ariel

#endif // RESOURCECARDS_HPP
