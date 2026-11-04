#ifndef DIPENDENTI_H
#define DIPENDENTI_H

#include <string>
#include <iostream>
using namespace std;

class Dipendente{
    private:
        string nome;
        string cognome;
        double stipendioBase;
    public:
        Dipendente()=default;
        Dipendente(const string& n, const string& c, double s):nome(n),cognome(c),stipendioBase(s){}
        const string& getNome() const{return nome;}
        const string& getCognome() const{return cognome;}
        const double& getStipendiobase() const{return stipendioBase;}
        void setNome(const string& n){nome=n;}
        void setCognome(const string& c){cognome=c;}
        void setStipendiobase(const double& s){stipendioBase=s;}
        void stampa() const;
};

#endif