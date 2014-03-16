
#include <iostream>
#include "coordinate.h"
#include "board.h"
#include "destroyer.h"
#include "cruiser.h"
#include "battleship.h"
#include "carrier.h"
#include <vector>
#include <string>
#include <sstream>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
using namespace std;
void setAllShips(Board *board);
template<class T>
void setShip(Board *board);
void setAllRandom(Board *board);
template<class T>
void setRandomShip(Board *board);
bool turn(Board *board);

int main(int argc,char* argv[])
{
    srand(time(0));
    Board *board1 = new Board();
    Board *board2 = new Board();
    setAllRandom(board1);
    setAllRandom(board2);
//    cout<<(board1->printShips())<<endl;
//    cout<<(board2->printShips())<<endl;
    do{
        cout<<board1->toString()<<endl;
        cout<<board2->toString()<<endl;
        cout<<"turno del jugador 1"<<endl;
        while(!turn(board2));
        if (board2->status() != "OK") {
            cout<<"ganador jugador 1"<<endl;
            break;
        }
        cout<<"turno del jugador 2"<<endl;
        while(!turn(board1));
        if (board1->status() != "OK") {
            cout<<"ganador jugador 2"<<endl;
            break;
        }
    }while(1);

    if (board1) {
        delete board1;
    }
    if (board2) {
        delete board2;
    }
    return 0;
}

void setAllShips(Board *board)
{
    setShip<Destroyer>(board);
    setShip<Cruiser>(board);
    setShip<Battleship>(board);
    setShip<Carrier>(board);
}

template<class T>
void setShip(Board *board)
{
    string srt;
    char orientation;
    bool flag = false;
    do{
        cout<<board->toString()<<endl;
        srt = "";
        orientation = 'v';
        cout<<"Ingrese la coordenada para "<<T().getType()<<": ";
        cin>>srt;
        cout<<"Ingrese orientasion(v/h): ";
        cin>>orientation;
        try {
            Coordinate coordinate(srt);
            flag = board->setShip<T>(coordinate,orientation);
        } catch (CoorditeExceptio &e) {
            cout<<e.what()<<endl;
        }
    }   while(!flag);
}

void setAllRandom(Board *board)
{
    setRandomShip<Destroyer>(board);
    setRandomShip<Cruiser>(board);
    setRandomShip<Battleship>(board);
    setRandomShip<Carrier>(board);
}

template<class T>
void setRandomShip(Board *board){
    bool flag = false;
    do{
        char orientation = 'v';
        if (rand() % 2) {
            orientation = 'v';
        } else {
            orientation = 'h';
        }
        try {
            stringstream ss;
            ss<<(char)(rand()%(75-65) + 65)<<','<<rand()%10;
            Coordinate coordinate(ss.str());
            flag = board->setShip<T>(coordinate,orientation);
        } catch (CoorditeExceptio &e) {
            cout<<e.what()<<endl;
        }
    }   while(!flag);
}

bool turn(Board *board)
{
        string srt;
        cout<<"Ingrese coordenada: "<<": ";
        cin>>srt;
        try {
            Coordinate coordinate(srt);
            cout<<board->evaluateShot(coordinate)<<endl;
            return true;
        } catch (CoorditeExceptio &e) {
            cout<<e.what()<<endl;
            return false;
        }
}
