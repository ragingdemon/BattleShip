#include "destroyer.h"
#include <typeinfo>

Destroyer::Destroyer() :
    Ship()
{

}

Destroyer::Destroyer(const Destroyer &d) :
    Ship(d)
{

}

Destroyer::~Destroyer()
{

}

std::string Destroyer::getType() const
{
    std::string s = typeid(Destroyer).name();
    return s.substr(1);
}
