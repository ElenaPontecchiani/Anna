#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

template<class T>

class vector: public matrix<T>{
private:

public:

    vector(const int & =1);

    vector(const matrix<T>&);//?

    T Euclidean_norm()const;//ritorna norma euclidea

    vector<T> Normalization()const;//ritorna vettore normalizzato

};






#endif