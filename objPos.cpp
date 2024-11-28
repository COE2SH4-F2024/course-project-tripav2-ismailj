#include "objPos.h"
#include "MacUILib.h" //added
#include <iostream> //added


objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}


// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule


//default contructor (already here)
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(const objPos& other)
{
    // std::cout << "Copy constructor called\n";
    pos = new Pos;              // Allocate memory for a new Pos (free this*)
    pos->x = other.pos->x;      // Copy x-coordinate
    pos->y = other.pos->y;      // Copy y-coordinate
    symbol = other.symbol;      // Copy the symbol
}

//ADDING ASSINGMENT OPERATOR
 
objPos& objPos::operator=(const objPos& other)
{
    // std::cout << "Copy assignment operator called\n";
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
    //std::cout << "Destructor called\n";
    delete pos;                         // freeing*
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
