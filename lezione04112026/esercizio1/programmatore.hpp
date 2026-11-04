#include "dipendenti.hpp"
#ifndef PROGRAMMATORE_H
#define PROGRAMMATORE_H

class Programmatore:public Dipendente{
    private:
        int Nprogetti;
    public:
        Programmatore():Dipendente(),Nprogetti(0){}
        double stipendio() const;
        void stampa() const;
};

#endif