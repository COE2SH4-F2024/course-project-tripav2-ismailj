#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; // its a global var meant to intantiate a player object
GameMechs *myGM;
Food *myFood; //iteration 2b

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM-> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    myPlayer = new Player(myGM);  

    exitFlag = false;
    
    myFood = new Food(); //iteration 2b
    
    myFood->generateRandomPosition(myPlayer->getPlayerPos()); //iteration 2b

}

void GetInput(void)
{
   myPlayer->updatePlayerDir(); //iteration 1a
   myGM -> collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->movePlayer(); //iteration 1a
}

void DrawScreen(void)
{
    objPos playerPos = myPlayer -> getPlayerPos();

    const int rows = 10;    // Gameboard height
    const int columns = 20; // Gameboard width
   // objPos foodPos = myGM ->getFoodPos(); //iteration 2b

    MacUILib_clearScreen(); // Clear the screen

    // Retrieve the player position without copying
    //const objPos playerPos = myPlayer->getPlayerPos();

    // Render the gameboard
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // Draw the gameboard border
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)
            {
                MacUILib_printf("#"); // Border symbol
            }
            // Draw the player at their position
            else if (i == playerPos.pos->y && j == playerPos.pos->x)
            {
                MacUILib_printf("%c", playerPos.symbol); // Use the player's symbol
            }
            // Draw empty space
            else if(j == playerPos.pos->x && i == playerPos.pos->y)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            else if(j == myFood->getFoodPos().pos->x && i == myFood->getFoodPos().pos->y)  //iteration 2b
            {
                MacUILib_printf("%c", myFood->getFoodPos().symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("\n"); // Move to the next row
    }

    // Debugging information (optional)
    MacUILib_printf("\n[DEBUG] Player position: (%d, %d, %c)\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    MacUILib_printf("\n[DEBUG] Food position: (%d, %d, %c)\n", myFood->getFoodPos().pos->x, myFood->getFoodPos().pos->y, myFood->getFoodPos().symbol);

}




void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
