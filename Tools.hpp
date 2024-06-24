//Wasimshebalny@gmail.com
#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <vector>
using namespace std;

namespace ariel
{
    class Player;

    class GameTools
    {
    private:
        string toolType; // Type of the tool (e.g., "Road", "City", "Settlement").    

    public:
        Player *player;  // Pointer to the player who owns this tool.

        virtual string getType() = 0;

        // Default constructor.
        GameTools();

        // Virtual destructor.
        virtual ~GameTools();
    };

    class Road : public GameTools
    {
    public:
        // Default constructor.
        Road();

        // Constructor with a player parameter.
        Road(Player *p);

        // Destructor.
        ~Road();

        // Get the player who owns this road.
        // @return Pointer to the player.
        Player *getPlayer();

        // Get the type of the tool.
        // @return The type of the tool as a string.
        string getType();
    };

    class City : public GameTools
    {
    public:
        // Default constructor.
        City();

        // Constructor with a player parameter.
        City(Player *p);

        // Destructor.
        ~City();

        // Get the type of the tool.
        // @return The type of the tool as a string.
        string getType();

        // Get the player who owns this city.
        // @return Pointer to the player.
        Player *getPlayer();
    };

    class Settlement : public GameTools
    {
    public:
        // Default constructor.
        Settlement();

        // Constructor with a player parameter.
        Settlement(Player *p);

        // Destructor.
        ~Settlement();

        // Get the type of the tool.
        // @return The type of the tool as a string.
        string getType();

        // Get the player who owns this settlement.
        // @return Pointer to the player.
        Player *getPlayer();
    };
} // namespace ariel

#endif // TOOLS_HPP
