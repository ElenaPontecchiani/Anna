#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    /*basex bx1(2.0,10);
    bx1 = 2 * bx1;
    cout << bx1 << endl << endl;

    while(true){
        cin >> bx1;
        for(int i = 2; i < 25; i++){
            bx1.changeBase(i);
            cout << bx1 << endl;
        }
    }*/
    matrix<int> sandro(1,2);
    cin >> sandro;
    cout << sandro;
    cout << endl;
    cout << sandro*0.5;

}
//controllo x numeri inseriti
