#pragma once

struct Square
{
    int value;
    int xCoordinate;
    int yCoordinate;

    Square(int a);
    void addCoordinate(int x, int y);
};