#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <memory>

struct coordinate {
    int xCoordinate;
    int yCoordinate;

    coordinate(int x, int y) : xCoordinate(x), yCoordinate(y) {}

    // Define the < operator for coordinate
    bool operator<(const coordinate& other) const {
        if (xCoordinate == other.xCoordinate) {
            return yCoordinate < other.yCoordinate;
        }
        return xCoordinate < other.xCoordinate;
    }
};

enum state { IDLE, MOVING, ATTACK, HURT, DYING, HEAL };

// Declare the operator== for coordinate
bool operator==(const coordinate& lhs, const coordinate& rhs);

#endif
