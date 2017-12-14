#ifndef BASEX_H
#define BASEX_H

#include <string>
#include <math.h>
#include "basxMath.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::string;


template<class T>
class basex{
//friend std::ostream& operator<<(std::ostream&, const basex<T>&);
private:
    T raw_number;//solo tipi num e inbase 10
    unsigned int base;
    
    static int approx10;

    static int charToInt(const char&);//conversione char->int
    static char intToChar(const int&);//conversione int->char
    static T stringToNum(const string&,const int&);//string->T
    static std::string basxToString(const basex&, const int &);//basx->string

public:
        
    //Costruttori
    basex(T=0,int=10);
    basex(const string&,int=10);  //Costruttore attraverso una stringa
                                    //Funge anche da conversione implicita da stringa
    basex(const basex&, int=10);  //Costruttore da basex + cambio base

    //Overload di operatori, base ritorno operando più a sx, this
    basex operator+(const basex&)const;
    basex operator*(const basex&)const;
    basex operator/(const basex&)const;
    basex operator-(const basex&)const;
    basex& operator=(const basex&);//copia valore ma non base

    void Print();
    void changeBase(int base);

    //Conversioni
    operator string()const; //Converto *this a stringa
    
    /*  Sarà necessario dichiarare dei metodi di conversione per i tipi che T può assumere
        = pigna in culo*/
    

//overload output

};


/*template<class T>
std::ostream& operator<<(std::ostream& os, const basex<T>& bx);*/




//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template<class T>
basex<T>::basex(T t, int b): raw_number(t), base(b) {/*se base>1 ok altrementi err*/}

template<class T>
basex<T>::basex(const string& s,int b):raw_number(stringToNum(s,b)), base(b) {
    //se base>1 ok altrementi err
    //controllo num<0
    //chiamata string->T
}
//conversione da string a base x

template<class T>
basex<T>::basex(const basex& bx, int b): raw_number(bx.raw_number), base(b){}   //Costruttore da basex + cambio base


//////////////////////////////
//      S T A T I C I       //
//////////////////////////////

template<class T>
int basex<T>::approx10 = 6;

template<class T>
T basex<T>::stringToNum(const string& s,const int& base){
    if (s[0] == '-')
#include <math.h>
        //Se il numero è negativo, eseguo la stessa funzione senza il meno
        return -stringToNum( s.substr(1,string::npos), base);

    int l = s.length(); //La chiamata a s.lenght e' ripetuta e onerosa
    double somma = 0;
    int int_part = 0;

    while(int_part < l && s[int_part] != '.' && s[int_part] != ',')
        int_part++;


    //Sommo la parte intera del numero
    int i = 0;
    while( i < l && s[i] != ',' && s[i] != '.' ){
        somma += charToInt(s[i]) * pow(base, int_part - i - 1);
        i++;
    }

    //Se il numero aveva solo una parte intera finisco qua
    if (int_part == l)
        return somma;

    i = 1;
    while(i < l - int_part){
        somma += charToInt(s[l-i]) * pow(base,(-1*(l - int_part - i)) );
        i++;
    }

    return somma;
}


#include <algorithm>    // std::reverse
template<class T>
string basex<T>::basxToString(const basex& bx, const int &prec){
    string conv;
    //Se il numero è negativo, metto subito il meno davanti
    if(bx.raw_number < 0)
        conv += "-";


    int i_part = abs(bx.raw_number);                //Parte intera del numero
    double f_part = abs(bx.raw_number) - i_part;    //Parte decimale del numero

    if (i_part == 0)    //Aggiungo uno zero in caso la parte intera sia zero
        conv += "0";    

    //Creo la stringa str e converto la parte intera del numero
    string i_str;
    while(i_part != 0){
        i_str += intToChar(i_part % bx.base);
        i_part = i_part / bx.base;
    }
    std::reverse(i_str.begin(),i_str.end()); //Devo invertire la stringa!!

    if (f_part > 0) //Se ho anche una parte decimale metto una virgola
        i_str += ',';
    else            //Altrimenti ritorno già il mio numero
        return conv + i_str;

    //Conversione stringa parte decimale

    //Punti 2-3 algoritmo
    int den = pow(bx.base,prec);
    f_part = (f_part * pow(10,approx10) ) 
            / (pow(10,approx10)/den); 

    //punto 4 algoritmo
    int div,digit;
    for(int i = 1; i <= prec; i++){
        div = (den/ pow(bx.base,i));
        digit = f_part / div;
        i_str += intToChar(digit);
        f_part -= digit * div;
    }

    conv += i_str;
    return conv;
}


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
    if(i >= 0 && i <10)
        return i + '0';

    if(i>=10 && i<=26)
        return i + 55;
    cout<<"input non valido"<<endl;
    return -1;
}


//////////////////////////////
//    M E T O D I  L O L    //
//////////////////////////////

template<class T>
void basex<T>::changeBase(int b){
    base = b;
}

template<class T>
void basex<T>::Print(){
    cout << "Raw: " << raw_number << "  (" << basxToString(*this,6) << ")" << base << endl;
}

//////////////////////////////
//   OP  O V E R L O A D    //
//////////////////////////////


template<class T>
//base ritorno è quella di *this
basex<T> basex<T>::operator+(const basex<T>& n)const{
    return basex( raw_number + n.raw_number ,base);
}

template<class T>
//base ritorno è quella di *this
basex<T> basex<T>::operator*(const basex<T>& n)const{
    return basex<T>( raw_number * n.raw_number , base);
}

template<class T>
//base ritorno è quella di *this
basex<T> basex<T>::operator/(const basex<T>& n)const{
    return basex<T>( raw_number / n.raw_number ,base);
}

template<class T>
//base ritorno è quella di *this
basex<T> basex<T>::operator-(const basex<T>& n)const{
    return basex<T>( raw_number - n.raw_number , base);
}

template<class T>
basex<T>::operator string() const{
    return basxToString(*this,6);
}

/*template<class T>
std::ostream& operator<<(std::ostream& os, const basex<T>& bx){
    os << "Raw: " << bx.raw_number << " Base: " << bx.base << " ->(" << basex<T>::basxToString(bx,6) << ")" << bx.base;
    return os;
}*/










#endif
