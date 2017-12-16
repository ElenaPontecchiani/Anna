#include "basx.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;


int main(){
    int bs;
    std::string s;

    basex bx1(2.0,10);
    bx1 = 2 * bx1; 
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
