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
    int a;

    cin >> a;
    vector<double> lil_tony(1,a);
    cin >> lil_tony;
    cout << lil_tony << endl;

    cout << lil_tony.Euclidean_norm() << endl << lil_tony.Normalization() << endl;





}
//controllo x numeri inseriti
