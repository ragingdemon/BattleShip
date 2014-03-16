#pragma once
#include "ship.h"
#include <string>
class Destroyer : public Ship
{
public:
    Destroyer();
    Destroyer(const Destroyer & d);
    virtual ~Destroyer();
    virtual std::string getType() const;
};
