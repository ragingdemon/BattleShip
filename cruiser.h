#pragma once
#include "ship.h"
#include <string>
class Cruiser : public Ship
{
public:
    Cruiser();
    Cruiser(const Cruiser & c);
    virtual ~Cruiser();
    virtual std::string getType() const;
};
