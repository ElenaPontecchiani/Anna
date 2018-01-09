#include "basx.h"
#include <iostream>
#include <math.h>
#include "matrix.h"
#include "square_matrix.h"
#include "diagonal_matrix.h"
#include "scalar_matrix.h"
#include "vector.h"

using std::cout;
using std::cin;
using std::endl;


int main(){
    matrix<double> a(2,2);
    cin >> a;
    cout << a.mathOp(pow,0.5);






}
//controllo x numeri inseriti
