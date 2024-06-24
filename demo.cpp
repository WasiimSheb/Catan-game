//Wasimshebalny@gmail.com
#include "Catan.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;

/**
 * @brief Safely rolls the dice for a player, catching and displaying any exceptions.
 * @param player The player who is rolling the dice.
 */
void safeRollDice(Player* player) {
    try {
        player->rollDice();
    } catch (const std::exception& e) {
        std::cerr << player->getName() << " encountered an error while rolling dice: " << e.what() << std::endl;
    }
}

/**
 * @brief Safely places a road for a player, catching and displaying any exceptions.
 * @param player The player who is placing the road.
 * @param position The position where the road is to be placed.
 */
void safePlaceRoad(Player* player, int position) {
    try {
        player->placeRoad(position);
        std::cout << player->getName() << " placed Road at path number: " << position << std::endl;
    } catch (const std::exception& e) {
        std::cerr << player->getName() << " encountered an error while placing road: " << e.what() << std::endl;
    }
}

/**
 * @brief Safely places a settlement for a player, catching and displaying any exceptions.
 * @param player The player who is placing the settlement.
 * @param position The position where the settlement is to be placed.
 */
void safePlaceSettlement(Player* player, int position) {
    try {
        player->placeSettelment(position);
        std::cout << player->getName() << " placed Settlement at node number: " << position << std::endl;
    } catch (const std::exception& e) {
        std::cerr << player->getName() << " encountered an error while placing settlement: " << e.what() << std::endl;
    }
}

/**
 * @brief Safely buys a development card for a player, catching and displaying any exceptions.
 * @param player The player who is buying the development card.
 */
void safeBuyDevCard(Player* player) {
    try {
        player->buydevCard();
        std::cout << player->getName() << " bought a development card." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << player->getName() << " encountered an error while buying development card: " << e.what() << std::endl;
    }
}

/**
 * @brief Safely initiates a trade between two players, catching and displaying any exceptions.
 * @param player The player initiating the trade.
 * @param other The other player involved in the trade.
 * @param give The type of card the player is giving.
 * @param get The type of card the player is receiving.
 * @param amountGive The amount of cards the player is giving.
 * @param amountGet The amount of cards the player is receiving.
 */
void safeTrade(Player* player, Player* other, const std::string& give, const std::string& get, size_t amountGive, size_t amountGet) {
    try {
        player->trade(other, give, get, amountGive, amountGet);
        std::cout << player->getName() << " traded with " << other->getName() << ": " << amountGive << " " << give << " for " << amountGet << " " << get << std::endl;
    } catch (const std::exception& e) {
        std::cerr << player->getName() << " encountered an error while trading: " << e.what() << std::endl;
    }
}

int main() {
    // Set up the players and game
    Player* p1 = new Player("Alice");
    Player* p2 = new Player("Bob");
    Player* p3 = new Player("Charlie");
    Catan* catan = new Catan();
    catan->setPlayers(p1, p2, p3);

    // Set up the game board
    Board* board = new Board();
    p1->setBoard(board);
    p2->setBoard(board);
    p3->setBoard(board);

    // Start the game with initial placements
    catan->StartTheGame();
    board->getNodeAt(12)->printinf(); // Example of print node
    p1->placeFirstSettelment(7);
    p1->placeFirstRoad(8);
    p2->placeFirstSettelment(24);
    p2->placeFirstRoad(26);
    p3->placeFirstSettelment(16);
    p3->placeFirstRoad(17);
    p3->placeFirstSettelment(28);
    p3->placeFirstRoad(32);
    p2->placeFirstSettelment(18);
    p2->placeFirstRoad(19);
    p1->placeFirstSettelment(4);
    p1->placeFirstRoad(5);

    // Print the initial number of cards for each player
    p1->printCard();
    p2->printCard();
    p3->printCard();

    // Round 1: Rolling dice and placing roads
    std::cout << "******** ROUND 1 ********" << std::endl;

    safeRollDice(p1);
    safePlaceRoad(p1, 15);

    safeRollDice(p2);
    safePlaceRoad(p2, 27);

    safeRollDice(p3);
    try {
        p3->placeRoad(1); // p3 tries to place road in illegal place (not next to his settlement/road)
    } catch (const std::exception& e) {
        std::cerr << p3->getName() << " encountered an error while placing road: " << e.what() << std::endl;
    }

    std::cout << "******** ROUND 1 DATA ********" << std::endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    std::cout << p1->getName() << " Number of points: " << p1->Pointsnum() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->Pointsnum() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->Pointsnum() << std::endl;

    // Round 2: Rolling dice and placing settlements
    std::cout << std::endl << "******** ROUND 2 ********" << std::endl;

    safeRollDice(p1);
    safeRollDice(p2);
    safeRollDice(p3);

    safePlaceSettlement(p1, 13);
    safePlaceSettlement(p2, 22);
    safePlaceSettlement(p3, 18);

    std::cout << "******** ROUND 2 DATA ********" << std::endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    std::cout << p1->getName() << " Number of points: " << p1->Pointsnum() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->Pointsnum() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->Pointsnum() << std::endl;

    // Round 3: Rolling dice and buying development cards
    std::cout << std::endl << "******** ROUND 3 ********" << std::endl;

    safeRollDice(p1);
    safeRollDice(p2);
    safeRollDice(p3);

    safeBuyDevCard(p1);
    safeBuyDevCard(p2);
    safeBuyDevCard(p3);

    std::cout << "******** ROUND 3 DATA ********" << std::endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    std::cout << p1->getName() << " Number of points: " << p1->Pointsnum() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->Pointsnum() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->Pointsnum() << std::endl;

    // Round 4: Rolling dice, trading, and buying development cards
    std::cout << std::endl << "******** ROUND 4 ********" << std::endl;

    safeRollDice(p1);
    safeTrade(p1, p2, "Wood_card", "Grains_card", 1, 1);
    safeTrade(p1, p2, "Brick_card", "Ore_card", 1, 1);
    safeBuyDevCard(p1);

    safeRollDice(p2);
    safeTrade(p2, p3, "Wood_card", "Ore_card", 1, 2);
    safeTrade(p2, p3, "Brick_card", "Wool_card", 1, 2);
    safeBuyDevCard(p2);

    safeRollDice(p3);
    safeTrade(p3, p1, "Brick_card", "Wool_card", 1, 1);
    safeBuyDevCard(p3);

    std::cout << "******** ROUND 4 DATA ********" << std::endl;
    p1->printCard();
    p2->printCard();
    p3->printCard();
    p1->printdevcard();
    p2->printdevcard();
    p3->printdevcard();
    std::cout << p1->getName() << " Number of points: " << p1->Pointsnum() << std::endl;
    std::cout << p2->getName() << " Number of points: " << p2->Pointsnum() << std::endl;
    std::cout << p3->getName() << " Number of points: " << p3->Pointsnum() << std::endl;

    // Final Check for Winner
    catan->printWinner(); // Check if the game is over or not.

    // Cleanup
    delete p1;
    delete p2;
    delete p3;
    delete catan;
    delete board;

    return 0;
}
