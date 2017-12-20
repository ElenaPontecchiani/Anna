#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    matrix<int> sandro(2,2);
    cin >> sandro;
    cout << endl;
    cout << sandro.mathOp(pow,2);




}
//controllo x numeri inseriti
