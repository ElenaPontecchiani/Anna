#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "square_matrix.h" //de ve includere base o il contrario?

template<class T>
class diagonal_matrix public:square_matrix{
private: 
public:
//costruttori da ridef-->si in input array di num che andranno sulla diag!!
    diagonal_matrix(const&=0);
    diagonal_matrix(const&d=0,const T[d]);//dicitura giusta??
    bool dimensions(const diagonal_matrix<T>&)const;
//costruttori da ridef-->si in input array di num che andranno sulla diag!!

    diagonal_matrix<T> operator+(const diagonal_matrix<T>&)const;
    
    
    diagonal_matrix<T> operator-(const diagonal_matrix<T>&)const;

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
diagonal_matrix<T>::diagonal_matrix(const int& dim,const T[dim])://dim è l/h
    h(dim),l(dim),raw_matrix(new T[dim^2])
    {int j=0;//indice el sulla diag
    int k=0;//indice scorrimento array che contiene el diag
    for(int i=0;i<h*dim;i++){
     if(i==j)
     {j+=l+1;//incremento j al prossimo el della diag
      k++;
      raw_matrix[i]=T[k]; 
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

    







#endif