#ifndef AZIENDA_HPP
#define AZIENDA_HPP

#include <string>
#include <vector>

#include "Dirigente.hpp"
#include "Programmatore.hpp"

class Azienda {
public:
    void assumi(const Programmatore& p);
    void assumi(const Dirigente& d);
    void licenzia(const std::string& cognome);
    void stampaDipendenti() const;
    double costoTotale() const;
    void ordinaDipendenti(int valore);

private:
    std::vector<Programmatore> programmatori;
    std::vector<Dirigente> dirigenti;
};

#endif
