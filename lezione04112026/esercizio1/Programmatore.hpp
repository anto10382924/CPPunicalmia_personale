#ifndef PROGRAMMATORE_HPP
#define PROGRAMMATORE_HPP

#include "Dipendente.hpp"

class Programmatore : public Dipendente {
public:
    Programmatore(const std::string& nome, const std::string& cognome,
                  double stipendioBase, int progetti);

    int getProgetti() const;
    void setProgetti(int progetti);

    double stipendio() const;
    void stampa() const;

private:
    int progetti;
};

#endif
