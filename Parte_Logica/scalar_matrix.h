#ifndef SCALARMATRIX_H
#define SCALARMATRIX_H

#include "diagonal_matrix.h" //de ve includere base o il contrario?

template<class T>
class scalar_matrix: public diagonal_matrix<T>{
private:

public:

    scalar_matrix(int, const T& =0);
    virtual T Det ()const;
};



//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template <class T>
scalar_matrix<T>::scalar_matrix(int dim, const T& t): diagonal_matrix<T>(dim,t){}


//////////////////////////////
//   O P E R A Z I O N I    //
//////////////////////////////

#include <math.h>
template<class T>
T scalar_matrix<T>::Det()const{
  return pow((*this)[0],this->getL());
}






#endif