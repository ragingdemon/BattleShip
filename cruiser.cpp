#include "cruiser.h"
#include <typeinfo>

Cruiser::Cruiser() :
    Ship(3)
{

}

Cruiser::Cruiser(const Cruiser &c) :
    Ship(c)
{

}

Cruiser::~Cruiser()
{

}

std::string Cruiser::getType() const
{
    std::string s = typeid(Cruiser).name();
    return s.substr(1);
}
