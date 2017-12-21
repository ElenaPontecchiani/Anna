#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    matrix<double> sandro(2,2);
    matrix<int> m(2,2);
    cin >> sandro >> m;
    sandro = sandro + m;
    cout << sandro;
    cout << endl;
    cout << sandro.mathOp(pow,2);




}
//controllo x numeri inseriti
