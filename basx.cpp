#include <string>
#include <math.h>
#include "basxMath.h"
#include <iostream>
#include "basx.h"

using std::cout;
using std::endl;
using std::string;





//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////


basex::basex(const long double& t, int b): raw_number(t), base(b) {/*se base>1 ok altrementi err*/}


basex::basex(const string& s,const int b):raw_number(stringToNum(s,b)), base(b) {}


basex::basex(const basex& bx,const int b): raw_number(bx.raw_number), base(b){}   //Costruttore da basex + cambio base


//////////////////////////////
//      S T A T I C I       //
//////////////////////////////


int basex::approx10 = 10;
int basex::approxx = 10;


long double basex::stringToNum(const string& s,const int& base){
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

string basex::basxToString(const basex& bx, const int &dec_num){
    string conv;
    //Se il numero è negativo, metto subito il meno davanti
    if(bx.raw_number < 0)
        conv += "-";


    int i_part = bxm::abs(bx.raw_number);                //Parte intera del numero
    double f_part = bxm::abs(bx.raw_number) - i_part;    //Parte decimale del numero

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
    int den = pow(bx.base,approxx);
    f_part = (f_part * pow(10,approx10) )
            / (pow(10,approx10)/den);

    //punto 4 algoritmo
    int div,digit;
    for(int i = 1; i <= approxx and i <= dec_num; i++){
        div = (den/ pow(bx.base,i));
        digit = f_part / div;
        i_str += intToChar(digit);
        f_part -= digit * div;
    }

    conv += i_str;
    return conv;
}



int basex::charToInt(const char& c){
    if(c>=48 && c<=57)  return c-48;    //cifre 0-9
    if(c>=65 && c<=90)  return c-55;    //lettere maiuscole
    if(c>=97 && c<=122) return c-87;    //lettere minuscole
    cout<<"input non valido"<<endl;
    return -1;
}



char basex::intToChar(const int& i){//da int a char, da chiamare solo se i>=10
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


void basex::changeBase(int b){
    base = b;
}


void basex::Print(){
    cout << "Raw: " << raw_number << "  (" << basxToString(*this) << ")" << base << endl;

}


//////////////////////////////
//   OP  O V E R L O A D    //
//////////////////////////////



//base ritorno è quella di *this
basex basex::operator+(const basex& n)const{
    return basex( raw_number + n.raw_number ,base);
}

basex basex::operator+(const long double& ld)const{
    return basex(raw_number + ld ,base);
}

//base ritorno è quella di *this
basex basex::operator*(const basex& n)const{
    return basex( raw_number * n.raw_number , base);
}

basex basex::operator*(const long double& ld)const{
    return basex(raw_number * ld ,base);
}

//base ritorno è quella di *this
basex basex::operator/(const basex& n)const{
    return basex( raw_number / n.raw_number ,base);
}

basex basex::operator/(const long double& ld)const{
    return basex(raw_number / ld ,base);
}


//base ritorno è quella di *this
basex basex::operator-(const basex& n)const{
    return basex( raw_number - n.raw_number , base);
}

basex basex::operator-(const long double& ld)const{
    return basex(raw_number - ld ,base);
}

//base resta quella di this
/*basex& basex::operator=(const basex& bx){
    raw_number = bx.raw_number;
    return *this;
}

basex& basex::operator=(const long double& ld){
    raw_number = ld;
    return *this;
}*/

//#include <stdio.h>
basex::operator string() const{
    return "(" + basxToString(*this) + ")" + std::to_string(base);
}

basex::operator long double()const{
    return raw_number;
}


std::ostream& operator<<(std::ostream& os, const basex& bx){
    os << (string)bx;
    return os;
}

std::istream& operator>>(std::istream& is, basex& bx){
    cout << "Numero: ";
    std::string s;
    is >> s;
    cout << "Base: ";
    unsigned int b;
    is >> b;
    bx = basex(s,b);
    return is;
}
