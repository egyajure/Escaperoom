#include "FindOptions.h"
//(fourth made)

//goal: to take the vector created (not a reference this time just a copy, do not need to edit the vector) and take in the current location of
//.. the travelling object and return an option for the object to travel to.

//problem - functions can only return one thing so instead of returning a variable for the x and y coordinates the object needs to travel to it will..
//..instead return the spot in the vector where the 'square' is

//inputs- vector, current location
//output- location in vector where square is

int findOptions(std::vector<Square> v, int X, int Y, bool &optionFound, Square s)
{
    //before goal was x * Y, only wokred for first 'move'
    int goal = s.xCoordinate * s.yCoordinate;
    float I = 0;
    optionFound = false;

    for (int i = 0; i < v.size(); i++)
    {
        Square o = v[i];
        if (o.value == goal)
        {
            I = i;
            optionFound = true;
        }
    }
    return I;
}