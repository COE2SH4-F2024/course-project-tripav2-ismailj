#ifndef FOOD_H
#define FOOD_H
 
#include <cstdlib>
#include <time.h>

#include "objPos.h"
// #include "objPosArrayList.h"


class Food
{
    private:
        objPos foodPos;
        // int x_range;
        // int y_range;


    public:
        Food();
        ~Food();
        void generateRandomPosition(const objPos& blockOff); // random food generation algorithm
        objPos getFoodPos() const; // Getter for obtaining a copy of the current position of the food.
};

#endif