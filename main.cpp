#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    matrix<double> sandro(3,3);
    cin >> sandro;
    cout << sandro << endl;
    cout << sandro.Gauss() << endl;




}
//controllo x numeri inseriti
