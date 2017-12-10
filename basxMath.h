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

    //Mi ritorna il numero di cifre dopo la virgola
    /*int digitsAfterComma(const double& d);*/


};




#endif