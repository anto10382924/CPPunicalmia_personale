#include "Dirigente.hpp"

#include <iostream>

using namespace std;

Dirigente::Dirigente(const string& nome, const string& cognome,
                     double stipendioBase, int collaboratori)
    : Dipendente(nome, cognome, stipendioBase), collaboratori(collaboratori) {}

int Dirigente::getCollaboratori() const { return collaboratori; }
void Dirigente::setCollaboratori(int collaboratori) { this->collaboratori = collaboratori; }

double Dirigente::stipendio() const {
    return Dipendente::stipendio() + 50 * collaboratori;
}

void Dirigente::stampa() const {
    cout << "[Dirigente] ";
    Dipendente::stampa();
    cout << " - stipendio: " << stipendio() << " - collaboratori: " << collaboratori;
}
