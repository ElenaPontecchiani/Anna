#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"



template<class T>
class square_matrix: public matrix<T>{
private: //h,l,rawmatrix,copyarr vectProd



public:
    square_matrix(const int & =1);//ridef costruttore con 1 solo parametro in cui chiamo anche costruttore matrix
    square_matrix(const square_matrix<T>&);//inizializzato con altra square matrix
    
    //~square_matrix();//ridef distruttore non serve?

//Operatori matematici-->no controllo chiamo direttamente quello genitore
//da tenere tutti?Prodotto con scalare ,[],+,-,*,==,=,conv U
    
//trasposta rimane uguale, gauss anche:non ridef


//ridef dimensions-->controllo solo su una
    bool dimensions(const square_matrix<T>&)const; 

    //Operatore di ugualianza ridef perchè ridef dimensions
    bool operator==(const matrix<T>&)const;
//-elevazione a potenza(? da fare se già messa in passaggio f?) 
/*
aggiungere metodo eventualmente staico per affiancare alla matrice la sua diagonale
per calcolo inversa
*/
    matrix<T> Composizione();//ritorna una matrice che affianca a quella quadrata la sua diagonale-->non quadrata!!
    
    square_matrix<T> Diagonale()const;//ritorna matrice diagonale(1 su diag,0) con =dim matrice invocazione

    square_matrix<T>Inversa()const;

    bool Symmetric()const;//se è trasposta a se stessa

    virtual T Determinante ()const;//non esistono parametri solo ogg inv.
};











//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template <class T>
square_matrix<T>::square_matrix(const int& dim):
    *this(matrix<T>(dim,dim)){}


//ok?
template <class T>
square_matrix<T>::square_matrix(const square_matrix<T>& m):
    *this(matrix<T>(m)){}



//////////////////////////////
//   O P E R A Z I O N I    //
//////////////////////////////

template<class T>
T square_matrix<T>::Determinante()const{
//l==h el su diag primnc i==j su secondaria dim-j?
int s=0;
for(int i=0;i<l;i++){
    s+=raw_matrix[i+i*l];//seleziona el su diagonale principale
}
//int s2=0;//per el su secondaria
for(int i=0;i<l;i++){
    s-=raw_matrix[(i+1)*(l-1)];//seleziona el su diagonale secondaria
}
return s;
}

template<class T>
bool square_matrix<T>::Symmetric()const{
matrix<T> m=(*this).Trasposta;
return m==(*this);//restituisce se matrice e uguale a se stessa
}

template<class T>
square_matrix<T> square_matrix<T>::Diagonale()const{//ritorna matrice diagonale 
matrix<T> m(h,l);//lunghezza è doppia perchè dopo c'e da affiancare
int j=0;
m.raw_matrix[j]=1;
j+=l;
for(int i=1;i<l*h;i++){
    if(i==j+1){
    j+=l;// per saltare di dimi in dimi
    m.raw_matrix[i]=1;}
    else {m.raw_matrix[i]=0;} 
}
return m;
}

template<class T>
matrix<T> square_matrix<T>::Inversa()const{
return (*this.Composizine()).GaussJordan;
}


template<class T>
matrix<T> square_matrix<T>::Composizione(){
matrix<T> Diag=*this.Diagonale();
matrix<T> m(h,2*l);//lung doppia, matrice di out
for(int j=0;j<h;j++){
int i=0;
while(i<l){
m.raw_matrix[j*2*l+i]=raw_matrix[j*l+i];}//assegnazione prime celle
}
//ora va assegnata pt finale righr della diag

for(int j=0;j<h;j++){
int i=0;
while(i<l){
m.raw_matrix[j*2*l+i+l-1]=Diag.raw_matrix[j*l+i];}//assegnazione ultime celle
}
return m;
}


template <class T>  
bool square_matrix<T>::dimensions(const square_matrix<T>& m)const{
  return (h==m.h);//basta controllare una dim
}


template <class T>
bool square_matrix<T>::operator==(const square_matrix<T>& m)const{
  if(!(*this.dimensions(m)) )
    return false;
  int i = 0;
  while(i < l*h){
    if((*this)[i] != m[i])
      return false;
    i++;
  }
  return true;
}

#endif