#include <string>
#include <math.h>
#include <iostream>
#include "basx.h"

template<class T>
class matrice{
    private:
    int h;
    int l;
    basex**Elementi;//array che tiene conto el
    public:
    matrice(const int &=1,const int &=1,const basex**=0);//inizializzato con l=1,h=1
    matrice(const matrice&);//costruttore
    matrice operator*(const T &=0)const;//prodotto con scalare METTERE TEMPLATE??
    matrice operator+(const matrice)const;//somma tra due matrici
    //prodotto tra vettore riga e vettore colonna in vettori
    //trasposta i-riga diventa i col
    matrice Trasposta()const;
    //coniugata: cambio segno pt img
    matrice Coniugata()const;
    //H-trasp:coniugata+trasposta
    matrice H_trasposta()const;

};