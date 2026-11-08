#include "Programmatore.hpp"

#include <iostream>

using namespace std;

Programmatore::Programmatore(const string& nome, const string& cognome,
                             double stipendioBase, int progetti)
    : Dipendente(nome, cognome, stipendioBase), progetti(progetti) {}

int Programmatore::getProgetti() const { return progetti; }
void Programmatore::setProgetti(int progetti) { this->progetti = progetti; }

double Programmatore::stipendio() const {
    return Dipendente::stipendio() + 100 * progetti;
}

void Programmatore::stampa() const {
    cout << "[Programmatore] ";
    Dipendente::stampa();
    cout << " - stipendio: " << stipendio() << " - progetti: " << progetti;
}
