#pragma once
#include "ship.h"
#include <string>
class Battleship : public Ship
{
public:
    Battleship();
    Battleship(const Battleship & b);
    virtual ~Battleship();
    virtual std::string getType() const;
};
