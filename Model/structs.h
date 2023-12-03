#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <memory>

struct coordinate {
    int xCoordinate;
    int yCoordinate;

    coordinate(int x, int y) : xCoordinate(x), yCoordinate(y) {}
};

// Declare the operator== for coordinate
bool operator==(const coordinate& lhs, const coordinate& rhs);

#endif
