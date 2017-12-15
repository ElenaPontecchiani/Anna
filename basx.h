#ifndef BASEX_H
#define BASEX_H

#include <string>
using std::string;


class basex{
friend std::ostream& operator<<(std::ostream&, const basex&);
private:
    long double raw_number;//solo tipi num e inbase 10
    unsigned int base;
    
    static int approx10;

    static int charToInt(const char&);//conversione char->int
    static char intToChar(const int&);//conversione int->char
    static long double stringToNum(const string&,const int&);//string->T
    static std::string basxToString(const basex&, const int &);//basx->string

public:
        
    //Costruttori
    basex(const long double& =0.0,int=10); //non eseguo conversioni
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













#endif
