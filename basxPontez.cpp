#include "basx.h"
#include <iostream>

using std::cout;
using std::endl;

template<class T>
int basex<T>::charToInt(const char& c){
    if(c>=48 && c<=57)  return c-48;    //cifre 0-9
    if(c>=65 && c<=90)  return c-55;    //lettere maiuscole
    if(c>=97 && c<=122) return c-87;    //lettere minuscole
    cout<<"input non valido"<<endl;
    return -1;
}

template<class T>
char basex<T>::intToChar(const int& i){//da int a char, da chiamare solo se i>=10
    if(i>=10 && i<=26)
        return i + 55;
    cout<<"input non valido"<<endl;
    return -1;
}

template<class T>
void basex<T>::changeBase(int b){
    base = b;
}

template<class T>
//base ritorno è quella di *this
basex<T> basex<T>::operator+(const basex<T>& n)const{
    return basex(raw_number + n.raw_number,base);
}

template<class T>
//base ritorno è quella di *this
basex<T> basex<T>::operator*(const basex<T>& n)const{
    return basex<T>((raw_number + n.raw_number), base);
}

template<class T>
basex<T> basex<T>::operator/(const basex<T>& n)const{
//base ritorno è quella di *this
//i due numeri sono entrambi in base 10
T tot=raw_number/n.raw_number;
basex<T> out;out.raw_number=tot;
out.base=*(this).base;
return out;
//totale in base 10
//return basex<T>((raw_number+n.raw_number),*(this).base)
}

template<class T>
basex<T> basex<T>::operator-(const basex<T>& n)const{
//base ritorno è quella di *this
//i due numeri sono entrambi in base 10
T tot=raw_number-n.raw_number;
basex<T> out;out.raw_number=tot;
out.base=*(this).base;
return out;
//totale in base 10
//return basex<T>((raw_number+n.raw_number),*(this).base)
}



