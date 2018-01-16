#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"
#include "square_matrix.h"
/*#include "diagonal_matrix.h"
#include "scalar_matrix.h"
#include "vector.h"*/

using std::cout;
using std::cin;
using std::endl;


int main(){
    square_matrix<double>* a = new square_matrix<double>(2);
    cin >> *a;
    cout << *(a->matrix<double>::GaussJordan());






}
//controllo x numeri inseriti
