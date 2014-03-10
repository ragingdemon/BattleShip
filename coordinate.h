#pragma once
#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;

class CoorditeExceptio : public invalid_argument{
public:
    CoorditeExceptio():invalid_argument("Coordinate exception"){}
};

class Coordinate
{
    char row;
    int column;
    bool ship;
    bool hit;
public:
    Coordinate(string coordinate);
    Coordinate(const Coordinate & c);
    bool evaluate(const Coordinate & c);
    int getRow()const;
    char getRowChar()const;
    int getColumn()const;
    void setShip(bool ship);
    void setHit(bool hit);
    bool getShip()const;
    bool getHit()const;
    string toString()const;
    bool operator ==(const Coordinate &c);
    bool operator !=(const Coordinate &c);
};
