#include "basx.h"

#include <string.h>
#include <math.h>
using std::string;

template<class T>
T stringToNum(const string& s,const int& base){
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
    if (i == s.length()
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