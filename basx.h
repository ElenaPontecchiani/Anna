#ifndef BASEX_H
#define BASEX_H

#include <string>
using std::string;

template<class T>
class basex{
private:
    T raw_number;//solo tipi num e inbase 10
    int base;
    
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

    //Overload di operatori, base ritorno operando più a sx, this
    basex operator+(const basex&)const;
    basex operator*(const basex&)const;
    basex operator/(const basex&)const;
    basex operator-(const basex&)const;
    basex& operator=(const basex&);//copia valore ma non base


    //Conversioni
    operator string()const; //Converto *this a stringa
    /*  Sarà necessario dichiarare dei metodi di conversione per i tipi che T può assumere
        = pigna in culo*/
    void changeBase(int base);

//overload output

};

#endif
