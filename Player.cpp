//Wasimshebalny@gmail.com
#include "Player.hpp"

using namespace std;
using namespace ariel;

// Default constructor for Player class
Player::Player() {}

// Destructor
Player::~Player() {
    for (auto i = devcards.begin(); i != this->devcards.end(); ++i) {
        delete i->first;
    }
}

// Parameterized constructor for Player class
Player::Player(string name) : name(name),
                              cards({{"Wood", 0},
                                     {"Grain", 0},
                                     {"Wool", 0},
                                     {"Ore", 0},
                                     {"Brick", 0}}) {
    // Initialize the development cards with their respective quantities set to 0
    devcards[new Monopoly()] = 0;
    devcards[new VictoryPoint()] = 0;
    devcards[new YearOfPlenty()] = 0;
    devcards[new RoadBuilding()] = 0;
    devcards[new Knight()] = 0;
}

// Return the name of the player
string Player::getName() {
    return this->name;
}

Player* Player::getnextplayer(){
    return this -> nextplayer;
}

// Function to get the number of points of the player
int ariel::Player::Pointsnum() {
    return this->points;
}

// Function to check if it's the player's turn
bool ariel::Player::getIsMyTurn() {
    return this->myturn;
}

// Function to set whether it's the player's turn
void Player::setIsMyTurn(bool b) {
    this->myturn = b;
}

// Function for the player to buy a development card
void ariel::Player::buydevCard() {
    // Check the resources
    if (this->getcardnum("Ore") < 1 || getcardnum("Grain") < 1 || getcardnum("Wool") < 1) {
        throw logic_error("Cannot buy due to lack of cards");
    }
    // Generate a random development card from the pile that is on the board
    DevelopmentCard *c = this->board->pickRandomDevCard();
    this->devcards[c]++;
    cout << this->getName() << " bought a development card: " << c->getType() << endl;
}

// Function to add k cards to the player's hand
void ariel::Player::addCard(Card *card, int quantity) {
    for (auto &cardPair : this->cards) {
        if (cardPair.first == card->getCardType()) {
            cardPair.second += quantity;
            cout << "Player: " << this->getName() << " got " << quantity << " cards of: " << card->getCardType() << endl;
            return;
        }
    }
}

// Function to print the player's development cards
void ariel::Player::printdevcard() {
    std::cout << "Player " << this->getName() << " Development Cards: ";
    for (auto pair : devcards) {
        DevelopmentCard *card = pair.first;
        std::cout << card->getType() << ", Amount: " << pair.second << endl;
    }
}


// Method to get a development card
DevelopmentCard *Player::getDevCard() {
    for (auto &entry : devcards) {
        if (entry.second > 0) {
            entry.second--; // Reduce the count of this development card type
            return entry.first; // Return the development card
        }
    }
    throw std::runtime_error("No development cards available");
}

// Function for the player to place the first settlement
void ariel::Player::placeFirstSettelment(int nodeIndex) {
    Node *node = this->board->getNodeAt(nodeIndex);

    if (!node->isOccupied()) {
        std::cout << this->getName() << " is placing the first settlement at node number: " << node->getNum() << std::endl;

        node->setOccupied(true); // Set to occupied

        Settlement *settlement = new Settlement(this);
        node->setSettlement(settlement); // Assign the settlement to the player

        // Add this settlement to the relevant hexagons
        std::cout << "Adding settlement to hexa number: " << node->getHexa1()->getNum() << std::endl;

        if (node->getHexa2() != nullptr) {
            std::cout << "Adding settlement to hexa number: " << node->getHexa2()->getNum() << std::endl;
        }

        if (node->getHexa3() != nullptr) {
            std::cout << "Adding settlement to hexa number: " << node->getHexa3()->getNum() << std::endl;
        }

        // Give the player all the resource cards from those hexagons
        this->giveCardsAfterPlacing(nodeIndex);
        this->points++;
    } else {
        throw std::logic_error("Error: this Node is already occupied");
    }
}

