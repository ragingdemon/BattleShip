#ifndef DESTROYER_H
#define DESTROYER_H
#include "ship.h"
class Destroyer : public Ship
{
public:
    Destroyer();
    Destroyer(const Destroyer & d);
    virtual ~Destroyer();
};

#endif // DESTROYER_H
