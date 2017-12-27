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


//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template <class T>
vector<T>::vector(const int& dim): matrix<T>(dim,1){}

template <class T>
vector<T>::vector(const matrix<T>& m): matrix<T>(m){}



//////////////////////////////
//  M E T O D I   V A R I   //
//////////////////////////////

template <class T>
T vector<T>::Euclidean_norm()const{
    T t=0;
    for(int i=0;i<(this->getH());i++){
        t+=this->raw_matrix[i]; //?
    }
    return sqrt(t);
}



template <class T>
vector<T> vector<T>::Normalization()const{
    vector<T> temp((this->getH()),1);
    temp=*this;
    for(int i=0;i<(this->getH());i++){
        temp->raw_matrix[i]=(temp->raw_matrix[i])/(temp.Euclidean_norm());
    }
    return temp;
}





#endif