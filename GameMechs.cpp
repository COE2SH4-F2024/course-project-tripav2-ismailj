#include "GameMechs.h"
#include "MacUILib.h"
 
GameMechs* gameMechs1 = nullptr;
 
GameMechs::GameMechs()   //will use a pointer instead and get rid of global vars
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
 
    boardSizeX = 20;
    boardSizeY = 10;
 
    food.setObjPos(5, 5, '*');
}
 
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;;
 
    boardSizeX = boardX;
    boardSizeY = boardY;
 
    food.setObjPos(boardSizeX / 2, boardSizeY / 2, '*');
}
 
// do you need a destructor?
 
 
GameMechs::~GameMechs()
{
    //nothing on the heap
    //destructor can stay empty for now
}
 
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}
 
bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
   
 
char GameMechs::getInput()
{
    if (MacUILib_hasChar() != 0) {
 
        input = MacUILib_getChar();
    }
}
 
int GameMechs::getScore() //removed const
{
    return score;
}
 
void GameMechs::incrementScore()
{
    score++;
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