// Function for the player to place the first road
void ariel::Player::placeFirstRoad(int p) {
    Path *path = this->board->getPathAt(p);

    if (!path->isoccupied()) {
        path->setoccupied(true);
        Road *road = new Road(this);
        path->setRoad(road);

        std::cout << this->getName() << " placed a road at edge number: " << path ->getNum() << std::endl;
    } else {
        throw std::logic_error("Error: this edge is already occupied");
    }
}

int Player::getcardnum(string cardType) {
    return cards[cardType];
}
// Function for the player to place a road
void ariel::Player::placeRoad(int p) {
    Path *path = this->board->getPathAt(p);

    // Check if the edge is already occupied
    if (path->isoccupied()) {
        throw std::logic_error("Error: This Path is already occupied");
    }

    // Check if the player has the required resources
    if (this->getcardnum("Wood") < 1 || this->getcardnum("Brick") < 1) {
        throw std::logic_error("Error: cannot place Road because don't have the resources");
    }

    // Deduct the resources
    this->cards["Wood"]--;
    this->cards["Brick"]--;

    Node *n1 = path->getNode1();
    Node *n2 = path->getNode2();

    // Check if the road can be placed
    bool canPlaceRoad =
            (n1->isOccupied() && (n1->getSettlement()->getPlayer() == this || n1->getCity()->getPlayer() == this)) ||
            (n2->isOccupied() && (n2->getSettlement()->getPlayer() == this || n2->getCity()->getPlayer() == this)) ||
            (n1->getPath1() && n1->getPath1()->isoccupied() && n1->getPath1()->getRoad()->getPlayer() == this) ||
            (n1->getPath2() && n1->getPath2()->isoccupied() && n1->getPath2()->getRoad()->getPlayer() == this) ||
            (n1->getPath3() && n1->getPath3()->isoccupied() && n1->getPath3()->getRoad()->getPlayer() == this) ||
            (n2->getPath1() && n2->getPath1()->isoccupied() && n2->getPath1()->getRoad()->getPlayer() == this) ||
            (n2->getPath2() && n2->getPath2()->isoccupied() && n2->getPath2()->getRoad()->getPlayer() == this) ||
            (n2->getPath3() && n2->getPath3()->isoccupied() && n2->getPath3()->getRoad()->getPlayer() == this);

    if (canPlaceRoad) {
        path->setoccupied(true);
        Road *road = new Road(this);
        path->setRoad(road);
        std::cout << this->getName() << " placed Road at path number: " << path->getNum() << std::endl;
    } else {
        throw std::logic_error("Error: cannot place Road in this Path");
    }
}

// Function to set the game board for the player
void Player::setBoard(Board *b) {
    this->board = b;
}

// Function to set the next player in the game sequence
void ariel::Player::setNextPlayer(Player *p) {
    this->nextplayer = p;
}

// Function to set another player in the game
void ariel::Player::setOtherPlayer(Player *p) {
    if (p != nullptr) {
        this->players.push_back(p);
    }
}

// Function to print the player's cards
void ariel::Player::printCard() {
    cout << "Player: " << this->getName();
    for (const auto &card : this->cards) {
        cout << " Card: " << card.first << " Amount: " << card.second;
    }
    cout << "" << endl;
}

