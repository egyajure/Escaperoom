#include "EndChecker.h"
#include <iostream>
//(created fourth)

void endCheck(Square &f, std::string &output, int X, int Y, bool &end, bool optionFound)
{
    //checking if the code has reached the beggining, indicating escape is possible
    if (f.xCoordinate == 1 && f.yCoordinate == 1)
    {
        output = "yes";
        end = true;
        std::cout << "done \n";
    }
    //checking if the code is stuck where it started. indicating escape is not possible
    if (f.xCoordinate == X && f.yCoordinate == Y && optionFound == false)
    {
        output = "no";
        end = true;
        std::cout << "done \n";

    }
    else
    {
        end = false;
    }
}