//Wasimshebalny@gmail.com
#include "Paths.hpp"

namespace ariel
{

  Path::Path() {} // Default constructor for Path.

  Path::Path(int n, Node *n1, Node *n2) : road(nullptr)
  {
    this->num = n;             // Initialize unique identifier.
    this->nodes.push_back(n1); // Add first node to vector.
    this->nodes.push_back(n2); // Add second node to vector.
    this->occupied = false;    // Initialize occupancy flag.
  }

  Path::~Path()
  {
    delete road; // Delete the road object.
  }

  Node *Path::getNode1()
  {
    return this->nodes[0]; // Return pointer to the first node.
  }

  Node *Path::getNode2()
  {
    return this->nodes[1]; // Return pointer to the second node.
  }

  Road *Path::getRoad()
  {
    return this->road; // Return pointer to the road.
  }

  void Path::setRoad(Road *a)
  {
    this->road = a;      // Set the road pointer.
    this->occupied = true; // Update occupancy flag to true.
  }

  int Path::getNum()
  {
    return this->num; // Return the unique identifier.
  }

  bool Path::isoccupied()
  {
    return this->occupied; // Return the occupancy flag.
  }

  void Path::setoccupied(bool ans)
  {
    this->occupied = ans; // Set the occupancy flag.
  }

  void Path::print()
  {
    std::cout << "Num is: " << this->getNum() << " occupation? " << this->isoccupied() << std::endl;
  }

} // namespace ariel
