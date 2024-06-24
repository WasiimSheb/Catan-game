//Wasimshebalny@gmail.com
#ifndef Nodes_HPP
#define Nodes_HPP

#include "Tools.hpp"
#include <iostream>
#include <vector>

namespace ariel
{
    class Path;
    class Hexa;

    class Node
    {
    private:
        int num;                    // Unique identifier for the node.
        City *city;                 // Pointer to the city occupying the node, if any.
        Settlement *settlement;     // Pointer to the settlement occupying the node, if any.
        bool occupied;              // Indicates whether the node is occupied by a settlement or city.
        std::vector<Path*> paths;   // List of edges connected to this node.
        std::vector<Hexa *> hexas;  // List of tiles adjacent to this node.

    public:
        Node(int n, std::vector<Path *> p, std::vector<Hexa *> h); // Constructor for Node.
        ~Node(); // Destructor for Node.

        int getNum(); // Get the unique identifier for the node.
        void addPath(Path *p); // Add an edge to the node.
        void addHexa(Hexa *h); // Add a tile to the node.
        void printinf(); // Print the info information about the node.

        Hexa *getHexa1(); // Get the first tile adjacent to the node.
        Hexa *getHexa2(); // Get the second tile adjacent to the node.
        Hexa *getHexa3(); // Get the third tile adjacent to the node.

        Path *getPath1(); // Get the first edge connected to the node.
        Path *getPath2(); // Get the second edge connected to the node.
        Path *getPath3(); // Get the third edge connected to the node.

        bool isOccupied(); // Check if the node is occupied by a settlement or city.
        void setOccupied(bool b); // Set the occupancy status of the node.

        Settlement *getSettlement(); // Get the settlement occupying the node.
        void setSettlement(Settlement *s); // Set the settlement occupying the node.

        void setCity(City *c); // Set the city occupying the node.
        City *getCity(); // Get the city occupying the node.
    };

} // namespace ariel

#endif // Nodes_HPP
