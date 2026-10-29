#ifndef ORARIO_H
#define ORARIO_H
#include <iostream>
using namespace std;

class Orario{

    friend ostream& operator<<(ostream&, const Orario&);
    friend istream& operator>>(istream&, Orario& );
    friend bool operator>(const Orario&, const Orario&);
    friend bool operator<(const Orario& A, const Orario& B);
    friend bool operator==(const Orario& A, const Orario& B);

    private:
        unsigned ore;
        unsigned minuti;
        unsigned secondi;
    public:
        Orario():ore(00),minuti(00),secondi(00){}
        Orario(unsigned o, unsigned m, unsigned s):ore(o),minuti(m),secondi(s){}
        Orario(const Orario& other){ore=other.ore; minuti=other.minuti; secondi=other.secondi;}
        const unsigned& getOre(){return ore;}
        const unsigned& getMinuti(){return minuti;}
        const unsigned& getSecondi(){return secondi;}
        void setOre(unsigned o){
            if(o>=0 && o<=23)
                ore=o;
        }
        void setMinuti(unsigned m){
        if(m>=0 && m<=59)
            minuti=m;
        }
        void setSecondi(unsigned s){
            if(s >=0 && s<=59)
                secondi=s;
        }
        Orario& operator=(const Orario & other){
            if (this != &other){
                ore = other.ore;
                minuti = other.minuti;
                secondi = other.secondi;
            }
            return *this;
        }
        Orario& operator+=(const Orario& other){
            ore += other.ore;
            minuti += other.minuti;
            secondi += other.secondi;
            if (ore > 23 && minuti > 59 && secondi > 59){
                ore = 23;
                minuti = 59;
                secondi = 59;
            }
            return *this;
        }
        Orario& operator-=(const Orario& other){
            if (other > *this)  //funziona dopo aver implementato operator> tra due orari.
                return *this;
            ore -= other.ore;
            minuti -= other.minuti;
            secondi -= other.secondi;
            return *this;
        }
};
#endif