#include "basx.h"


int charToInt(const char& c){
if(c>=48 && c<=57) //sono corrispondenti num 0-9 (static cast?)
{int a=c-48; return a;}
if(c>=65 && c<=90)//lettere maiuscole
{int a=c-55;return a;}
if(c>=97 && c<=122)//lettere minuscole
{int a=c-87;return a;}
cout<<"input non valido"<<endl;
return -1;
}

char intToChar(const int& i){//da int a char, da chiamare solo se i>=10
if(i>=10 && i<=26){
    char x=i+55;
    return x;
}
cout<<"input non valido"<<endl;
return -1;    
}

template<class T>
void changeBase(int b){
    base=b;
}

template<class T>
//overloading operatori
basex operator+(const basex& n)const{
//base ritorno è quella di *this
//i due numeri sono entrambi in base 10
T tot=raw_number+n.raw_number;
basex out;out.raw_number=tot;
out.base=*(this).base;
return out;
//totale in base 10
//return basex((raw_number+n.raw_number),*(this).base)
}

template<class T>
basex operator*(const basex& n)const{
//base ritorno è quella di *this
//i due numeri sono entrambi in base 10
T tot=raw_number*n.raw_number;
basex out;out.raw_number=tot;
out.base=*(this).base;
return out;
//totale in base 10
//return basex((raw_number+n.raw_number),*(this).base)
}

template<class T>
basex operator/(const basex& n)const{
//base ritorno è quella di *this
//i due numeri sono entrambi in base 10
T tot=raw_number/n.raw_number;
basex out;out.raw_number=tot;
out.base=*(this).base;
return out;
//totale in base 10
//return basex((raw_number+n.raw_number),*(this).base)
}

template<class T>
basex operator/(const basex& n)const{
//base ritorno è quella di *this
//i due numeri sono entrambi in base 10
T tot=raw_number-n.raw_number;
basex out;out.raw_number=tot;
out.base=*(this).base;
return out;
//totale in base 10
//return basex((raw_number+n.raw_number),*(this).base)
}



