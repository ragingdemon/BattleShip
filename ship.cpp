#include "ship.h"
#include "coordinate.h"
#include <typeinfo>
#include <sstream>

Ship::Ship(unsigned int size) :
    sunk(false),size(size)
{
    ship = new Coordinate*[size];
}

Ship::Ship(const Ship &s) :
    sunk(s.sunk),size(s.size)
{
    ship = new Coordinate*[size];
    for (unsigned int i = 0; i < size; ++i) {
        ship[i] = s.ship[i];
    }
}

Ship::~Ship()
{
    delete[] ship;
}


int Ship::getSize() const
{
    return size;
}


bool Ship::getSunk() const
{
    return sunk;
}

void Ship::setSunk(bool value)
{
    sunk = value;
}

Coordinate **Ship::getShip() const
{
    return ship;
}

void Ship::setShip(unsigned int index, Coordinate *value)
{
    if (index < size) {
        ship[index] = value;
    }
}

std::string Ship::evaluateShot(const Coordinate &c)
{
    if (!sunk) {
        for (unsigned int i = 0; i < size; ++i) {
            if (*ship[i] == c) {
                shipStatus();
                if (sunk) {
                    return "SUNK";
                }else {
                    return "HIT";
                }
            }
        }
    }
    return "MISS";
}

std::string Ship::toString() const
{
    std::stringstream ss;
    ss<<getType()<<": ";
    for (unsigned int i = 0; i < size; ++i) {
        ss<<ship[i]->toString()<<',';
    }
    return ss.str();
}

bool Ship::shipStatus()
{
    unsigned int hits = 0;
    for (unsigned int i = 0; i < size; ++i) {
        if(ship[i]->getHit()){
            hits++;
        }
    }
    if (hits >= size) {
        sunk = true;
    } else {
        sunk = false;
    }
    return sunk;
}
