#pragma once
#include "coordinate.h"
#include <string>
class Ship
{
    bool shipStatus();
protected:
    bool sunk;
    unsigned int size;
    Coordinate **ship;
public:
    Ship(unsigned int size = 2);
    Ship(const Ship &s);
    virtual ~Ship();
    Coordinate **getShip() const;
    void setShip(unsigned int index,Coordinate *value);
    int getSize() const;
    bool getSunk() const;
    void setSunk(bool value);
    std::string evaluateShot(const Coordinate &c);
    virtual std::string getType() const=0;
    virtual std::string toString()const;
};
