#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerdirection = STOP;
    // more actions to be included
    playerPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2; //want to acess x position
    playerPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    playerPos.symbol = '@';
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
        char input = mainGameMechsRef-> getInput();
        // PPA3 input processing logic 
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
         
}

void Player::movePlayer()
{
    
    // PPA3 Finite State Machine logic
    
    }

// More methods to be added