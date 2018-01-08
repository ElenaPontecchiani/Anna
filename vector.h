#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

template<class T>

class vector: public matrix<T>{
public:
    vector(int height, int lenght);

    vector<T> operator=(const vector<T>&);

    T Euclidean_norm()const;//ritorna norma euclidea
    vector<T> Normalization()const;//ritorna vettore normalizzato
    bool isRow() const;
    bool isColumn() const;

};


template <class T>
vector<T>::vector(int height, int length):matrix<T>(height,length){}

template <class T>
bool vector<T>::isRow()const{
  return (this->getH() == 1);
}

template <class T>
bool vector<T>::isColumn()const{
  return (!isRow());
}


#include <math.h>
template<class T>
T vector<T>::Euclidean_norm()const{
  T temp = 0;
  for(int i = 0; i < this->getL()*this->getH(); i++)
    temp = temp + pow((*this)[i],2);
  return sqrt(temp);
}

template <class T>
vector<T> vector<T>::Normalization()const{
    vector<T> temp(*this);
    T norm = temp.Euclidean_norm();
      for(int i = 0; i < this->getL()*this->getH(); i++)
        temp[i] = temp[i] / norm;
    return temp;
}








#endif
