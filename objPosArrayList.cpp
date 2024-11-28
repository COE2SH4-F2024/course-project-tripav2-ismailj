#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;        // Setting array max capacity
    aList = new objPos[arrayCapacity];   // allocating memeory for array
    listSize = 0;                        // Initial sizze of list is 0
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // Deallocating heap mem
}

int objPosArrayList::getSize() const
{
    return listSize; // Returning current size oflist
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity)
        return; // (if array is full -> nothing)

    // Shifting all elements to the right (for making room @ head)
    for (int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1];
    }

    aList[0] = thisPos; // insert new character to head
    listSize++;         // Incrementing size of lsit
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity)
        return; // Doing nothing if array full

    aList[listSize] = thisPos; // Adding character to the end of the list
    listSize++;                // Incrementing sizelist
}

void objPosArrayList::removeHead()
{
    if (listSize == 0)
        return; // if list is mempty do nothgin

    // Shiftong all elements to the left (to remove the head)
    for (int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i + 1];
    }

    listSize--; // Decrementoing the list size
}

void objPosArrayList::removeTail()
{
    if (listSize == 0)
        return; // nothing if list emoty

    listSize--; // Decrement list size
}

objPos objPosArrayList::getHeadElement() const
{
    if (listSize == 0)
        return objPos(); // Return default objPos if the list is empty

    return aList[0]; // Return first element
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize == 0)
        return objPos(); // Return default objPos if the list is empty

    return aList[listSize - 1]; // Returnlast element
}

objPos objPosArrayList::getElement(int index) const
{
    if (index < 0 || index >= listSize)
        return objPos(); // Return default objPos for invalid indices

    return aList[index]; // Returnelement at the specified index
}