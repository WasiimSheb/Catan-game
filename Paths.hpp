//Wasimshebalny@gmail.com
#ifndef PATHS_HPP
#define PATHS_HPP

#include "Tools.hpp"
#include <iostream>
#include <vector>

namespace ariel {

    class Node;

    class Path {
    private:
        int num;                // Unique identifier for the path
        std::vector<Node *> nodes; // Nodes connected by this path
        Road *road;             // Road built on this path
        bool occupied;          // Flag indicating if the path is occupied

    public:
        Path(); // Default constructor for Path.

        Path(int n, Node *n1, Node *n2); // Constructor for Path.

        ~Path(); // Destructor for Path.

        Node *getNode1(); // Get the first node connected by the path.

        Node *getNode2(); // Get the second node connected by the path.

        void setRoad(Road *r); // Set the road built on this path.

        Road *getRoad(); // Get the road built on this path.

        int getNum(); // Get the unique identifier of the path.

        void print(); // Display information about the path.

        bool isoccupied(); // Check if the path is occupied by a road.

        void setoccupied(bool b); // Set the occupancy status of the path.
    };

} // namespace ariel

#endif // PATHS_HPP
