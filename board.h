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
	Board(const Board&);
    Coordinate* getCoordinate(const Coordinate &c)const;
    string toString()const;
};
