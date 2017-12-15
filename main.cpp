#include "basx.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;


int main(){
    int bs;
    std::string s;
    //basex<double> bx1(10.0,10);
    basex bx1(2.0,10);
    //cout << (string)bx1;
    bx1 = bx1 + 4;

    cout << bx1;

    while(true){
        cout << endl << "Numero: ";
        cin >> s;
        cout << "Base: ";
        cin >> bs;
        basex bx1(s,bs);
        for(int i = 2; i < 25; i++){
            bx1.changeBase(i);
            //bx1.Print();
            cout << bx1 << endl;
        }
    }
}

//controllo x numeri inseriti
