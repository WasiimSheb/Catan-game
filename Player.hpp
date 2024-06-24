//Wasimsheblny@gmail.com
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Board.hpp"
#include "DevelopmentCard.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

namespace ariel
{
  class Player
  {

  protected:
    string name; // Name of the player.
    map<string, int> cards; // Map of card types to their quantities.
    int points = 0; // Number of points the player has.
    bool myturn = false; // Flag indicating if it is the player's turn.
    Player *nextplayer; // Pointer to the next player in the turn order.
    Board *board; // Pointer to the game board.
    vector<Player *> players; // Vector of pointers to the other players.
    map<DevelopmentCard *, int> devcards; // Map of development cards to their quantities.

  public:
    Player(); // Default constructor.
    ~Player(); // Destructor.
    Player(string name); // Constructor with a name parameter.
    string getName(); // Get the name of the player.
    Player* getnextplayer();
    int Pointsnum(); // Get the number of points the player has.
    void buydevCard(); // Buy a development card.
    void addCard(Card *c, int quantity); // Add a card to the player's hand.
    int getcardnum(string cardType); // Get the number of cards of a specific type.
    void printdevcard(); // Print the development cards the player has.
    void printCard(); // Print the resource cards the player has.
    int rollDice(); // Roll the dice.
    void placeRoad(int location); // Place a road on the board.
    void placeSettelment(int location); // Place a settlement on the board.
    void placeTown(int location); // Place a town on the board.
    void placeFirstSettelment(int location); // Place the first settlement.
    void placeFirstRoad(int location); // Place the first road.
    void setBoard(Board *b); // Set the game board for the player.
    void setNextPlayer(Player *p); // Set the next player in the turn order.
    void setOtherPlayer(Player *p); // Set another player.
    DevelopmentCard *getDevCard(); // Get a development card.
    void trade(Player *p, string give, string get, size_t amountGive, size_t amountGet); // Trade resources with another player.
    void setIsMyTurn(bool isMyTurn); // Set if it is the player's turn.
    void giveCardsAfterPlacing(int location); // Give cards to the player after placing a settlement or town.
    void reduceCards(map<string, int> &cards); // Reduce the quantity of specific cards from the player's hand.
    void throwCards(); // Throw away half of the player's cards.
    bool getIsMyTurn(); // Check if it is the player's turn.
  };
} // namespace ariel

#endif // PLAYER_HPP
