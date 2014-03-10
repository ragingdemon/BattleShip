#pragma once
#include <string>
#include "coordinate.h"

using std::string;

class Board
{
    int size;
    Coordinate ***matrix;

public:
	Board(int=10);
	~Board();
    Board(const Board& b);
    Coordinate* getCoordinate(const Coordinate &c)const;
    bool setDestroyer(const Coordinate & c, char orientation);
    string toString()const;
};
