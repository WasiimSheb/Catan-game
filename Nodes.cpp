//Wasimshebalny@gmail.com
#include "Nodes.hpp"
#include "Paths.hpp"
#include "Hexas.hpp"

namespace ariel
{
    // Constructor for Node.
    Node::Node(int n, std::vector<Path *> p, std::vector<Hexa *> h) : num(n), city(nullptr), settlement(nullptr), occupied(false), paths(p), hexas(h) {}

    // Destructor for Node.
    Node::~Node()
    {
        if (settlement != nullptr) delete settlement;
        if (city != nullptr) delete city;
    }

    int Node::getNum() { return num; } // Get unique identifier.

    void Node::addPath(Path *p) { paths.push_back(p); } // Add an edge.

    void Node::addHexa(Hexa *h) { hexas.push_back(h); } // Add a tile.

    void Node::printinf() // Print node info.
    {
        std::cout << "Node number: " << this->getNum();
        std::cout << " , On Lands: " << std::endl;
        for (auto &hex : hexas)
        {
            if (hex != nullptr)
                hex->printinf();
        }
        std::cout << std::endl;
    }

    Hexa *Node::getHexa1() // Get first tile.
    {
        return hexas.empty() ? nullptr : hexas[0];
    }

    Hexa *Node::getHexa2() // Get second tile.
    {
        return hexas.size() < 2 ? nullptr : hexas[1];
    }

    Hexa *Node::getHexa3() // Get third tile.
    {
        return hexas.size() < 3 ? nullptr : hexas[2];
    }

    Path *Node::getPath1() // Get first edge.
    {
        return paths.empty() ? nullptr : paths[0];
    }

    Path *Node::getPath2() // Get second edge.
    {
        return paths.size() < 2 ? nullptr : paths[1];
    }

    Path *Node::getPath3() // Get third edge.
    {
        return paths.size() < 3 ? nullptr : paths[2];
    }

    bool Node::isOccupied() { return occupied; } // Check occupancy.

    void Node::setOccupied(bool b) { occupied = b; } // Set occupancy.

    Settlement *Node::getSettlement() { return settlement; } // Get settlement.

    void Node::setSettlement(Settlement *s) { settlement = s; } // Set settlement.

    void Node::setCity(City *c) { city = c; } // Set city.

    City *Node::getCity() { return city; } // Get city.

} // namespace ariel
