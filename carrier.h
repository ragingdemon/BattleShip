#pragma once
#include "ship.h"
#include <string>
class Carrier : public Ship
{
public:
    Carrier();
    Carrier(const Carrier & d);
    virtual ~Carrier();
    virtual std::string getType() const;
};
