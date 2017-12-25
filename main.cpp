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
    //sandro.divRow(0,2);
    //cout << sandro << endl;
    cout << sandro.GaussJordan(3) << endl;//aaaa
    




}
//controllo x numeri inseriti
