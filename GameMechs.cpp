#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 10; 
    boardSizeY = 20; 

    food.setObjPos(5, 5, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
    food.setObjPos(-10, -10, 'o');
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs::collectAsyncInput(){

    if (MacUILib_hasChar()) 
    {
        input = MacUILib_getChar();
    }
    if (input == ' '){
        exitFlag = true;
    }

    //return input;
}

char GameMechs:: getInput() 
{
    return input;
}

int GameMechs::getScore() 
{
    return score;
}

void GameMechs::incrementScore()
{
    ++score;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here
void GameMechs::generateFood(objPos blockOff)
{
    srand(time(NULL));

    int foodX, foodY;
    bool isPositionValid;

    do {
        // generating random coordinates that arent in the game borders
        foodX = 1 + rand() % (boardSizeX - 3);
        foodY = 1 + rand() % (boardSizeY - 3);

        // checking the position against the blocked position
        isPositionValid = (foodX != blockOff.pos->x || foodY != blockOff.pos->y);

    } while (!isPositionValid);

    // the food's coordinate
    food.setObjPos(foodX, foodY, 'o');
}
objPos GameMechs::getFoodPos() const
{
    return food;
}


