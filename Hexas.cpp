//Wasimshebalny@gmail.com
#include "Hexas.hpp"
using namespace std;
using namespace ariel;


/**
 * Constructs a Hexagon with specified resource, number, cities, roads, and settlements.
 * @param r The resource type of the hexagon.
 * @param num The number assigned to the hexagon.
 * @param cities Vector of cities adjacent to the hexagon.
 * @param roads Vector of roads adjacent to the hexagon.
 * @param settelments Vector of settlements adjacent to the hexagon.
 */
Hexa::Hexa(string r, int num, vector<City> cities, vector<Road> roads, vector<Settlement> settelments)
    : data(r), num(num), card(nullptr), roads(roads) 
{
    // Assign a resource card based on the resource type
    if (r == "forest") {
        this->card = new Wood();
    } else if (r == "pasture") {
        this->card = new Wool();
    } else if (r == "hills") {
        this->card = new Brick();
    } else if (r == "mountains") {
        this->card = new Ore();
    } else if (r == "fields") {
        this->card = new Grains();
    } else { 
        this->card = nullptr;
    }
}

/**
 * Default constructor for Hexagon.
 */
Hexa::Hexa() : data(""), num(0), card(nullptr), hex_id(0) {}

/**
 * Destructor for Hexagon.
 * Deletes the associated resource card.
 */
Hexa::~Hexa() {
    delete this->card;
}

/**
 * Gets the resource type of the hexagon.
 * @return The resource type as a string.
 */
string Hexa::getdata() {
    return this->data;
}

/**
 * Gets the road at the specified index.
 * @param k The index of the road.
 * @return Pointer to the Road object or nullptr if index is out of range.
 */
Road* Hexa::getRoad(size_t k) {
    return &this->roads[k];
}

/**
 * Sets a road for the hexagon.
 * @param r The road to set.
 */
void Hexa::setRoads(Road r) {
    this->roads.push_back(r);
}

/**
 * Displays information about the hexagon.
 */
void Hexa::printinf() {
    cout << "Hexagon number: " << this->num << ", Resource: " << this->data << endl;
}

/**
 * Sets the nodes for the hexagon.
 * @param v Vector of Node pointers.
 */
void Hexa::setNode(vector<Node *> v) {
    this->vertices = v;
}

/**
 * Gets the nodes of the hexagon.
 * @return Vector of Node pointers.
 */
vector<Node *> Hexa::getNode() {
    return this->vertices;
}

/**
 * Gets the number assigned to the hexagon.
 * @return The number of the hexagon.
 */
int Hexa::getNum() {
    return this->num;
}


/**
 * @brief Gets the resource card associated with the hexagon.
 * @return Pointer to the Card object.
 */
Card* Hexa::getResCard() {
    if (this->card != nullptr) {
        return this->card;
    }

    // Assign a resource card based on the resource type if not already assigned
    string resource = this->getdata();

    if (resource == "forest") {
        this->card = new Wood();
    } else if (resource == "pasture") {
        this->card = new Wool();
    } else if (resource == "hills") {
        this->card = new Brick();
    } else if (resource == "mountains") {
        this->card = new Ore();
    } else if (resource == "fields") {
        this->card = new Grains();
    } else { 
        this->card = nullptr;
    }

    return this->card;
}

/**
 * Sets the resource card for the hexagon.
 * @param card Pointer to the Card object.
 */
void Hexa::setResCard(Card* card) {
    this->card = card;
}

/**
 * Gets the unique identifier of the hexagon.
 * @return The hexagon ID.
 */
int Hexa::gethex_id() {
    return this->hex_id;
}

/**
 * Sets the unique identifier for the hexagon.
 * @param id The hexagon ID to set.
 */
void Hexa::sethex_id(int id) {
    this->hex_id = id;
}