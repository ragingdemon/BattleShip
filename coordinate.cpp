#include "coordinate.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
Coordinate::Coordinate(string str)
{
    //cout<<str<<endl;
    if (str.size() < 3) {
        throw CoorditeExceptio();
    }
    row = toupper(str[0]);
    //cout<<str.substr(2)<<endl;
    stringstream convert(str.substr(2)); // stringstream used for the conversion initialized with the contents of Text
    if ( !(convert >> column) )//give the value to Result using the characters in the string
        throw CoorditeExceptio();
    column--;
    ship = false;
    hit = false;
    if ((getRow() < 0 || getRow() > 25) || (column < 0 || column > 25)) {
        throw CoorditeExceptio();
    }
}

int Coordinate::getRow() const
{
    return row - 65;
}

char Coordinate::getRowChar() const
{
    return row;
}

int Coordinate::getColumn() const
{
    return column;
}

void Coordinate::setShip(bool ship)
{
	this->ship = ship;
}

void Coordinate::setHit(bool ship)
{
	this->hit = hit;
}

bool Coordinate::getShip()const
{
	return ship;
}

bool Coordinate::getHit()const
{
	return hit;
}

string Coordinate::toString() const
{
    stringstream ss;
    ss<<'('<<row<<','<<column + 1<<')';
    ss<<"Row = "<<getRow()<<", Column = "<<getColumn();
    return ss.str();
}

bool Coordinate::operator==(const Coordinate &c)
{
    if (row == c.row && column == c.column) {
        return true;
    }
    return false;
}

bool Coordinate::operator!=(const Coordinate &c)
{
    return !(*this == c);
}
