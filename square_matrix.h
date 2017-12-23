#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h" //de ve includere base o il contrario?

template<class T>
class square_matrix public:matrix{
private: 
public:

//costruttori da ridefinire???


//ottiene tutti quelli genitore+ propri
/*metodi propri:
 -inverso-->ok
-calcolo determinante-->messo
-elevazione a potenza(? da fare se già messa in passaggio f?)
-matrice simmetrica--> trasposta di sè stessa messa

costruttori rimangono uguali? non servono controlli
+-/* sono uguali o vanno ridef
aggiungere metodo eventualmente staico per affiancare alla matrice la sua diagonale
per calcolo inversa
*/

matrix<T> Diagonale()const;//ritorna matrice diagonale con =dim matrice invocazione

matrix<T> Composizione()const;//ritorna una matrice che affianca a quella quadrata la sua diagonale

matrix<T>Inversa()const;

bool Symmetric()const;//non esistono parametri solo ogg inv. se è trasposta a se stessa

T Determinante ()const;//non esistono parametri solo ogg inv.
};





template<class T>
T square_matrix<T>::Determinante()const{
//l==h el su diag primnc i==j su secondaria dim-j?
int s1=0;
for(int i=0;i<l;i++){
    s1+=raw_number[i+i*l];//seleziona el su diagonale principale
}
//int s2=0;//per el su secondaria
for(int i=0;i<l;i++){
    s1-=raw_number[(i+1)*(l-1)];//seleziona el su diagonale secondaria
}
return s1;
}

template<class T>
bool square_matrix<T>::Symmetric()const{
matrix<T> m=(*this).Trasposta;
return m==*this;//restituisce se matrice e uguale a se stessa
}

template<class T>
matrix<T> square_matrix<T>::Diagonale()const{//ritorna matrice diagonale 
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
matrix<T> square_matrix<T>::Accosta()const{
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

template<class T>
matrix<T> square_matrix<T>::Inversa()const{
return (*this.Accosta()).Gauss;
}































#endif