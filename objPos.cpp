#include "objPos.h"
#include "MacUILib.h" //i added that

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

//destructing the constructor
objPos::~objPos()
{
    // cout <<"Destructor Called\n";
    delete pos;
}

//copy constructor
objPos::objPos(const objPos &a)
{
    // cout<<"Cpy constructor called\n";
    //deep copy

        // Pos* pos;        
        // char symbol;

    symbol = a.symbol; //deep copy
    pos = new Pos;

    for(int i = 0; i < symbol; i++)
    {
        pos[i] = a.pos[i];
    }
}

objPos& objPos::operator=(const objPos &a)
{
    //cout<<"Copy assignment operator called\n";
    if(this != &a)
    {
        this->symbol = a.symbol;
        for(int i = 0; i < this->symbol; i++)
        {
        this->pos[i] = a.pos[i];
        }
        return *this;
    }
}




void gameboard()
{
    const int rows = 10;
    const int columns = 20;
    char gameboard[rows][columns];

    for(int i = 0; i < rows; i++){
        //inner loop for width
        for(int j = 0; j < columns; j++){
            // if(int i == objpost1.x && j == objpost1.y)
            // {
            //     gameboard[i][j] = objpost1.symbol;
            // }
            if (i == 0 || i == rows-1 || j == 0 || j == columns-1)
            {
                gameboard[i][j] = '#';
            }
            else if( i == 2 && j ==6) //aribtary coordinate
            {
                gameboard[i][j] = 'W';
            }
            else if(i == 10 && j == 13)
            {
                gameboard[i][j] = 'Z'; //aribtary coordinate
            }
            else
            {
                gameboard[i][j] = ' ';
            }
            MacUILib_printf("%c", gameboard[i][j]);
            
            
        }
        MacUILib_printf("\n");

    }
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
