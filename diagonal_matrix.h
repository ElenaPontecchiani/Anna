#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "square_matrix.h" 

template<class T>
class diagonal_matrix public:square_matrix{
private: 
  static bool onDiagonal(int dim,int i)const;//ogg inv matrice diag, dim e indice e dice se è su diag
                                        //serve per sommare/sottrarre solo el sualla diag altri sono 0
public:
//costruttori da ridef-->si in input array di num che andranno sulla diag!!
    diagonal_matrix(const&=0);
    
    
    //giusto?
    diagonal_matrix(const&=0,const T[d]);//dicitura giusta??
    


    diagonal_matrix<T> operator+(const diagonal_matrix<T>&)const;
    
    
    diagonal_matrix<T> operator-(const diagonal_matrix<T>&)const;

    diagonal_matrix<T> operator*(const T&)const;

    T Determinante()const;//messi solo el diagonale principale
  
};


//////////////////////////////
//     S T A T I C H E      //
//////////////////////////////

template <class T>
bool diagonal_matrix<T>::onDiagonal(int dim,int i)const{// su diag princ se è primo el o se multiplo l+1-->resto
  if(i==0) return true;
  if(!(i%(l+1))) return true;
  return false;
}






//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////


template <class T>
diagonal_matrix<T>::diagonal_matrix(const int& dim):
    *this(square_matrix<T>(dim,dim)){} //messe solo dim


//giusto?
template <class T>
diagonal_matrix<T>::diagonal_matrix(const int& dim,const T[]): *this(square_matrix<T>(dim,dim)){
    int j=0;//per segnare el da mettere su diag    
    for(int i=0;i<dim^2;i++){
      if(i==j){
        j+=dim+1;//slittoprox el 
        raw_matrix[i]=T[i];
      }
      else {T[i]=0;}

    }
}


//////////////////////////////
//   OP  O V E R L O A D    //
//////////////////////////////




//fare f che dice se el è sulla diagonale?
#include "basxMath.h"
template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator+(const diagonal_matrix<T>& m)const{
  if(!(*this.dimensions(m))){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  diagonal_matrix<T> temp(h,l);
  for(int i = 0; i < l*h; i++){
    if(onDiagonal(h,i))
    {temp[i] = raw_matrix[i]+m.raw_matrix[i];}
    else{temp[i] =0;}
}
  return temp;
}

template <class T>
matrix<T> matrix<T>::operator-(const matrix<T>& m)const{
  if(!(l == m.l && h == m.h)){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  matrix<T> temp(h,l);
  ffor(int i = 0; i < l*h; i++){
    if(onDiagonal(h,i))
    {temp[i] = raw_matrix[i]-m.raw_matrix[i];}
    else{temp[i] =0;}
}
  return temp;
}



template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator*(const T& t)const{
  if(!(*this.dimensions(m))){
    //Throw///
    std::cout << "Non sommabile vezz" << std::endl;
  }
  diagonal_matrix<T> temp(h,l);
  for(int i = 0; i < l*h; i++){
    if(onDiagonal(h,i))
    {temp[i] =raw_matrix[i]*t;}
    else{temp[i] =0;}
}
  return temp;
}

//ridef costruttore copia!!


//////////////////////////////
//   O P E R A Z I O N I    //
//////////////////////////////

template<class T>
T square_matrix<T>::Determinante()const{
//non fatta secondaria tanto tt 0
int s=0;
for(int i=0;i<l;i++){
    s+=raw_matrix[i+i*l];//seleziona el su diagonale principale
}
return s;
}









#endif