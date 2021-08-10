#include <iostream>
#include <vector>
#include "GatherData.cpp"
#include "FindOptions.cpp"
#include "EndChecker.cpp"
//(third made)

int main (){
    //initiallizing variables for the size of the grid
    int X;
    int Y;
    //gathering inputs for variables initalized above
    std::cin >> Y;
    std::cin >> X;
    
    //creating a vector made out of 'squares' (objects of the class Square)
    std::vector <Square> vect;

    //running the modeule 'gatherData' to fill the vector created with values and coordinates
    gatherData (vect, X, Y);

    //test, printing out the contents of vect after gatherData runs to see if it worked
    for(int i=0; i < vect.size(); i++){
        Square o = vect[i]; //gives access to vect[i]
        
        std::cout<< "coordinate: "<< o.xCoordinate << ", "<< o.yCoordinate << "\n";
        std::cout << "value: "<< o.value << "\n";
    }

    Square f = vect[Y*X]; //creating a special object, f, which will be the 'travelling' object
    bool optionFound = false; // creating a bool that will be modified in the 'findoptions module'

    bool end = false;
    float option = 0.5;
    std::string output = " ";


    //now that set up is done ^ the loop below will run until the program ends
    //different from the loop in a loop I am avoiding because this loop does not have a set amount
    while (end == false){
        option = findOptions(vect, f.xCoordinate, f.yCoordinate, optionFound);

        if (optionFound == true){
            //!!insert code for keeping track of past locations to backtrack!!

            //the object then 'travels' to the found option
            f = vect[option];
        }

        //if no option is found, code will change the current value as to not come back, then move backwards
        else {

        }

        //at the end of each loop, the code will check to see if it is done
        endCheck(f, output, X, Y, end);
    }

}