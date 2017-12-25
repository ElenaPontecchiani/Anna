#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    int a;
    int b;
    cin >> a;
    cin >> b;
    matrix<double> sandro(a,b);
    cin >> sandro;
    cout << sandro << endl;
    matrix<double> diag(3,3);
    cin >> diag;
    cout << sandro.Append(diag) << endl;//aaaa
    




}
//controllo x numeri inseriti
