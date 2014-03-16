#include "battleship.h"
#include <typeinfo>

Battleship::Battleship() :
    Ship(4)
{

}

Battleship::Battleship(const Battleship &b) :
    Ship(b)
{

}

Battleship::~Battleship()
{

}

std::string Battleship::getType() const
{
    std::string s = typeid(Battleship).name();
    return s.substr(2);
}
