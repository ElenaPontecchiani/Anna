#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "basx.h"
#include "square_matrix.h"

template<class T>
class matrix{
/*  Cosa vuol dire sta cosa?
 *  Tutte le istanze di questi overload sono amiche della classe matrice,
 *  indipendentemente dal tipo U che matrix contiene.
 */
template <class U>
  friend std::istream& operator>>(std::istream& is, matrix<U>& m);
template <class U>
  friend std::ostream& operator<<(std::ostream& os, const matrix<U>& m);

private:
    int h;
    int l;
    T* raw_matrix;//array che tiene conto el

    //Fa una deep copy di un array (raw_matrix) da una matrice m, e ne torna
    //il puntatore
    static T* copyArr(const matrix<T>& m);

    //Esegue il prodotto vettoriale fra due vettori estrapolati da matrici
    //sulla riga row e colonna col
    static T VectProd(const matrix<T>&m1,int row, const matrix<T>&m2, int col);

public:
    int getH()const;
    int getL()const;

    //Ridefinizione dei big 3 ££$$$€€€€
    matrix(const int& =1,const int& =1);//inizializzato con l=1,h=1
    matrix(const matrix<T>&);//costruttore di copia
    virtual ~matrix();

    //Operatori Matematici fra matrici
    matrix<T>& operator=(const matrix<T>&);
    matrix<T> operator+(const matrix<T>&)const;
    matrix<T> operator-(const matrix<T>&)const;
    matrix<T> operator*(const matrix<T>&)const;
    bool sameDim(const matrix<T>&)const;
    virtual bool hasDet()const;
    virtual bool isInvertible()const;

    //Operazioni generali su matrici
    virtual matrix<T> Trasposta()const;
    virtual matrix<T> Gauss(int col_num =-1)const;
    virtual matrix<T> GaussJordan(int col_num =-1)const;
    virtual square_matrix<T> Inversa()const;
    virtual T Det()const;

    //Metodi di taglia-cuci per matrici
    void Fill(const T& t);
    matrix<T> Cut(int row_start, int row_num, int col_start, int col_num)const;
    matrix<T> Append(const matrix<T>& m1)const;

    //Metodi utili per l'el. di Gauss
    void swap(int r1, int r2);
    void divRow(int r, T coeff);
    int maxCoeff(int now_row, int now_col)const;
    void subRow(int r1,int r2, T coeff =1);
    void approxZero();

    //Funzioni scalari che si applicano elemento per elemento
    virtual matrix<T> operator*(const T&)const;//prodotto con scalare
    matrix<T> mathOp(double (*function)(double));
    matrix<T> mathOp(double (*function)(double,double),const double&);

    //Operatore di selezione di un elemento nell'array
    T& operator[](const int&)const;

    //Operatore di ugualianza
    bool operator==(const matrix<T>&)const;

    //Operatore di conversione fra vari tipi di matrice
    //Il template class U è necessario perchè voglio rendere
    //la conversione disponibile con ogni tipo di matrice
    template <class U>
    operator matrix<U>();

};

template<class T>
std::istream& operator>>(std::istream& is, matrix<T>& m);

template<class T>
std::ostream& operator<<(std::ostream& os, const matrix<T>& m);

template<class T>
int matrix<T>::getH()const{ return h;}

template<class T>
int matrix<T>::getL()const{ return l;}

//////////////////////////////
//     S T A T I C H E      //
//////////////////////////////

template <class T>
T* matrix<T>::copyArr(const matrix<T>& m){
  T* t_arr = new T[m.h*m.l];
  for(int i = 0; i < m.h * m.l; i++)
    t_arr[i] = (T)m.raw_matrix[i];
  return t_arr;
}

