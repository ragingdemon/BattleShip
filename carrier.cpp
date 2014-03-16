#include "carrier.h"
#include <typeinfo>

Carrier::Carrier() :
    Ship(5)
{

}

Carrier::Carrier(const Carrier &c) :
    Ship(c)
{

}

Carrier::~Carrier()
{

}

std::string Carrier::getType() const
{
    std::string s = typeid(Carrier).name();
    return s.substr(1);
}
