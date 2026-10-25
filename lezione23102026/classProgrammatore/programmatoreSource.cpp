#include "programmatore.hpp"
#include <iostream>

const int numero_prog = 5;

programmatore::programmatore():nome(""),eta(0),stipendio(0),anni_esperienza(0),senior(false){};

programmatore::programmatore(const string& s, unsigned e, unsigned stip, unsigned a_e, bool sen):
    nome(s), eta(e), stipendio(stip), anni_esperienza(a_e), senior(sen){}

programmatore::programmatore(const programmatore &altro){
    nome = altro.nome;
    eta = altro.eta;
    stipendio = altro.eta;
    anni_esperienza = altro.anni_esperienza;
    senior = altro.senior;
}

string programmatore::getNome() const{ return nome;}
unsigned programmatore::getEta() const {return eta;}
unsigned programmatore::getStipendio() const {return stipendio;}
unsigned programmatore::getAnniesperienza() const{return anni_esperienza;}
bool programmatore::getSenior() const{ return senior;}

void programmatore::setNome(const string & n){nome = n;}
void programmatore::setEta(unsigned e){eta = e;}
void programmatore::setStipendio(unsigned stip){stipendio = stip;}
void programmatore::setAnniesperienza(unsigned a_e){anni_esperienza = a_e;}
void programmatore::setSenior(bool sen){senior = sen;}

programmatore& programmatore::operator=(const programmatore &altro){
    if (this != &altro){
        nome = altro.nome;
        eta = altro.eta;
        stipendio = altro.stipendio;
        anni_esperienza = altro.anni_esperienza;
        senior = altro.senior;
    }
    return *this;
}

unsigned getNumeroProgrammatoriPerNome(const programmatore programmatori[], string nome){
    unsigned count = 0;
    for (int i=0;i<numero_prog;++i){
        if (programmatori[i].getNome() == nome)
            count ++;
    }
    return count;
}

const programmatore& getJuniorPiuEsperto(const programmatore programmatori[]){
    unsigned max_anni = 0;
    int indexpiuesperto = -1;
    for (int i=0; i<numero_prog; ++i){
        if (!programmatori[i].getSenior() && programmatori[i].getAnniesperienza() > max_anni){
            //max_anni = programmatori[i].
        }
    }
}

int main(){

    return 0;
}