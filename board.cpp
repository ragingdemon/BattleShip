#include "board.h"
#include "coordinate.h"
#include "destroyer.h"
#include "cruiser.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::setw;

//template <class T>
//bool setShip(const Coordinate &c, char orientation);

Board::Board(int size)
{
    this->size = size;
    matrix = new Coordinate**[size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new Coordinate*[size];
    }
    int letters = 65;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            string s;
            try {
                stringstream ss;
                ss<<(char)(letters + i)<<','<<j+1;
                s = ss.str();
                matrix[i][j] = new Coordinate(ss.str());
            } catch (CoorditeExceptio &e) {
                cout<<e.what()<<endl;
                cout<<"matriz["<<i<<']'<<'['<<j<<']'<<"= "<<s<<endl;
            }
        }
    }
}


Board::~Board(){
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[i][j])
            {
                delete matrix[i][j];
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        delete matrix[i];
    }
    delete[] matrix;

    for (unsigned int i = 0; i < ships.size(); ++i) {
        delete ships[i];
    }
}

Board::Board(const Board &b) : size(b.size)
{
    matrix = new Coordinate**[size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new Coordinate*[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = new Coordinate(*b.matrix[i][j]);
        }
    }
}

Coordinate* Board::getCoordinate(const Coordinate &c) const
{
    if (c.getRow() >= size || c.getColumn() >= size) {
        throw CoorditeExceptio();
    }
    return matrix[c.getRow()][c.getColumn()];
}

string Board::evaluateShot(const Coordinate &c)
{
    string message;
    stringstream ss;
    if (matrix[c.getRow()][c.getColumn()]->shoot()) {
        for (unsigned int i = 0; i < ships.size(); ++i) {
            Ship *ship = ships[i];
            message = ship->evaluateShot(c);
            if (message == "HIT") {
                ss<<message<<':'<<ship->getType();
                return ss.str();
            }else if (message == "SUNK") {
                ss<<message<<':'<<ship->getType();
                return ss.str();
            }
        }
    }
    return "MISS";
}

std::string Board::status() const
{
    unsigned int sunkShips = 0;
    for (unsigned int i = 0; i < ships.size(); ++i) {
        Ship *ship = ships[i];
        if (ship->getSunk()) {
            sunkShips++;
        }
    }
    if (sunkShips == ships.size()) {
        return "LOST";
    }
    return "OK";
}

string Board::printShips() const
{
    stringstream ss;
    for (unsigned int i = 0; i < ships.size(); ++i) {
        ss<<ships[i]->toString()<<endl;
    }
    return ss.str();
}

string Board::toString() const
{
    stringstream ss;
    int letters = 65;
    ss<<' ';
    for (int i = 0; i < size; ++i) {
        ss<<setw(4)<<i+1;
    }
    ss<<endl;
    for (int i = 0; i < size; ++i) {
        ss<<(char)(letters + i);
        for (int j = 0; j < size; ++j) {
            if (!matrix[i][j]->getHit() && !matrix[i][j]->getShip()) {
                ss<<setw(4)<<'-';
            }else if (matrix[i][j]->getHit() && !matrix[i][j]->getShip()) {
                ss<<setw(4)<<'M';
            }else if (!matrix[i][j]->getHit() && matrix[i][j]->getShip()) {
                ss<<setw(4)<<'S';
            }else if (matrix[i][j]->getHit() && matrix[i][j]->getShip()) {
                ss<<setw(4)<<'X';
            }
        }
        ss<<endl;
    }
    return ss.str();
}
