#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; // its a global var meant to intantiate a player object
GameMechs *myGM;

//bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM -> getExitFlagStatus() == false)  
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

}

void GetInput(void)
{
    myGM-> collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    

    objPosArrayList* SnakeBody = myPlayer->getPlayerPosList();
    objPos playerHead = SnakeBody->getHeadElement(); // Access the head element

    objPos foodPos = myGM->getFoodPos(); // the food position

    // when the snake eats
    if (playerHead.pos->x == foodPos.pos->x && playerHead.pos->y == foodPos.pos->y) {
        myGM->incrementScore();
        myGM->generateFood(playerHead); // Generate new food at a random position
        SnakeBody->insertHead(playerHead); 
    }
}

void DrawScreen(void) {
    MacUILib_clearScreen();
    objPosArrayList* SnakeBody = myPlayer->getPlayerPosList(); 
    objPos foodPos = myGM->getFoodPos();

    const int rows = 10;    // Gameboard height
    const int columns = 20; // Gameboard width

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == columns - 1) {
                MacUILib_printf("#"); // Border symbol
            } 
            else {
                bool snakePrint = false;
                for (int k = 0; k < SnakeBody->getSize(); k++) {
                    objPos thisSeg = SnakeBody->getElement(k);
                    if (i == thisSeg.pos->x && j == thisSeg.pos->y) {
                        MacUILib_printf("%c", thisSeg.symbol); // Draw snake segment
                        snakePrint = true;
                        break;
                    }
                }
                if (!snakePrint) {
                    if (i == foodPos.pos->x && j == foodPos.pos->y) {
                        MacUILib_printf("%c", foodPos.symbol); // print the food symbol
                    } else {
                        MacUILib_printf(" "); 
                    }
                }
            }
        }
        MacUILib_printf("\n"); // Move to the next row
    }
    MacUILib_printf("\n"); // Move to the next line after each row
    MacUILib_printf("Score: %d\n", myGM->getScore());
    //MacUILib_printf("Player [x,y,sym] = [%d,%d,%c]\n", playerPos.pos->x, playerPos.pos->y,playerPos.symbol);  
    MacUILib_printf("Food [x,y,sym] = [%d,%d,%c]\n", foodPos.pos->x, foodPos.pos->y, foodPos.symbol);  
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