template <class T>
T matrix<T>::VectProd(const matrix<T>&m1,int row, const matrix<T>&m2, int col){
  T sum = 0;
  for(int i = 0; i < m1.l; i++)
      sum += m1[i+m1.l*row] * m2[col+m2.l*i];
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
    is >> m[i];
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
matrix<T> matrix<T>::operator+(const matrix<T>& m)const{
  if(!(*this).sameDim(m)){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  matrix<T> temp(h,l);
  for(int i = 0; i < l*h; i++)
    temp[i] = (*this)[i] + m[i];
  return temp;
}

template <class T>
matrix<T> matrix<T>::operator-(const matrix<T>& m)const{
  if(!(*this).sameDim(m)){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  matrix<T> temp(h,l);
  for(int i = 0; i < l*h; i++)
    temp[i] = (*this)[i] - m[i];
  return temp;
}

template <class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m)const{
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

template <class T>
bool matrix<T>::operator==(const matrix<T>& m)const{
  if(!(*this).sameDim(m))
    return false;
  int i = 0;
  while(i < l*h){
    if((*this)[i] != m[i])
      return false;
    i++;
  }
  return true;
}

template <class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m){
    if (this == &m)
        return *this;
    T* p = raw_matrix;
    delete[] p;
    l = m.l;
    h = m.h;
    raw_matrix = copyArr(m);
    return (*this);
}

template <class T>
template <class U>
matrix<T>::operator matrix<U>(){
  matrix<U> temp(h,l);
  for(int i = 0; i < l*h; i++)
    temp[i] = (*this)[i];
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

template <class T>
matrix<T> matrix<T>::mathOp(double (*function)(double)){
    matrix<T> temp(h,l);
    for(int i = 0; i < l*h; i++)
        temp[i] = (*function)((*this)[i]);
    return temp;
}

template <class T>
matrix<T> matrix<T>::mathOp(double (*function)(double,double),const double& d){
    matrix<T> temp(h,l);
    for(int i = 0; i < l*h; i++)
        temp[i] = (*function)((*this)[i],d);
    return temp;
}

template <class T>
void matrix<T>::swap(int r1, int r2){
  if (r1 != r2){
    T temp;
    for(int c = 0; c < l; c++){
      temp = (*this)[r1*l+c];
      (*this)[r1*l+c] = (*this)[r2*l+c];
      (*this)[r2*l+c] = temp;
    }
  }
}

template <class T>
void matrix<T>::divRow(int r, T coeff){
  for(int c = 0; c < l; c++)
    if((*this)[r*l+c] != 0)
      (*this)[r*l+c] = (*this)[r*l+c]/coeff;
  /*if (r == 1)
    std::cout << "Riga: " << r << " Coeff: " << coeff << std::endl;*/
}

template <class T>
int matrix<T>::maxCoeff(int now_row, int now_col)const{
  int max = now_row;
  for(int r = now_row + 1; r < h; r++)
    if( (*this)[r*l+now_col] > (*this)[max*l+now_col])
      max = r;
  return max;
}

template <class T>
void matrix<T>::subRow(int r1, int r2, T coeff){
  for(int c = 0; c < l; c++)
    (*this)[r1*l+c] = (*this)[r1*l+c] - (*this)[r2*l+c] * coeff;
}



template <class T>
matrix<T> matrix<T>::Gauss(int col_num)const{
  matrix<T> temp(*this);
  if (col_num == -1)
    col_num = l;
  int c = 0;
  for(int r = 0; r < h && c < col_num; r++){
    if(temp[r*l+c] == 0){
      temp.swap(r,temp.maxCoeff(r,c));
      while (temp[temp.maxCoeff(r,c)*l+c] == 0)
      c++;
    }

    for(int i = r; i < h; i++)
      if(temp[i*l+c] != 0){
        temp.divRow(i,temp[i*l+c]);
      }


    for(int i = r + 1; i < h; i++)
      if(temp[i*l+c] != 0)
        temp.subRow(i,r);

    temp.approxZero();

    c++;
  }

  return temp;
}

template <class T>
void matrix<T>::approxZero(){
  for(int i = 0; i < l*h; i++)
    if(bxm::abs((*this)[i]) < 0.00000001)
      (*this)[i] = 0;
}

template <class T>
matrix<T> matrix<T>::GaussJordan(int col_num)const{
  if (col_num == -1)
    col_num = l;
  matrix<T> temp(this->Gauss(col_num));

  int r = h - 1;
  int rd;
  for(int c = col_num - 1; c >= 0 && r > 0; c--){
    rd = r;
    while( temp[rd*l+c] != 1 && rd > 0 )
      rd--;
    if (rd > 0){
      for(int i = rd - 1; i >= 0; i--){
        temp.subRow(i,rd,temp[i*l+c]);
      }
      r--;
    }
  }

  return temp;
}
template <class T>
matrix<T> matrix<T>::Cut(int row_start, int row_num, int col_start, int col_num)const{
  matrix<T> temp(row_num - row_start ,col_num - col_start);
  int pos = 0;
  for(int r = row_start; r < row_num; r++)
    for(int c = col_start; c < col_num; c++){
      temp[pos] = (*this)[r*l+c];
      pos++;
    }
  return temp;
}

template <class T>
matrix<T> matrix<T>::Append(const matrix<T>& m1)const{
  if(m1.h != h)
    std::cout << "PROBLEMA VEZZZ";
  int pos = 0;
  matrix<T> temp(m1.h,l+m1.l);
  for(int r = 0; r < m1.h; r++){
    for(int c = 0; c < l; c++){
      temp[pos] = (*this)[r*l+c];
      pos++;
    }
    for(int c = 0; c < m1.l; c++){
      temp[pos] = m1[r*m1.l+c];
      pos++;
    }
  }
  return temp;
}

template <class T>
bool matrix<T>::sameDim(const matrix<T>& m)const{
  return (h==m.h && l==m.l);
}

template <class T>
void matrix<T>::Fill(const T& t){
  for(int i = 0; i < l*h; i++)
    (*this)[i] = t;
}

template <class T>
bool matrix<T>::hasDet()const{
  return false;
}

template <class T>
bool matrix<T>::isInvertible()const{
  return false;
}

template <class T>
T matrix<T>::Det()const{
  return 0;
}

template <class T>
square_matrix<T> matrix<T>::Inversa()const{
  return square_matrix(1,1);
}



#endif
