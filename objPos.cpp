#include "objPos.h"
#include "MacUILib.h"
#include <iostream>
using namespace std;

//default contructor (already here)
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}


// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule



//ADDING COPY CONSTRUCTOR

objPos::objPos(const objPos& other)
{
    std::cout << "Copy constructor called\n";
    pos = new Pos;              // Allocate memory for a new Pos (free this*)
    pos->x = other.pos->x;      // Copy x-coordinate
    pos->y = other.pos->y;      // Copy y-coordinate
    symbol = other.symbol;      // Copy the symbol
}

//ADDING ASSINGMENT OPERATOR 

objPos& objPos::operator=(const objPos& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {       // Checkign for self-assignment
        delete pos;             // Freeing**
        pos = new Pos;          // Allocate memory for new Pos (free this*)
        pos->x = other.pos->x;  // Copy x-coord
        pos->y = other.pos->y;  // Copy y-coord
        symbol = other.symbol;  // Copy symbol
    }
    return *this;               // Return *this for assignment chaining
}


//DESTRUCTOR
objPos::~objPos()
{
    std::cout << "Destructor called\n"; 
    delete pos;                         // freeing*
}


void DrawScreen(void)
{
    // dimensions
    const int HEIGHT = 10;
    const int WIDTH = 20;

    // Defining the player object and game objects
    objPos player(5, 5, '#'); // Player starts at (5, 5) with symbol '#'
    objPos items[] = {
        objPos(2, 6, 'W'), 
        objPos(4, 8, 'X'),
        objPos(7, 3, 'Y'), 
        objPos(6, 10, 'Z') 
    };

    const int NUM_ITEMS = sizeof(items) / sizeof(items[0]); // Number of items

    // 1. Clear the current screen contents
    MacUILib_clearScreen();

    // 2. Iterate through each character location on the game board
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            // 3. Drawing gameboard border using `#`
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
            {
                MacUILib_printf("#"); // Border symbol
            }
            // Check for the player object position
            else if (x == player.pos->x && y == player.pos->y)
            {
                MacUILib_printf("%c", player.symbol); // Player symbol
            }
            else
            {
                int itemFound = 0;

                // Check for items in the gameboard
                for (int i = 0; i < NUM_ITEMS; i++)
                {
                    if (x == items[i].pos->x && y == items[i].pos->y)
                    {
                        // Draw the item's symbol
                        MacUILib_printf("%c", items[i].symbol);
                        itemFound = 1;
                        break;
                    }
                }

                // Print a space if no item is found
                if (!itemFound)
                {
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n"); // Move to  next row
    }

    // 4. Debug info.
    MacUILib_printf("\n[DEBUG] Player position: (%d, %d)\n", player.pos->x, player.pos->y);
    MacUILib_printf("[DEBUG] Number of items on board: %d\n", NUM_ITEMS);
    MacUILib_printf("[DEBUG] Gameboard dimensions: %dx%d\n", WIDTH, HEIGHT);
}


void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
