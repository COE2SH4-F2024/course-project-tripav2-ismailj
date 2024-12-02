#include "Player.h"
#include <iostream> // for printing lose message

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerdirection = STOP;

    playerPosList = new objPosArrayList(); // Allocate the array list
    objPos headPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList->insertHead(headPos);
    // Initialize player's position and symbol
    // playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2; 
    // playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    // playerPos.symbol = '*'; // ASCII character for the player
    
}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPosList() const //objPos &returnPos, og void
{
    // return the reference to the playerPos arrray list
    
    //return the reference to the player objPos array list
    return playerPosList; 
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef -> getInput();

    switch(input) 
    {                      
        case 'W':
        case 'w':
            if ((playerdirection == LEFT || playerdirection == RIGHT || playerdirection == STOP)){
                playerdirection = UP;
            }
            break;
        case 'S':
        case 's':
            if ((playerdirection == LEFT || playerdirection == RIGHT || playerdirection == STOP)){
                playerdirection = DOWN;
            }
            break;
        case 'D':
        case 'd':
            if ((playerdirection == UP || playerdirection == DOWN || playerdirection == STOP)){
                playerdirection = RIGHT;
            }
            break;
        case 'A':
        case 'a':
            if ((playerdirection == UP || playerdirection == DOWN || playerdirection == STOP)){
                playerdirection = LEFT;
            }
            break;
        default:
            break;
    }

       
}

void Player::movePlayer() {
    objPos currentHead = playerPosList->getHeadElement();
    objPos newHead = currentHead; 

        // PPA3 Finite State Machine logic (iteration 1A)
    switch (playerdirection) {
        case UP:
            newHead.pos->x -= 1;
            if (newHead.pos->x < 1) {
                newHead.pos->x = mainGameMechsRef->getBoardSizeX() - 2; 
            }
            break;
        case DOWN:
            newHead.pos->x += 1;
            if (newHead.pos->x > mainGameMechsRef->getBoardSizeX() - 2) {
                newHead.pos->x = 1; 
            }
            break;
        case LEFT:
            newHead.pos->y -= 1;
            if (newHead.pos->y < 1) {
                newHead.pos->y = mainGameMechsRef->getBoardSizeY() - 2; 
            }
            break;
        case RIGHT:
            newHead.pos->y += 1;
            if (newHead.pos->y > mainGameMechsRef->getBoardSizeY() - 2) {
                newHead.pos->y = 1; 
            }
            break;
        default:
            return; 
    }



    // More methods to be added


    playerPosList->insertHead(newHead);
    playerPosList->removeTail(); //remove the last piece(tail)

//checking for collision with self
    if (checkSelfCollision()) {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }
    
}

// Check for collision with self
bool Player::checkSelfCollision()
{
    objPos head = playerPosList->getHeadElement(); // Get the head element
    for (int i = 1; i < playerPosList->getSize(); i++) // Start from index 1 to check for collision
    {
        objPos currentElement = playerPosList->getElement(i); // Store the element in a variable
        if (head.isPosEqual(&currentElement)) // Use the address of the variable
        {
            return true; // Collision detected
        }
    }
    return false; // No collision
}