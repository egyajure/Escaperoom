
#include "GatherData.h"
#include <iostream>
//(created second)

//goal: to create a function that reads input and stores it in a vector, returns nothing

void gatherData(std::vector<Square> &vect, int x, int y)
{ //creates a reference to the vector "vect" which holds Squares
    int xCoordinate = 1;
    int yCoordinate = 1;

    for (int i = 0; i < x * y; i++)
    { //looping through each value

        int value = 0;

        //gathering input for value, and making an object
        std::cin >> value;
        Square o(value);

        //code for adding coordinates to the vector
        o.addCoordinate(xCoordinate, yCoordinate);

        //adding the object to the vector
        vect.push_back(o);

        //what controls the 'looping' of x and y coordinates
        if (xCoordinate == x)
        {
            xCoordinate = 1;
            yCoordinate = yCoordinate + 1;
        }
        else
        {
            xCoordinate++;
        }
    }
}
