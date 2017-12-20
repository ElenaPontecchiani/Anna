#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    matrix<int> sandro(3,2);
    cin >> sandro;
    cout << sandro;
    cout << endl;
    //cout << sandro.Trasposta();
    matrix<int> m(2,3);
    cin >> m;
    cout << m;
    cout << endl;
    cout << sandro * m;
    /*matrix<double> neo(2,2);
    cin >> neo;
    cout << neo + sandro << endl;
    cout << sandro - neo;*/


}
//controllo x numeri inseriti
