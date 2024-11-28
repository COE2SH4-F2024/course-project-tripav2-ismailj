#include "Food.h"
#include "objPos.h"

Food::Food()
{
    objPos foodPos;
    foodPos.setObjPos(1,1,'o');

    srand(time(NULL));

}

Food::~Food()
{
    //empty for now
}


void Food::generateRandomPosition(const objPos& blockOff) {



    int x_dim = 20;
    int y_dim = 10;
    
    do 
    {
        foodPos.pos->x = rand() % x_dim; // gives a random number from 0 to width -1.

    } while (foodPos.pos->x == blockOff.pos->x || foodPos.pos->x == 0 || foodPos.pos->x == x_dim -1);

    do
    {
        foodPos.pos->y = rand() % y_dim; // gives a random number from 0 to length -1

    } while (foodPos.pos->y == blockOff.pos->y || foodPos.pos->y == 0 || foodPos.pos->y == y_dim -1);


   

    do
    {
        foodPos.symbol = (rand() % 94) +33;
    } while(foodPos.symbol == 35 || foodPos.symbol == 64);
    
}




objPos Food::getFoodPos() const
{
    return foodPos;
}