#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"
#include "square_matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    int a;
    cin >> a;
    square_matrix<double> sandro(a);
    cin >> sandro;
    cout << sandro.Inversa() << endl;
    //matrix<double> diag(3,3);
    //cin >> diag;
    //cout << sandro.Append(diag).GaussJordan(3).Cut(0,3,3,6) << endl;//aaaa
    




}
//controllo x numeri inseriti
