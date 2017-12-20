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
template <class U>  friend class matrix;

private:
    int h;
    int l;
    T* raw_matrix;//array che tiene conto el

    static T* copyArr(const matrix<T>& m);
    template<class U>
    static T VectProd(const matrix<T>&m1,int row, const matrix<U>&m2, int col);
public:
    matrix(const int& =1,const int& =1);//inizializzato con l=1,h=1
    matrix(const matrix<T>&);//costruttore di copia
    ~matrix();
    matrix<T> operator*(const T&)const;//prodotto con scalare

    template <class U>
    matrix<T> operator*(const matrix<U>&)const;

    //bool sameDim(matrix<U>)
    T& operator[](const int&)const;

    template <class U>
    matrix<T> operator+(const matrix<U>&)const;//somma tra due matrici
    template <class U>
    matrix<T> operator-(const matrix<U>&)const;
    //prodotto tra vettore riga e vettore colonna in vettori
    //trasposta i-riga diventa i col
    matrix<T> Trasposta()const;
    //H-trasp:coniugata+trasposta

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

template <class T>
template <class U>
T matrix<T>::VectProd(const matrix<T>&m1,int row, const matrix<U>&m2, int col){
  T sum = 0;
  std::cout << "R>" << row << "\n";
  std::cout << "C>" << col << "\n";
  for(int i = 0; i < m1.l; i++)
      {sum += m1[i+m1.h*row] * m2[col+m2.l*i];
        std::cout << "Sel1>" << i+m1.h*row << "\n";
        std::cout << "Sel2>" << col+m2.l*i << "\n\n";
      }
  return sum;
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
  for(int i=0; i < m.h * m.l; i++)
    is >> m[i];    //bool sameDim(matrix<U>)
  return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T>& m){
  for(int i = 0; i < m.h; i++){
    for(int j = 0; j < m.l; j++){
      os << m[i*m.l+j] << "\t\t";
    }
    os << std::endl;
  }
  return os;
}

template <class T>
matrix<T> matrix<T>::operator*(const T& n)const{
  //T* t_arr = new T[h*l];
  matrix<T> m(h,l);
  for(int i=0; i < h*l; i++)
    m[i] = (*this)[i]*n;
  return m;
}

template <class T>
T& matrix<T>::operator[](const int& i)const{
  return raw_matrix[i];
}

#include "basxMath.h"
template <class T>
template <class U>
matrix<T> matrix<T>::operator+(const matrix<U>& m)const{
  if(!(l == m.l && h == m.h)){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  matrix<T> temp(h,l);
  for(int i = 0; i < l*h; i++)
    temp[i] = (*this)[i] + m[i];
  return temp;
}

template <class T>
template <class U>
matrix<T> matrix<T>::operator-(const matrix<U>& m)const{
  if(!(l == m.l && h == m.h)){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  matrix<T> temp(h,l);
  for(int i = 0; i < l*h; i++)
    temp[i] = (*this)[i] - m[i];
  return temp;
}

template <class T>
template <class U>
matrix<T> matrix<T>::operator*(const matrix<U>& m)const{
  if(l != m.h){
    std::cout << "VEzzzzzzzzz";
  }
  matrix<T> temp(h,m.l);
  for(int i = 0; i < temp.h; i++)
    for(int j = 0; j < temp.l; j++){
      temp[i*temp.l+j] = VectProd((*this),i,m,j);
    }
  return temp;
}


//////////////////////////////
//   O P E R A Z I O N I    //
//////////////////////////////

template <class T>
matrix<T> matrix<T>::Trasposta()const{
  matrix<T> trans(l,h);
  for(int i = 0; i < h; ++i)
        for(int j = 0; j < l; ++j)
            trans[j*h+i] = (*this)[i*l+j];
  return trans;
}







#endif
