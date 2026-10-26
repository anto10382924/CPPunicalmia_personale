#ifndef PROGRAMMATORE_H
#define PROGRAMMATORE_H
using namespace std;
#include <string>

class programmatore{
    private:
        string nome;
        unsigned eta;
        unsigned stipendio;
        unsigned anni_esperienza;
        bool senior;
    public:
        programmatore();
        programmatore(const string& , unsigned , unsigned, unsigned, bool);
        programmatore(const programmatore &);

        //getter
        string getNome() const;
        unsigned getEta() const;
        unsigned getStipendio() const;
        unsigned getAnniesperienza() const;
        bool getSenior() const;

        //setter
        void setNome(const string &);
        void setEta(unsigned);
        void setStipendio(unsigned);
        void setAnniesperienza(unsigned);
        void setSenior(bool);

        programmatore& operator=(const programmatore &);
        unsigned getNumeroProgrammatoriPerNome(const programmatore [], string);
        const programmatore& getJuniorPiuEsperto(const programmatore []);
        float getStipendioMedioSenior(const programmatore []);
        unsigned maxDifferenzaEta(const programmatore []);
        bool anzianita(const programmatore []);
};

#endif