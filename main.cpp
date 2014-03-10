
#include <iostream>
#include "coordinate.h"
#include "board.h"
#include <vector>
using namespace std;

void copia(Board b){
    cout<<b.toString()<<endl;
}

int main(int argc,char* argv[])
{
    vector<Coordinate> v;
    try {
        Coordinate a("c,3"), b("B,2"), c("C,3");
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        cout << a.toString()<< endl;
        cout << b.toString()<< endl;
        cout << c.toString()<< endl;
        cout << (a == c) << endl;
        cout << (a == b) << endl;
        cout << (a != b) << endl;
        cout << (a != c) << endl;
        //cout<<;
    } catch (CoorditeExceptio &e) {
        cout<<e.what()<<endl;
    }
    Board board1;
    cout<<board1.toString()<<endl;
    copia(board1);
    cout<<(board1.getCoordinate(Coordinate("B,5"))->toString())<<endl;
    return 0;
}

