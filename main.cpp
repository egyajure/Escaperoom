#include <iostream>
#include <vector>
#include "GatherData.h"
//(third made)

//moved stuff from 'lastLocation' here
int count;
std::vector<Square> moves;

void keepTrack(Square f)
{
    count++;
    moves.push_back(f);
};

void goBack(std::vector<Square> &vect, Square &f, int option)
{
    f = moves[0];
    //want to delete the first element in the vector
    for (int i = 0; i < count; i++)
    {
        moves[i] = moves[i + 1];
    }
    moves.pop_back();
    count--;
    Square o(0);      //making a square with a value of zero
    vect[option] = o; //replacing current option with the square with the value of zero
};

//moved stuff from endcheck here
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
    
}

//stuff from findOptions here
int findOptions(std::vector<Square> v, int X, int Y, bool &optionFound, Square s)
{
    //before goal was x * Y, only wokred for first 'move'
    int goal = s.xCoordinate * s.yCoordinate;
    float I = 0;
    optionFound = false;

    for (int i = 0; i < v.size(); i++)
    {
        Square o = v[i];
        if (o.value == goal /*new*/ && o.beenSeen == false)
        {
            I = i;
            optionFound = true;
        }
    }
    return I;
}

//*new* function to mark spot in vector as visited

void markVisited (std::vector<Square> &vect, int spot){
    Square a = vect[spot];
    a.beenSeen = true;
    vect[spot] = a;
}

int main()
{
    //initiallizing variables for the size of the grid
    int X;
    int Y;
    //gathering inputs for variables initalized above
    std::cin >> Y;
    std::cin >> X;

    //creating a vector made out of 'squares' (objects of the class Square)
    std::vector<Square> vect;

    //running the modeule 'gatherData' to fill the vector created with values and coordinates
    gatherData(vect, X, Y);

    //test, printing out the contents of vect after gatherData runs to see if it worked
    /*
    for (int i = 0; i < vect.size(); i++)
    {
        Square o = vect[i]; //gives access to vect[i]

        std::cout << "coordinate: " << o.xCoordinate << ", " << o.yCoordinate << "\n";
        std::cout << "value: " << o.value << "\n";
    }
    */

    Square f = vect[Y * X - 1]; //creating a special object, f, which will be the 'travelling' object
    //*new* marking the travelling object as seen before
    f.beenSeen = true;

    bool optionFound = false;   // creating a bool that will be modified in the 'findoptions module'

    bool end = false;
    float option = 0.5;
    std::string output = " ";

    //test for FindOprions.cpp
    /*
    std::cout << "pre-findOptions, optionFound = " << optionFound << "\n";
    option = findOptions(vect, X, Y, optionFound, f);
    std::cout << "post-findOptions, optionFound = " << optionFound << "\n";
    std::cout << "option located is equal to "
              << "vect[" << option << "] \n";

    //printing original coordinates
    std::cout << "original coordinate = " << f.xCoordinate << ", " << f.yCoordinate << "\n";
    std::cout << "original value = " << f.value << "\n";

    //'moving' f
    f = vect[option];

    //printing new coordinate
    std::cout << "new coordinate = " << f.xCoordinate << ", " << f.yCoordinate << "\n";
    std::cout << "new value = " << f.value << "\n";
    */
    //the above test confirmed that f can successfully move to a found option

    //now that set up is done ^ the loop below will run until the program ends
    //different from the loop in a loop I am avoiding because this loop does not have a set amount

    

    while (end == false)
    {
        option = findOptions(vect, f.xCoordinate, f.yCoordinate, optionFound, f);

        if (optionFound == true)
        {
            //the current location is tracked
            keepTrack(f);

            //the object then 'travels' to the found option
            f = vect[option];

            //*new* current option is now marked as visited
            markVisited (vect, option);

            //for keeping track of where the program is at
            std::cout << "new coordinate = " << f.xCoordinate << ", " << f.yCoordinate << "\n";
            std::cout << "new value = " << f.value << "\n";
        }

        //if no option is found, code will change the current value as to not come back, then move backwards
        else
        {
            std::cout << "no option found \n";

            //changes the vector at this location to make the value 0, goes back a step
            goBack(vect, f, option);
        }

        //at the end of each loop, the code will check to see if it is done
        endCheck(f, output, X, Y, end, optionFound);
        std::cout << "endCheck = " << end << "\n";
    }
    std::cout << "end of loop reached\n\n";

    std::cout << output;

    std::cout<< "\npath: ";
    for (int i = 0; i < moves.size(); i++)
    {
        std::cout << moves[i].value;
    }
}