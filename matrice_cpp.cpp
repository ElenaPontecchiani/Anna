#include "matrice.h"
#include <string>
#include <math.h>
#include <iostream>

//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

//vedere sintassi template

template <class T>
matrice<T>::matrice(const int & altezza=1,const int &lunghezza=1,const basex**b=0):
h(altezza),l(lunghezza),Elementi(b){}/////copia profonda???

template <class T>
matrice<T>::matrice(const matrice& m):h(m.h),l(m.l),Elementi(m.Elemeti){}
////copia profonda????

//////////////////////////////
//   OP  O V E R L O A D    //
//////////////////////////////

template <class T>
matrice<T> matrice::operator*(const T& n)const{
matrice out;//matrice mandata in output

}