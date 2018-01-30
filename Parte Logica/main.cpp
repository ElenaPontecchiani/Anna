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
    int x;
    cin >> x;
    matrix<double>* a = new diagonal_matrix<double>(3);
    cout << dynamic_cast<square_matrix<double>*>(a);





}
//controllo x numeri inseriti
