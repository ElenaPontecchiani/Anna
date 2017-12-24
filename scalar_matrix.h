#ifndef SCALARMATRIX_H
#define SCALARMATRIX_H

#include "diagonal_matrix.h" //de ve includere base o il contrario?

template<class T>
class scalar_matrix: public diagonal_matrix{
private: 

public:


    scalar_matrix(const T&=0,const T&=0);//in input el diag ()che è sempre uguale e dim==n el diag
    scalar_matrix(const T&=0,const T&=0,const int&=0);
    T Determinante ()const;

    scalar_matrix<T> operator+(const scalar_matrix<T>&)const;
    scalar_matrix<T> operator-(const scalar_matrix<T>&)const;
    scalar_matrix<T> operator*(const scalar_matrix<T>&)const;
    scalar_matrix<T> operator*(const T&)const;
};



//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template <class T>
scalar_matrix<T>::scalar_matrix(const int& dim):
    *this(diagonal_matrix<T>(dim,dim)){
    } 


template <class T>
scalar_matrix<T>::scalar_matrix(const int& dim,const int& el)://secondo costruttore che prende in input anche el da mettere su diag
    *this(diagonal_matrix<T>(dim,dim)){
       for(int i=0;i<dim^2;i++){
        if(onDiagonal(dim,i)){//se è sulla diagonale mettere el?
          raw_matrix[i]=el;
        }
        else{raw_matrix[i]=0;}
      }
    }

    
//////////////////////////////
//   O P E R A Z I O N I    //
//////////////////////////////

template<class T>
T scalar_matrix<T>::Determinante()const{
return raw_matrix[0]*h;
}



//////////////////////////////
//   OP  O V E R L O A D    //
//////////////////////////////

#include "basxMath.h"
template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator+(const diagonal_matrix<T>& m)const{
  if(!(*this.dimensions(m))){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  diagonal_matrix<T> temp(h,l);
  T t=raw_matrix[0]+m.raw_matrix[0];//el tt uguali da mettere sulla diag risultante
  for(int i = 0; i < l*h; i++){
    if(onDiagonal(h^2,i))
    {temp[i] = t;}
    else{temp[i] =0;}
}
  return temp;
}



template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator-(const diagonal_matrix<T>& m)const{
  if(!(*this.dimensions(m))){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  diagonal_matrix<T> temp(h,l);
  T t=raw_matrix[0]-m.raw_matrix[0];//el tt uguali da mettere sulla diag risultante
  for(int i = 0; i < l*h; i++){
    if(onDiagonal(h^2,i))
    {temp[i] = t;}
    else{temp[i] =0;}
}
  return temp;
}



template <class T>
scalar_matrix<T> scalar_matrix<T>::operator*(const T& w)const{
  if(!(*this.dimensions(m))){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
 scalar_matrix<T> temp(h,l);
  T t=raw_matrix[0]*w;//el tt uguali da mettere sulla diag risultante
  for(int i = 0; i < l*h; i++){
    if(onDiagonal(h^2,i))
    {temp[i] = t;}
    else{temp[i] =0;}
}
  return temp;
}


template <class T>
scalar_matrix<T> scalar_matrix<T>::operator*(const scalar_matrix<T>& m)const{
  iff(!(*this.dimensions(m))){//il metodo si può invocare anche qui tanto sono quadrate
    std::cout << "dim sbagliate";
  }
  scalar_matrix<T> temp(h,h);
  T t=raw_matrix[0]*m.raw_matrix[0];
  for(int i = 0; i < h^2; i++){
    if(onDiagonal(h^2,i))
    {temp[i] =t;}
    else {temp[i] =0;}
    }
  return temp;
}



#endif