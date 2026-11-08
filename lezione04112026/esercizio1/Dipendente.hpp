#ifndef DIPENDENTE_HPP
#define DIPENDENTE_HPP

#include <string>

class Dipendente {
public:
    Dipendente(const std::string& nome, const std::string& cognome, double stipendioBase);

    const std::string& getNome() const;
    const std::string& getCognome() const;
    double getStipendioBase() const;
    void setNome(const std::string& nome);
    void setCognome(const std::string& cognome);
    void setStipendioBase(double stipendioBase);

    double stipendio() const;
    void stampa() const;

private:
    std::string nome;
    std::string cognome;
    double stipendioBase;
};

#endif
