#include "Player.h"
#include "GameMechs.h" //added
#include "MacUILib.h"
Player* player = nullptr; // Global pointer to the Player object


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerdirection = STOP;

    // Initialize player's position and symbol
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2; // Center on the board
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '*'; // ASCII character for the player
}


Player::~Player()
{
    // delete any heap members here
    //no keyword "new" in the constructor
    //leave the constructor empty FOR NOW
    
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    
    return playerPos;
}

void Player::updatePlayerDir()
{
        char input = mainGameMechsRef->getInput();
    MacUILib_printf("[DEBUG] Input received: %c\n", input); // Debug input

        switch(input)
            {
      
            case 'W':
            case 'w':
                if(playerdirection == RIGHT || playerdirection == LEFT || playerdirection == STOP){
                    playerdirection = UP;
                    }
                    break;
            case 'S':
            case 's':
                if(playerdirection == RIGHT || playerdirection == LEFT || playerdirection == STOP){
                    playerdirection = DOWN;
                }
                    break;
            case 'D':
            case 'd':
                if(playerdirection == DOWN || playerdirection == UP || playerdirection == STOP){
                    playerdirection = RIGHT;
                }
                    break;
            case 'A':
            case 'a':
                if(playerdirection == UP || playerdirection == DOWN || playerdirection == STOP ){
                    playerdirection = LEFT;
                }
                    break;


            
            // Add more key processing here
            // Add more key processing here    
            default:
                break;
        }
        input = 0;
        MacUILib_printf("[DEBUG] Player direction updated: %d\n", playerdirection);
}

void Player::movePlayer()
{
    
    // PPA3 Finite State Machine logic (iteration 1A)
    switch (playerdirection)
    {
        case UP:
            playerPos.pos->y -= 1;
            break;
        case DOWN:
            playerPos.pos->y += 1;
            break;
        case RIGHT:
            playerPos.pos->x += 1;
            break;
        case LEFT:
            playerPos.pos->x -= 1;
            break;
        default:
            break; 
    }

    //implementing the gameboard wrap around logic (iteration 1A)
    int boardWidth = mainGameMechsRef->getBoardSizeX();
    int boardHeight = mainGameMechsRef->getBoardSizeY();

    if (playerPos.pos->x < 0) playerPos.pos->x = boardWidth - 1;
    else if (playerPos.pos->x >= boardWidth) playerPos.pos->x = 0;

    if (playerPos.pos->y < 0) playerPos.pos->y = boardHeight - 1;
    else if (playerPos.pos->y >= boardHeight) playerPos.pos->y = 0;
    }

// More methods to be added