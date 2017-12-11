#include "basx.h"

#include <string.h>
#include <math.h>
#include "basxMath.h"
using std::string;

int approx10 = 6;

template<class T>
T basex<T>::stringToNum(const string& s,const int& base){
    if (s[0] == '-')
        //Se il numero è negativo, eseguo la stessa funzione senza il meno
        return -stringToNum( s.substr(1,string::npos), base);
    
    double somma = 0;
    int i = 0;
    int deltaComma = 0;

    //Controllo se c'è una virgola, se c'è calcolo deltaComma
    std::size_t found = s.find(",");
    if (found == std::string::npos){
        found = s.find(".");
        if (found != string::npos)
            deltaComma = found;
    }
    else
        deltaComma = found - 1;

    //Sommo la parte intera del numero
    while( i < s.length() && s[i] != ',' && s[i] != '.' ){
        somma += charToInt(s[i]) * pow(base,s.length() - i-1 - deltaComma);
        i++;
    }

    //Se il numero aveva solo una parte intera finisco qua
    if (i == s.length())
        return somma;
    
    //Salto la virgola
    int comma_pos = i++;
    
    //Sommo la parte decimale
    while( i < s.length() ){
        somma += charToInt(s[i]) * pow(base,-(i-comma_pos));
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
        conv.append("-");


    int i_part = abs(bx.raw_number);                //Parte intera del numero
    double f_part = abs(bx.raw_number) - i_part;    //Parte decimale del numero

    //Creo la stringa str e converto la parte intera del numero
    string i_str;
    while(i_part != 0){
        i_str += intToChar(i_part % bx.base);
        i_part = i_part / 2;
    }
    std::reverse(i_str.begin(),i_str.end()); //Devo invertire la stringa!!

    if (f_part > 0)
        i_str += ',';

    //Conversione stringa parte decimale
    int den = pow(bx.base,prec);
    f_part = (f_part * pow(10,approx10) ) //Punto 2 algoritmo
            / (pow(10,approx10)/den);  //!!!!!! FUNZIA????????

    //punto 4 algoritmo
    int div,digit;
    for(int i = 1; i <= prec; i++){
        div = (den/ pow(bx.base,i));
        digit = f_part / div;
        i_str += intToChar(digit);
        f_part -= digit * div;
    }

    return i_str;

   


    


    
    
}
