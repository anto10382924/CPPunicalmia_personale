#include "programmatore.hpp"

double Programmatore::stipendio() const{
    return getStipendiobase() + (Nprogetti*100);
}

void Programmatore::stampa() const{
    Dipendente::stampa();
    cout << "Programmatore \n";
    stipendio();
    cout << "Ha svolto: " << Nprogetti << "progetti \n";
}