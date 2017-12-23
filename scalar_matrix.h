#ifndef SCALARMATRIX_H
#define SCALARMATRIX_H

#include "diagonal_matrix.h" //de ve includere base o il contrario?

template<class T>
class scalar_matrix public:diagonal_matrix{
private: 

public:

//ridef determinante!!!!!!!!!!!!

//costruttori da ridef-->si in input array di num che andranno sulla diag!!
    scalar_matrix(const T&=0,const T&=0);//in input el diag ()che è sempre uguale e dim==n el diag
    
    T Determinante ()const;
//costruttori da ridef-->si in input array di num che andranno sulla diag!!

    
//matrix<T> Diagonale()const;//ritorna matrice diagonale con =dim matrice invocazione
//-->uguale

//matrix<T> Composizione()const;//ritorna una matrice che affianca a quella quadrata la sua diagonale
//-->uguale

//matrix<T>Inversa()const;
//-->uguale

//bool Symmetric()const;//non esistono parametri solo ogg inv. se è trasposta a se stessa
//-->uguale

//T Determinante ()const;//non esistono parametri solo ogg inv.
//-->uguale

};

template <class T>
scalar_matrix<T>::diagonal_matrix(const int& dim,const int el)://dim è l/h
h(dim),l(dim),raw_matrix(new T[dim^2])
  {int j=0;//indice el sulla diag
    for(int i=0;i<h*dim;i++){
     if(i==j)
     {j+=l+1;//incremento j al prossimo el della diag
      raw_matrix[i]=el; 
    }
    else{raw_matrix[i]=0;}
    }
    }


template <class T>
diagonal_matrix<T>::diagonal_matrix(const int& dim)://dim è l/h
    h(dim),l(dim){}

template <class T>
bool diagonal_matrix<T>::dimensions(const matrix<T>& m)const{
  return (m.dim==dim);
}




//ridef costruttore copia!!


template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator+(const diagonal_matrix<T>& m)const{
  if(!(*this.dimensions(m)){
    //eccezione da lanciare///
    std::cout << "errore dim" << std::endl;
  }

  diagonal_matrix<T> temp=m;//vedere se ridef costruttore a una sola dim
  for(int i=0; i < dim; i++)
    temp.raw_matrix[i+i*dim] +=raw_matrix[i+i*dim];//+m.raw_matrix[i+i*dim]
  return temp;//sommo solo el sulla diagonale perchè altri sono tutti 0
}

template <class T>
diagonal_matrix<T> diagonal_matrix<T>::operator-(const diagonal_matrix<T>& m)const{
  if(!(*this.dimensions(m)){
    //eccezione da lanciare///
    std::cout << "errore dim" << std::endl;
  }

  diagonal_matrix<T> temp=m;//vedere se ridef costruttore a una sola dim
  for(int i=0; i < dim; i++)
    temp.raw_matrix[i+i*dim] -=raw_matrix[i+i*dim];//+m.raw_matrix[i+i*dim]
  return temp;//sottraggo solo el sulla diagonale perchè altri sono tutti 0
}

    
template<class T>
T square_matrix<T>::Determinante()const{
return raw_matrix[0]*h;
}






#endif