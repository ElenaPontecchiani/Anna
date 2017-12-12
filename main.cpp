#include "basx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main(){
    basex<double> bx1(34.0,10);
    basex<double> bx2("1A,4",16);
    basex<double> bx3(bx1,2);

    bx1.Print();
    bx2.Print();
    bx3.Print();
}