// Function for the player to roll the dice
int ariel::Player::rollDice() {
    if (!this->getIsMyTurn()) {
        throw std::logic_error("Error: Not your turn");
    }
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    // Roll two dice
    int dice1 = dis(gen);
    int dice2 = dis(gen);
    int result = dice1 + dice2;
    std::cout << this->getName() << " rolled the dice. The result: " << result << std::endl;

    // If the result is 7, players must discard cards
    if (result == 7) {
        std::cout << "Players with more than 7 cards need to discard half of their cards." << std::endl;
        throwCards();
    }

    // Function to process resource allocation
    auto processResourceAllocation = [&](Node *node, Player *player, int cardsToAdd) {
        if (node->getSettlement() && node->getSettlement()->getPlayer() == player) {
            player->addCard(this->board->getHexaAt(result)->getResCard(), cardsToAdd);
        } else if (node->getCity() && node->getCity()->getPlayer() == player) {
            player->addCard(this->board->getHexaAt(result)->getResCard(), cardsToAdd * 2);
        }
    };

    // Allocate resources based on the dice roll
    for (int i = 0; i < 19; i++) {
        if (this->board->getHexaAt(i)->gethex_id() == result) {
            for (int j = 0; j < 6; j++) {
                Node *node = this->board->getHexaAt(i)->getNode()[j];
                if (node && node->isOccupied()) {
                    processResourceAllocation(node, this, 1);
                    processResourceAllocation(node, this->players[0], 1);
                    processResourceAllocation(node, this->players[1], 1);
                }
            }
        }
    }

    this->myturn = false;               // Finish current player's turn
    this->nextplayer->setIsMyTurn(true);  // Set next player's turn
    return result;
}

// Function for the player to place a settlement
void ariel::Player::placeSettelment(int nodeIndex) {
    Node *node = this->board->getNodeAt(nodeIndex);

    // Check if the node is already occupied
    if (node->isOccupied()) {
        throw invalid_argument("This node is taken");
    }

    // Check if the player has enough resources
    for (auto &card : cards) {
        if (card.second < 1) {
            throw logic_error("Insufficient resources");
        }
    }

    // Deduct resources
    for (auto &card : cards) {
        card.second--;
    }

    // Function to check if a node has player's settlement or city
    auto isPlayerStructure = [&](Node *n) {
        return (n->isOccupied() &&
                ((n->getSettlement() && n->getSettlement()->getPlayer() == this) ||
                 (n->getCity() && n->getCity()->getPlayer() == this)));
    };

    // Function to check if a node has a road connected to the player
    auto isPlayerRoadConnected = [&](Node *n) {
        return ((n->getPath1() && n->getPath1()->isoccupied() && n->getPath1()->getRoad()->getPlayer() == this) ||
                (n->getPath2() && n->getPath2()->isoccupied() && n->getPath2()->getRoad()->getPlayer() == this) ||
                (n->getPath3() && n->getPath3()->isoccupied() && n->getPath3()->getRoad()->getPlayer() == this));
    };

    // Check if the settlement can be placed
    if (isPlayerStructure(node) || isPlayerRoadConnected(node)) {
        node->setSettlement(new Settlement(this));
        cout << this->getName() << " placed Settlement at node number: " << node->getNum() << endl;
        this->points++;
    } else {
        throw logic_error("Invalid placement");
    }
}

// Function for the player to place a City
void ariel::Player::placeTown(int nodeIndex) {
    Node *node = this->board->getNodeAt(nodeIndex);

    // Check if this node already has a city
    if (node->getCity() != nullptr) {
        throw invalid_argument("Error: this town is already occupied");
    }

    // Check if this node has a settlement
    if (node->getSettlement() == nullptr) {
        throw invalid_argument("Error: there is no settlement on this node");
    }

    // Check if the settlement belongs to the current player
    if (node->getSettlement()->getPlayer() != this) {
        throw logic_error("Error: this node already has a settlement of another player");
    }

    // Check if the player has the required resources
    if (this->getcardnum("Grain") < 2 || this->getcardnum("Ore") < 3) {
        throw logic_error("Error: cannot place Town because don't have the resources");
    }

    // Deduct the resources
    this->cards["Ore"] -= 3;
    this->cards["Grain"] -= 2;

    // Place the city
    City *city = new City(this);
    node->setCity(city);

    // Update the player's points
    this->points++;
    std::cout << this->getName() << " placed City at node number: " << node->getNum() << std::endl;
}

