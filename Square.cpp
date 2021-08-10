#pragma once
#include <iostream>
//(created first)
//goal: create a class so it's objects can be included in a vector created in the gatherdata module
//the class represents each 'square' in the grid where each square holds a value and coordinates

struct Square {
   
    int value;
    int xCoordinate;
    int yCoordinate;

    Square (int a){ //constructor, runs when an object is made
        value = a;
    }
    void addCoordinate (int x, int y){
        xCoordinate= x;
        yCoordinate = y;
    }
};