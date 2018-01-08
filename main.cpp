#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"
#include "square_matrix.h"
#include "diagonal_matrix.h"
#include "scalar_matrix.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    int a;

    cin >> a;
    diagonal_matrix<double> sandro(a,2);
    //cin >> sandro;
    //matrix<double>* p = &sandro;
    cout << sandro.Det() << endl;

   /* cin >> a;
    square_matrix<double> sandrina(a);
    cin >> sandrina;
    cout << sandrina << endl;

    cout << sandro.Det() << endl << sandrina.Det() << endl;*/





}
//controllo x numeri inseriti
