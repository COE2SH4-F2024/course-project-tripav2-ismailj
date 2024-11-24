#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos();
        objPos(int xPos, int yPos, char sym);
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        
        objPos(const objPos &other); //cpy constructor
        objPos& operator = (const objPos &other); //cpy assignment operator
        ~objPos();
        void gameboard();
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        //copy constructor and assingmemnt operator
        objPos(const objPos& other);            
        objPos& operator=(const objPos& other); 
        ~objPos(); 

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif