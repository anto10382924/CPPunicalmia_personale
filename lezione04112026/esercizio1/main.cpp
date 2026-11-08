#include <iostream>

#include "Azienda.hpp"

using namespace std;

int main() {
    Azienda azienda;

    azienda.assumi(Programmatore("Luca", "Bianchi", 1800, 3));
    azienda.assumi(Programmatore("Anna", "Verdi", 1900, 5));
    azienda.assumi(Programmatore("Marco", "Rossi", 1700, 1));
    azienda.assumi(Programmatore("Elena", "Neri", 2000, 4));
    azienda.assumi(Dirigente("Paolo", "Gallo", 3000, 10));
    azienda.assumi(Dirigente("Sara", "Conti", 3200, 6));
    azienda.assumi(Dirigente("Carlo", "Esposito", 2800, 12));
    azienda.assumi(Dirigente("Giulia", "Fabbri", 3500, 8));

    cout << "--- Dipendenti ---" << endl;
    azienda.stampaDipendenti();
    cout << "Costo totale: " << azienda.costoTotale() << endl;

    cout << endl << "--- Ordinati per cognome ---" << endl;
    azienda.ordinaDipendenti(1);
    azienda.stampaDipendenti();

    cout << endl << "--- Ordinati per stipendio ---" << endl;
    azienda.ordinaDipendenti(2);
    azienda.stampaDipendenti();

    cout << endl << "--- Dopo il licenziamento di Esposito ---" << endl;
    azienda.licenzia("Esposito");
    azienda.stampaDipendenti();
    cout << "Costo totale: " << azienda.costoTotale() << endl;

    return 0;
}
