# Catan Game Project
--------------------------------------------------------------------------------------------------------------------------------
## Overview

This project is a simulation of the Catan board game, implemented in C++. The game includes functionalities for managing players, game board, development cards, and gameplay mechanics. The project also includes unit tests to ensure the correctness of the implementation.
--------------------------------------------------------------------------------------------------------------------------------
## Features

- **Player Management**: Add players, manage turns, and trade resources.
- **Game Board**: Initialize and manage the game board with nodes, paths, and hexagons.
- **Development Cards**: Buy and use development cards during the game.
- **Dice Roll**: Simulate rolling dice to generate resources and manage player actions.
- **Unit Tests**: Ensure the correctness of the game logic using unit tests.
--------------------------------------------------------------------------------------------------------------------------------
## Requirements

- C++ compiler (e.g., `g++`)
- `make` utility
- `doctest` library for unit testing
- `clang-tidy` for static analysis (optional)
--------------------------------------------------------------------------------------------------------------------------------
### Installation
1. **Clone the repository**:
   git https://github.com/WasiimSheb/systemsoftware2Ex3/tree/main
   cd systemsoftware2Ex3
--------------------------------------------------------------------------------------------------------------------------------
## Build the project:
  make
--------------------------------------------------------------------------------------------------------------------------------
## Usage:
   Running the Demo
  To run the demo of the Catan game:
   make demo
--------------------------------------------------------------------------------------------------------------------------------
## To run the unit tests:
  make test
--------------------------------------------------------------------------------------------------------------------------------
# Project Structure
  Board.cpp, Board.hpp: Implementation and header for the game board.
  
  Catan.cpp, Catan.hpp: Implementation and header for the Catan game logic.
  
  Player.cpp, Player.hpp: Implementation and header for player management.
  
  DevelopmentCard.cpp, DevelopmentCard.hpp: Implementation and header for development cards.
  
  Hexas.cpp, Hexas.hpp: Implementation and header for hexagons on the board.
  
  Nodes.cpp, Nodes.hpp: Implementation and header for nodes on the board.
  
  Paths.cpp, Paths.hpp: Implementation and header for paths on the board.
  
  Cards.cpp, Cards.hpp: Implementation and header for resource cards.
  
  Tools.cpp, Tools.hpp: Utility functions and classes.
  
  Test.cpp: Unit tests for the project using the doctest library.
  
  --------------------------------------------------------------------------------------------------------------------------------
  Contributing: 
  Contributions are welcome! Please fork the repository and submit pull requests for any features, bug fixes, or improvements.
  
--------------------------------------------------------------------------------------------------------------------------------
## Contact
  For any questions or suggestions, please contact Wasimshebalny@gmail.com.
