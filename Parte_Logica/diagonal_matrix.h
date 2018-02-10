#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "square_matrix.h"

template<class T>
class diagonal_matrix: public square_matrix<T>{
private:

public:

    diagonal_matrix(int);
    diagonal_matrix(int,const T& t);
    diagonal_matrix(const matrix<T>& t);
    diagonal_matrix<T>* clone()const;


    diagonal_matrix<T> operator+(const diagonal_matrix<T>&)const;
    diagonal_matrix<T> operator-(const diagonal_matrix<T>&)const;
    diagonal_matrix<T> operator*(const diagonal_matrix<T>&)const;
    virtual matrix<T> operator*(const T&)const;

    virtual T Det ()const;
    virtual void Trasposta();
    virtual void Gauss(int col_num =-1);
    virtual void GaussJordan(int col_num =-1);

    void setDiag(const T& t);



};






//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////


template <class T>
diagonal_matrix<T>::diagonal_matrix(int dim): square_matrix<T>(dim){}

template <class T>
diagonal_matrix<T>::diagonal_matrix(int dim, const T& t): square_matrix<T>(dim){
  (*this).Fill(0);
  for(int i = 0; i < dim; i++)
    (*this)[i*dim+i] = t;
}

template <class T>
diagonal_matrix<T>::diagonal_matrix(const matrix<T>& t): square_matrix<T>(t){}

//////////////////////////////
//  O P   O V E R L O A D   //
//////////////////////////////

template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator+(const diagonal_matrix<T>& dm)const{
  diagonal_matrix<T> temp(*this);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = temp[i*this->getL()+i] + dm[i*this->getL()+i];
  return temp;
}

template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator-(const diagonal_matrix<T>& dm)const{
  diagonal_matrix<T> temp(*this);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = temp[i*this->getL()+i] - dm[i*this->getL()+i];
  return temp;
}

template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator*(const diagonal_matrix<T>& dm)const{
  diagonal_matrix<T> temp(this->getL());
  temp.Fill(0);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = (*this)[i*this->getL()+i] * dm[i*this->getL()+i];
  return temp;
}

template <class T>
matrix<T> diagonal_matrix<T>::operator*(const T& t)const{
  diagonal_matrix<T> temp(*this);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = temp[i*this->getL()+i] * t;
  return temp;
}

//////////////////////////////
//  O P E R A Z I O N I     //
//////////////////////////////

template <class T>
T diagonal_matrix<T>::Det()const{
  T t = 1;
  for(int i = 0; i < this->getL(); i++)
    t = (*this)[i*this->getL()+i] * t;
  return t;
}

template <class T>
void diagonal_matrix<T>::Trasposta(){}

template <class T>
void diagonal_matrix<T>::Gauss(int col_num){
  setDiag(1);
}

template <class T>
void diagonal_matrix<T>::GaussJordan(int col_num){
  setDiag(1);
}

template <class T>
void diagonal_matrix<T>::setDiag(const T& t){
  for(int i = 0; i < this->getL(); i++)
    this[i + this->getL()*i] = t;
}

template <class T>
diagonal_matrix<T>* diagonal_matrix<T>::clone() const{
  return (new diagonal_matrix<T>(*this));
}




#endif
