#include "basx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main(){
    int bs;
    std::string s;
    //basex<double> bx1(10.0,10);
    basex<double> bx1(10.0,10);
    cout << (string)bx1;

    while(true){
        cout << endl << "Numero: ";
        cin >> s;
        cout << "Base: ";
        cin >> bs;
        basex<double> bx1(s,bs);
        for(int i = 2; i < 25; i++){
            bx1.changeBase(i);
            bx1.Print();
        }
    }
}

//controllo x numeri inseriti
