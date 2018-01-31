#ifndef BASXMATH_H
#define BASXMATH_H

/*  Questo namespace contiene funzioni di calcolo utili ai metodi
    della classe basex, che non possono essere logicamente inseriti
    all'interno della classe
*/

namespace bxm{
    //Questa funzione restituisce il valore assoluto
    template<class T>
    T abs(const T& t);

    template<class T>
    T min(const T& a,const T& b);

    //Mi ritorna il numero di cifre dopo la virgola
    /*int digitsAfterComma(const double& d);*/


};


template<class T>
T bxm::abs(const T& t){
    if(t < 0)
        return t*-1;
    return t;
}

template<class T>
T bxm::min(const T& a,const T& b){
  if (a < b)
    return a;
  return b;
}




#endif
