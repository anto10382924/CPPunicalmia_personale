#include "Azienda.hpp"

#include <algorithm>
#include <iostream>

using namespace std;

static bool cognomeProg(const Programmatore& a, const Programmatore& b) {
    return a.getCognome() < b.getCognome();
}

static bool cognomeDir(const Dirigente& a, const Dirigente& b) {
    return a.getCognome() < b.getCognome();
}

static bool stipendioProg(const Programmatore& a, const Programmatore& b) {
    return a.stipendio() < b.stipendio();
}

static bool stipendioDir(const Dirigente& a, const Dirigente& b) {
    return a.stipendio() < b.stipendio();
}

void Azienda::assumi(const Programmatore& p) {
    programmatori.push_back(p);
}

void Azienda::assumi(const Dirigente& d) {
    dirigenti.push_back(d);
}

void Azienda::licenzia(const string& cognome) {
    for (unsigned i = 0; i < programmatori.size(); i++) {
        if (programmatori[i].getCognome() == cognome) {
            programmatori.erase(programmatori.begin() + i);
            return;
        }
    }
    for (unsigned i = 0; i < dirigenti.size(); i++) {
        if (dirigenti[i].getCognome() == cognome) {
            dirigenti.erase(dirigenti.begin() + i);
            return;
        }
    }
}

void Azienda::stampaDipendenti() const {
    for (unsigned i = 0; i < programmatori.size(); i++) {
        programmatori[i].stampa();
        cout << endl;
    }
    for (unsigned i = 0; i < dirigenti.size(); i++) {
        dirigenti[i].stampa();
        cout << endl;
    }
}

double Azienda::costoTotale() const {
    double totale = 0;
    for (unsigned i = 0; i < programmatori.size(); i++)
        totale += programmatori[i].stipendio();
    for (unsigned i = 0; i < dirigenti.size(); i++)
        totale += dirigenti[i].stipendio();
    return totale;
}

void Azienda::ordinaDipendenti(int valore) {
    if (valore == 1) {
        sort(programmatori.begin(), programmatori.end(), cognomeProg);
        sort(dirigenti.begin(), dirigenti.end(), cognomeDir);
    } else if (valore == 2) {
        sort(programmatori.begin(), programmatori.end(), stipendioProg);
        sort(dirigenti.begin(), dirigenti.end(), stipendioDir);
    }
}
