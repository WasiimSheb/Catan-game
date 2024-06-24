//Wasimshebalny@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "Catan.hpp"

using namespace std;
using namespace ariel;

// Test for Board class
TEST_CASE("Board Class")
{
    Board board;

    SUBCASE("Test Initial Nodes")
    {
        // Check if nodes exist at specified positions
        CHECK(board.getNodeAt(0) != nullptr);
        CHECK(board.getNodeAt(53) != nullptr);

        // Check if out-of-bound access throws exception
        CHECK_THROWS_AS(board.getNodeAt(54), std::out_of_range);
    }

    SUBCASE("Test Initial Paths")
    {
        // Check if paths exist at specified positions
        CHECK(board.getPathAt(0) != nullptr);
        CHECK(board.getPathAt(71) != nullptr);

        // Check if out-of-bound access throws exception
        CHECK_THROWS_AS(board.getPathAt(72), std::out_of_range);
    }

    SUBCASE("Test Initial Hexas")
    {
        // Check if hexagons exist at specified positions
        CHECK(board.getHexaAt(0) != nullptr);
        CHECK(board.getHexaAt(18) != nullptr);

        // Check if out-of-bound access throws exception
        CHECK_THROWS_AS(board.getHexaAt(19), std::out_of_range);
    }

    SUBCASE("Test Pick Random Dev Card")
    {
        // Assuming the board is initialized with some development cards
        DevelopmentCard *card = board.pickRandomDevCard();
        CHECK(card != nullptr);
    }

    SUBCASE("Test Display Board")
    {
        // Check if the display function runs without errors
        CHECK_NOTHROW(board.printinf());
    }

    // Test destructor
    SUBCASE("Test Destructor")
    {
        // Explicitly call the destructor to check for clean deletion
        // Note: You should not manually call the destructor in typical usage. This is purely for testing purposes.
        Board *testBoard = new Board();
        CHECK_NOTHROW(delete testBoard);
    }
}

/* Test cases for the Player */
TEST_CASE("Test Player")
{

    SUBCASE("Test Player Initialization")
    {
        Player *p1 = new Player("Amit");
        Player *p2 = new Player("wasim");
        Player *p3 = new Player("wasim2");
        Catan *catan = new Catan();
        catan->setPlayers(p1, p2, p3);

        CHECK(p1->getName() == "Amit");
        CHECK(p1->Pointsnum() == 0);
        CHECK(p1->getIsMyTurn() == false);

        delete p1;
        delete p2;
        delete p3;
        delete catan;
    }

    SUBCASE("Test Place First Settlement and Road")
    {
        Player *p1 = new Player("Amit");
        Player *p2 = new Player("wasim");
        Player *p3 = new Player("wasim2");
        Catan *catan = new Catan();
        catan->setPlayers(p1, p2, p3);

        Board board;
        p1->setBoard(&board);
        p1->addCard(new Wood(), 1);
        p1->addCard(new Brick(), 1);
        p1->addCard(new Wool(), 1);
        p1->addCard(new Grains(), 1);
        CHECK_NOTHROW(p1->placeFirstSettelment(7));
        CHECK_NOTHROW(p1->placeFirstRoad(8));

        delete p1;
        delete p2;
        delete p3;
        delete catan;
    }

    SUBCASE("Test Place Road")
    {
        Player *p1 = new Player("Amit");
        Player *p2 = new Player("wasim");
        Player *p3 = new Player("wasim2");
        Catan *catan = new Catan();
        catan->setPlayers(p1, p2, p3);

        Board board;
        p1->setBoard(&board);
        p1->addCard(new Wood(), 1);
        p1->addCard(new Brick(), 1);
        CHECK_NOTHROW(p1->placeFirstRoad(8));
        CHECK_THROWS_AS(p1->placeRoad(8), std::logic_error);

        delete p1;
        delete p2;
        delete p3;
        delete catan;
    }

    SUBCASE("Test Place Settlement")
    {
        Player *p1 = new Player("Amit");
        Player *p2 = new Player("wasim");
        Player *p3 = new Player("wasim2");
        Catan *catan = new Catan();
        catan->setPlayers(p1, p2, p3);

        Board board;
        p1->setBoard(&board);
        p1->addCard(new Wood(), 1);
        p1->addCard(new Brick(), 1);
        p1->addCard(new Wool(), 1);
        p1->addCard(new Grains(), 1);
        CHECK_NOTHROW(p1->placeFirstSettelment(7));
        CHECK_THROWS_AS(p1->placeSettelment(7), std::logic_error);

        delete p1;
        delete p2;
        delete p3;
        delete catan;
    }

    SUBCASE("Test Place Town")
    {
        Player *p1 = new Player("Amit");
        Player *p2 = new Player("wasim");
        Player *p3 = new Player("wasim2");
        Catan *catan = new Catan();
        catan->setPlayers(p1, p2, p3);

        Board board;
        p1->setBoard(&board);
        p2->setBoard(&board);
        p3->setBoard(&board);

        catan->StartTheGame();

        p1->placeFirstSettelment(0);
        p1->placeFirstRoad(0);

        p2->placeFirstSettelment(1);
        p2->placeFirstRoad(1);

        p3->placeFirstSettelment(2);
        p3->placeFirstRoad(2);

        CHECK_THROWS_AS(p1->placeTown(0), std::logic_error);

        delete p1;
        delete p2;
        delete p3;
        delete catan;
    }

    SUBCASE("Test Buy Development Card")
    {
        Player *p1 = new Player("Amit");
        Player *p2 = new Player("wasim");
        Player *p3 = new Player("Omer");
        Catan *catan = new Catan();
        catan->setPlayers(p1, p2, p3);
        Board *board = new Board;
        p1->setBoard(board);
        p2->setBoard(board);
        p3->setBoard(board);
        catan->StartTheGame();

        CHECK_THROWS(p1->buydevCard());

        delete p1;
        delete p2;
        delete p3;
        delete catan;
    }

    SUBCASE("Test Trade")
    {
        Player *p1 = new Player("Amit");
        Player *p2 = new Player("wasim");
        Player *p3 = new Player("Omer");
        Catan *catan = new Catan();
        catan->setPlayers(p1, p2, p3);
        Board *board = new Board();
        p1->setBoard(board);
        p2->setBoard(board);
        p3->setBoard(board);
        catan->StartTheGame();

        // Initial trade attempt should fail due to insufficient resources
        CHECK_THROWS(p1->trade(p2, "Wood_Card", "Grains_Card", 1, 1));

        // Cleanup
        delete p1;
        delete p2;
        delete p3;
        delete catan;
    }
}