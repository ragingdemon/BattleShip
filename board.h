#pragma once
#include <string>
#include "coordinate.h"
#include "ship.h"
#include <vector>
using std::string;
using std::vector;

class Board
{
    int size;
    Coordinate ***matrix;
    vector<Ship*> ships;
public:
	Board(int=10);
	~Board();
    Board(const Board& b);
    Coordinate* getCoordinate(const Coordinate &c)const;
    string evaluateShot(const Coordinate &c);
    string status()const;
    string printShips()const;
    string toString()const;
    template <class T>
    bool setShip(const Coordinate &c, char orientation)
    {
        orientation = toupper(orientation);
        int row = c.getRow();
        int column = c.getColumn();
        Ship *ship = new T();
        if (orientation == 'V') {
            if (row + ship->getSize() > size) {
                delete ship;
                return false;
            }
            for (int i = row; i < row + ship->getSize(); ++i) {
                if (matrix[i][column]->getShip()) {
                    delete ship;
                    return false;
                }
            }
            for (int i = row; i < row + ship->getSize(); ++i) {
                matrix[i][column]->setShip(true);
                ship->setShip(i-row,matrix[i][column]);
            }
            ships.push_back(ship);
            return true;
        }else if (orientation == 'H') {
            if (column + ship->getSize() > size) {
                delete ship;
                return false;
            }
            for (int i = column; i < column + ship->getSize(); ++i) {
                if (matrix[row][i]->getShip()) {
                    delete ship;
                    return false;
                }
            }
            for (int i = column; i < column + ship->getSize(); ++i) {
                matrix[row][i]->setShip(true);
                ship->setShip(i-column,matrix[row][i]);
            }
            ships.push_back(ship);
            return true;
        }
        delete ship;
        return false;
    }
};
