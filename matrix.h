#ifndef MATRIX_H
#define MATRIX_H

//#include <iostream>
#include "basx.h"

template<class T>
class matrix{
template <class U>
  friend std::istream& operator>>(std::istream& is, matrix<U>& m);
template <class U>
  friend std::ostream& operator<<(std::ostream& os, const matrix<U>& m);

private:
    int h;
    int l;
    T* raw_matrix;//array che tiene conto el

    static T* copyArr(const matrix<T>& m);
public:
    matrix(const int& =1,const int& =1);//inizializzato con l=1,h=1
    matrix(const matrix<T>&);//costruttore di copia
    ~matrix();
    matrix<T> operator*(const T&)const;//prodotto con scalare
    matrix<T> operator+(const matrix<T>&)const;//somma tra due matrici
    //prodotto tra vettore riga e vettore colonna in vettori
    //trasposta i-riga diventa i col
    /*matrix Trasposta()const;
    //coniugata: cambio segno pt img
    matrix Coniugata()const;
    //H-trasp:coniugata+trasposta
    matrix H_trasposta()const;*/

};

template<class T>
std::istream& operator>>(std::istream& is, matrix<T>& m);

template<class T>
std::ostream& operator<<(std::ostream& os, const matrix<T>& m);


//////////////////////////////
//     S T A T I C H E      //
//////////////////////////////

template <class T>
T* matrix<T>::copyArr(const matrix<T>& m){
  T* t_arr = new T[m.h*m.l];
  for(int i = 0; i < m.h * m.l; i++)
    t_arr[i] = m.raw_matrix[i];
  return t_arr;
}



//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template <class T>
matrix<T>::matrix(const int& height,const int& length):
    h(height),l(length),raw_matrix(new T[length*height]){}

template <class T>
matrix<T>::matrix(const matrix<T>& m):h(m.h),l(m.l),raw_matrix(copyArr(m)){}

template<class T>
matrix<T>::~matrix(){
  delete[] raw_matrix;
}

//////////////////////////////
//   OP  O V E R L O A D    //
//////////////////////////////

template<class T>
std::istream& operator>>(std::istream& is, matrix<T>& m){
  T t;
  for(int i=0; i < m.h * m.l; i++){
    is >> t;
    m.raw_matrix[i] = t;
  }
  return is;
}
template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T>& m){
  for(int i = 0; i < m.h; i++){
    for(int j = 0; j < m.l; j++){
      os << m.raw_matrix[i*m.l+j] << " ";
    }
    os << std::endl;
  }
  return os;
}

template <class T>
matrix<T> matrix<T>::operator*(const T& n)const{
  T* t_arr = new T[h*l];
  for(int i=0; i < h*l; i++)
    t_arr[i] = raw_matrix[i]*n;
  matrix<T> m(h,l);
  m.raw_matrix = t_arr;
  return m;
}

#include "basxMath.h"
template <class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m)const{
  int lm = min(l,m.l);
  int hm = min(h,m.h);

  for(int i = 0; i < hm; i++){
    for(int j = 0; j < lm; j++){
      
    }
  }
}



#endif