// Function for the player to discard cards when the dice is rolled and a 7 is thrown, chosen randomly
void ariel::Player::throwCards() {
    // Calculate the total number of cards the player has
    int totalCards = 0;
    for (const auto &card : cards) {
        if (card.second > 0) {
            totalCards += card.second;
        }
    }

    // Reduce the player's cards if they have more than 7
    if (totalCards > 7) {
        reduceCards(this->cards);
        cout << this->name << " discarded cards." << endl;
    }

    // Reduce cards for each other player if they have more than 7
    for (auto *player : this->players) {
        int otherPlayerTotalCards = 0;
        for (const auto &card : player->cards) {
            if (card.second > 0) {
                otherPlayerTotalCards += card.second;
            }
        }

        if (otherPlayerTotalCards > 7) {
            cout << player->name << " discarded cards." << endl;
            reduceCards(player->cards);
        }
    }
}

// Function to reduce cards for the player if needed
void Player::reduceCards(map<string, int> &cards) {
    int totalCards = 0;

    // Calculate the total number of cards
    for (const auto &card : cards) {
        totalCards += card.second;
    }

    // If the total number of cards is greater than 7, reduce them to half
    if (totalCards > 7) {
        int targetTotal = totalCards / 2;  // Calculate the target number of cards
        vector<string> cardTypes;

        // Collect all types of cards that have a non-zero amount
        for (const auto &card : cards) {
            if (card.second > 0) {
                cardTypes.push_back(card.first);
            }
        }

        // Randomly discard cards until the total number of cards is reduced to the target total
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, cardTypes.size() - 1);

        // Continue discarding cards until the target total is reached
        while (totalCards > targetTotal) {
            int index = dis(gen);
            string cardType = cardTypes[index];

            // Decrement the card count and update the total
            if (cards[cardType] > 0) {
                cards[cardType]--;
                totalCards--;

                // If a card type is exhausted, remove it from the list
                if (cards[cardType] == 0) {
                    cardTypes.erase(cardTypes.begin() + index);
                    // Break the loop if there are no more card types left
                    if (cardTypes.empty()) {
                        break;
                    }
                }
            }
        }
    }
}


// Function for the player to trade resources with another player
void ariel::Player::trade(Player *tradePartner, string resourceToGive, string resourceToReceive, size_t amountToGive, size_t amountToReceive) {
    // Check if the trade is with oneself
    if (tradePartner == this) {
        throw invalid_argument("tricky trying to trade with yourself...");
    }

    // Check if both players have sufficient resources for the trade
    if (this->getcardnum(resourceToGive) >= amountToGive && tradePartner->getcardnum(resourceToReceive) >= amountToReceive) {
        // Perform the trade
        this->cards[resourceToGive] -= amountToGive;
        this->cards[resourceToReceive] += amountToReceive;
        tradePartner->cards[resourceToReceive] -= amountToReceive;
        tradePartner->cards[resourceToGive] += amountToGive;

        // Print trade details
        cout << this->getName() << " is trading:  " << amountToGive << " " << resourceToGive
             << " to " << tradePartner->getName() << " and receives " << amountToReceive
             << " " << resourceToReceive << endl;
    } else {
        // Throw an error if the trade cannot be completed due to insufficient resources
        throw invalid_argument("this trade couldn't be completed due to insufficient resources");
    }
}

// Function to give cards after placing a settlement
void Player::giveCardsAfterPlacing(int nodeIndex) {
    // Helper lambda to process each tile
    auto processHexa = [this](Hexa *hex) {
        if (hex) {
            Card *resCard = hex->getResCard();
            if (resCard) {
                Card *newCard = new Card(*resCard);
                this->addCard(newCard, 1);
                delete newCard;
            } else {
                cerr << "resource card null" << endl;
            }
        }
    };

    // Get the node and its tiles
    Node *node = this->board->getNodeAt(nodeIndex);

    // Process each of the three possible tiles
    processHexa(node->getHexa1());
    processHexa(node->getHexa2());
    processHexa(node->getHexa3());
}
