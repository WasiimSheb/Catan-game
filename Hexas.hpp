//Wasimshebalny@gmail.com
#ifndef HEXAS_HPP
#define HEXAS_HPP

#include "Cards.hpp"
#include "Nodes.hpp"
#include "Paths.hpp"
#include <vector>

using namespace std;

namespace ariel {

/**
 * @class Hexa
 * @brief Represents a tile on the board.
 */
class Hexa {
private:
  string data;    // which type is this hexagon is
  int num;            /**< The number assigned to the tile (2-12) */
  int hex_id;        /**< Unique identifier for the tile */
  vector<Road> roads; /**< Roads connected to the tile */
  Card *card;         /**< Resource card associated with the tile */
  vector<Node *> vertices = {3, nullptr}; /**< Vertices (corners) of the tile */

public:
  /**
   * Constructs a Hexa with specified resource, number, cities, roads, and settlements.
   * @param resource The resource type of the tile.
   * @param num The number assigned to the tile (2-12).
   * @param cities Vector of cities adjacent to the tile.
   * @param roads Vector of roads adjacent to the tile.
   * @param settelments Vector of settlements adjacent to the tile.
   */
  Hexa(string resource, int num, vector<City> cities, vector<Road> roads, vector<Settlement> settelments);

  /**
   * Default constructor for Hexa.
   */
  Hexa();                           

  /**
   * Destructor for Hexa.
   */
  ~Hexa();                           

  /**
   * Gets the resource type of the tile.
   * @return The resource type as a string.
   */
  string getdata();     

  /**
   * Gets the road at the specified index.
   * @param i The index of the road.
   * @return Pointer to the Road object.
   */
  Road *getRoad(size_t);       

  /**
   * Sets a road for the tile.
   * @param road The road to set.
   */
  void setRoads(Road road);              

  /**
   * Displays information about the tile.
   */
  void printinf();                  

  /**
   * Sets the vertices for the tile.
   * @param v Vector of Node pointers.
   */
  void setNode(vector<Node *> v); 

  /**
   * Gets the vertices of the tile.
   * @return Vector of Node pointers.
   */
  vector<Node *> getNode();       

  /**
   * Gets the number assigned to the tile.
   * @return The number of the tile.
   */
  int getNum();                       

  /**
   * Gets the resource card associated with the tile.
   * @return Pointer to the Card object.
   */
  Card *getResCard();                    

  /**
   * Sets the resource card for the tile.
   * @param card Pointer to the Card object.
   */
  void setResCard(Card *card);               

  /**
   * Gets the unique identifier of the tile.
   * @return The tile ID.
   */
  int gethex_id();                   

  /**
   * Sets the unique identifier for the tile.
   * @param num The tile ID to set.
   */
  void sethex_id(int num);             
};

} //namespace ariel

#endif // HEXAS_HPP
