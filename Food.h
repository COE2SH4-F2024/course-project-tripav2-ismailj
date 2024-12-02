#ifndef FOOD_H
#define FOOD_H
#include <cstdlib>
#include <time.h>
 
#include "objPos.h"
#include "objPosArrayList.h"
 
 
class Food
{
    private:
        objPos foodPos;  // storign food position 
        // int x_range;
        // int y_range;
 
 
    public:
        Food();
        ~Food();
        void generateRandomPosition(const objPosArrayList& blockOff); // random food generation algorithm
        objPos getFoodPos() const;             // Returns the current food position
};
 
#endif