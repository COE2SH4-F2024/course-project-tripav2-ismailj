#include "GameMechs.h"
#include "MacUILib.h"
#include "objPos.h"
 
GameMechs* gameMechs1 = nullptr;
 
GameMechs::GameMechs()   //will use a pointer instead and get rid of global vars
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
 
    boardSizeX = 20;
    boardSizeY = 10;
 
    // food.setObjPos(6, 6, 'o');
    food.setObjPos(5, 5, '*');
    // food.setObjPos(-10,-10,'o');
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
    food.setObjPos(-10,-10,'o'); //iteration 2b
    // food.setObjPos(6, 6, 'o');
    food.setObjPos(5, 5, '*');
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
void GameMechs :: collectAsyncInput()
{
    if (MacUILib_hasChar() != 0) 
        {
            input = MacUILib_getChar();
            MacUILib_printf("[DEBUG] Captured input: %c\n", input);
        }
    if(input == '\e')
    {
        setExitTrue();
    }

}
 
char GameMechs::getInput()
{
    return input; // Always return the current value of `input`
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


 
//More methods should be added here

// void GameMechs::generateFood(objPos blockOff) {
//     int tempX, tempY;
//     char tempSymbol = '*'; // Set symbol for food
//     bool isValid;

//     do {
//         // Generate random position within board limits
//         tempX = rand() % (boardSizeX - 2) + 1; // Range [1, boardSizeX-2]
//         tempY = rand() % (boardSizeY - 2) + 1; // Range [1, boardSizeY-2]

//         // Check validity (food shouldn't overlap blockOff)
//         isValid = !(tempX == blockOff.pos->x && tempY == blockOff.pos->y);
//     } while (!isValid); // Retry until a valid position is found

//     // Set food position
//     food.setObjPos(tempX, tempY, tempSymbol);

// }


// objPos GameMechs::getFoodPos() const
// {
//     return food;
// }