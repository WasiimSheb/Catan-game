//Wasimshebalny@gmail.com
#ifndef BOARD_HPP
#define BOARD_HPP

#include "DevelopmentCard.hpp"
#include "Hexas.hpp"
#include <vector>
#include <map>
#include <string>
using namespace std;

namespace ariel {

class Board {
private:
  map<DevelopmentCard *, int> cards; // Map of development cards and their quantities.
  vector<Node *> nodes; // Vector of nodes representing points on the board.
  vector<Path *> paths; // Vector of paths representing connections between nodes.
  vector<Hexa *> hexas; // Vector of hexagons representing the game board tiles.
  string forest = "forest"; // Resource type for wood.
  string pasture = "pasture"; // Resource type for wool.
  string hills = "hills"; // Resource type for brick.
  string mountains = "mountains"; // Resource type for ore.
  string fields = "fields"; // Resource type for grains.
  string desert = "desert"; // Resource type for desert, provides no resources.

public:
  Board(); // Default constructor for Board.
  ~Board(); // Destructor for Board.

  Node *getNodeAt(int i); // Method to get the node at a specific index.
  Path *getPathAt(int i); // Method to get the path at a specific index.
  Hexa *getHexaAt(int i); // Method to get the hexagon at a specific index.
  DevelopmentCard *pickRandomDevCard(); // Method to pick a random development card.
  void printinf(); // Method to print the current state of the board.
};

} // namespace ariel

#endif // BOARD_HPP
