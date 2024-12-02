#include "Food.h"

Food::Food()
{
    foodPos.setObjPos(1, 1, 'o'); // Initialize with default position and symbol
    srand(time(NULL));            // Seed random number generator
}

Food::~Food()
{
    // Empty for now
}

void Food::generateRandomPosition(const objPosArrayList& blockOff)
{
    int x_dim = 20; // Gameboard width
    int y_dim = 10; // Gameboard height

    // Generatignb random X coord
    do {
        foodPos.pos->x = rand() % x_dim;
    } while (foodPos.pos->x == blockOff.getHeadElement().pos->x || 
             foodPos.pos->x == 0 || 
             foodPos.pos->x == x_dim - 1);

    // Generating random Y coord
    do {
        foodPos.pos->y = rand() % y_dim;
    } while (foodPos.pos->y == blockOff.getHeadElement().pos->y || 
             foodPos.pos->y == 0 || 
             foodPos.pos->y == y_dim - 1);

    // assinging random ASCII symbol
    do {
        foodPos.symbol = (rand() % 94) + 33;
    } while (foodPos.symbol == 35 || foodPos.symbol == 64);
}

objPos Food::getFoodPos() const
{
    return foodPos; // Return the stored food position
}