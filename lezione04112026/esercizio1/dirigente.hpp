#ifndef DIRIGENTE_HPP
#define DIRIGENTE_HPP

#include "Dipendente.hpp"

class Dirigente : public Dipendente {
public:
    Dirigente(const std::string& nome, const std::string& cognome,
              double stipendioBase, int collaboratori);

    int getCollaboratori() const;
    void setCollaboratori(int collaboratori);

    double stipendio() const;
    void stampa() const;

private:
    int collaboratori;
};

#endif
