#include "Dipendente.hpp"

#include <iostream>

using namespace std;

Dipendente::Dipendente(const string& nome, const string& cognome, double stipendioBase)
    : nome(nome), cognome(cognome), stipendioBase(stipendioBase) {}

const string& Dipendente::getNome() const { return nome; }
const string& Dipendente::getCognome() const { return cognome; }
double Dipendente::getStipendioBase() const { return stipendioBase; }

void Dipendente::setNome(const string& nome) { this->nome = nome; }
void Dipendente::setCognome(const string& cognome) { this->cognome = cognome; }
void Dipendente::setStipendioBase(double stipendioBase) { this->stipendioBase = stipendioBase; }

double Dipendente::stipendio() const {
    return stipendioBase;
}

void Dipendente::stampa() const {
    cout << nome << " " << cognome;
}
