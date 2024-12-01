#ifndef GAMEMECHS_H
#define GAMEMECHS_H
 
#include <cstdlib>
#include <time.h>
 
#include "objPos.h"
#include "objPosArrayList.h"
 
using namespace std;
 
class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
 
        int boardSizeX;
        int boardSizeY;
 
        objPos food;
 
 
    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        GameMechs(GameMechs* gameMechs1);
        bool getExitFlagStatus() const;
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();
 
        char getInput();
        void setInput(char this_input);
        void clearInput();
 
        int getBoardSizeX() const;
        int getBoardSizeY() const;
       
        int getScore(); //removed const
        void incrementScore();
       
        // More methods should be added here
        // void collectAsyncInput();

        // void generateFood(objPos blockOff);
        // objPos getFoodPos() const;

        // GameMechs::GameMechs(int boardX, int boardY) : boardSizeX(boardX), boardSizeY(boardY), score(0), exitFlag(false), loseFlag(false) 
        // {
        // food.setObjPos(boardSizeX / 2, boardSizeY / 2, '*');
        // // generateFood(objPos(boardSizeX / 2, boardSizeY / 2, '*')); // Ensure food doesn't overlap initial position
        // }

        void collectAsyncInput();

        // void generateFood(objPos blockOff);
        // objPos getFoodPos() const;

        // GameMechs::GameMechs(int boardX, int boardY) : boardSizeX(boardX), boardSizeY(boardY), score(0), exitFlag(false), loseFlag(false) 
        // {
        // food.setObjPos(boardSizeX / 2, boardSizeY / 2, '*');
        // generateFood(objPos(boardSizeX / 2, boardSizeY / 2, '*')); // Ensure food doesn't overlap initial position
        // }
      void generateFood(objPos blockoff);
      objPos getFoodPos() const;

};
 
#endif



