//Wasimshebalny@gmail.com
#include "Catan.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

Catan::Catan() : _players(), _board(nullptr) {}

Catan::~Catan() { delete _board; }

void Catan::setPlayers(Player *p1, Player *p2, Player *p3) {
    if (p1 && p2 && p3) {
        this->_players.push_back(p1);
        this->_players.push_back(p2);
        this->_players.push_back(p3);
    } else {
        cout << "Error: One or more player pointers are null." << endl;
    }
}

Board *Catan::getBoard() { return this->_board; }

void Catan::StartTheGame() {
    cout << "\n"
         << "               ================================================\n"
         << "               |               LET'S START PLAYING CATAN!    |\n"
         << "               ================================================\n"
         << "               |           NODES: 54   ROADS: 72         |\n"
         << "               |---------------------------------------------|\n"
         << "               |  PLAYER #1: " << this->_players[0]->getName() << "|\n"
         << "               |  PLAYER #2: " << this->_players[1]->getName() << "|\n"
         << "               |  PLAYER #3: " << this->_players[2]->getName() << "|\n"
         << "               ================================================\n"
         << "\n";

    this->_players[0]->setNextPlayer(_players[1]);
    this->_players[1]->setNextPlayer(_players[2]);
    this->_players[2]->setNextPlayer(_players[0]);

    this->_players[0]->setOtherPlayer(_players[1]);
    this->_players[0]->setOtherPlayer(_players[2]);
    this->_players[1]->setOtherPlayer(_players[2]);
    this->_players[1]->setOtherPlayer(_players[0]);
    this->_players[2]->setOtherPlayer(_players[0]);
    this->_players[2]->setOtherPlayer(_players[1]);

    this->_players[0]->setIsMyTurn(true);
}

int Catan::printWinner() {
    for (Player *p : this->_players) {
        if (p->Pointsnum() == 10) {
            cout << "\n"
                 << "               ================================================\n"
                 << "               |                 GAME OVER!                  |\n"
                 << "               ================================================\n"
                 << "               |            THE WINNER IS: " << p->getName() << "         |\n"
                 << "               ================================================\n"
                 << "\n";
            return 1;
        }
    }
    cout << "\n"
         << "               ================================================\n"
         << "               |             GAME NOT OVER YET!              |\n"
         << "               ================================================\n"
         << "               |       No player with 10 points yet.         |\n"
         << "               |          Continue the game...               |\n"
         << "               ================================================\n"
         << "\n";
    return 0;
}

vector<Player *> ariel::Catan::getPlayers() {
    return this->_players;
}
