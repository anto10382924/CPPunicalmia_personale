#include <iostream>
#include "stu.hpp"

Stu::Stu(const Stu &other):matricola(other.matricola),eta(other.eta),esami_sost(other.esami_sost){
    for (unsigned i=0; i < NUM_ESAMI; ++i){
        nomi_esami[i] = other.nomi_esami[i];
        voti_esami[i] = other.voti_esami[i];
        cfu_esami[i] = other.cfu_esami[i];
    }
}

void Stu::setNomi_esami(string nuoviNomi[]){
    for (unsigned i=0; i<NUM_ESAMI; ++i)
        nomi_esami[i] = nuoviNomi[i];
}

void Stu::setVoti_esami(unsigned nuoviVoti[]){
    for (unsigned i=0; i<NUM_ESAMI; ++i)
        voti_esami[i] = nuoviVoti[i];
}

void Stu::setCfu_esami(unsigned nuoviCFU[]){
    for (unsigned i=0; i<NUM_ESAMI; ++i)
        cfu_esami[i] = nuoviCFU[i];
}

Stu & Stu::operator=(const Stu &other){
    if (this != &other){
        matricola = other.matricola;
        eta = other.eta;
        esami_sost = other.esami_sost;
        for (unsigned i=0; i< other.esami_sost; ++i){
            nomi_esami[i] = other.nomi_esami[i];
            voti_esami[i] = other.voti_esami[i];
            cfu_esami[i] = other.cfu_esami[i];
        }
    }
    return *this;
}

void Stu::aggiungiEsame(const string& esame, unsigned voto, unsigned cfu){
    if (esami_sost < NUM_ESAMI){
        nomi_esami[esami_sost] = esame;
        voti_esami[esami_sost] = voto;
        cfu_esami[esami_sost] = cfu;
        ++esami_sost;
    }
    else
        cout << "Numero esami sostenuti già al massimo!!! \n";
}

void Stu::rimuoviUltimoesame(){
    if (esami_sost == 0)
        cout << "Non ci sono esami \n";
    else{
        --esami_sost;
        nomi_esami[esami_sost] = " ";
        voti_esami[esami_sost] = 0;
        cfu_esami[esami_sost] = 0; 
    }
}

float Stu::getMediaVoti() const{
    int somma = 0;
    for (unsigned i=0; i < esami_sost; ++i)
        somma += voti_esami[i];
    return (float)somma/esami_sost;
}

float Stu::getMediaPonderata() const{
    if (esami_sost == 0)    
        return 0;
    int prodottoV_C = 0;
    int sommaCFU = 0;
    for (unsigned i=0; i < esami_sost; ++i){
        prodottoV_C += (voti_esami[i]*cfu_esami[i]);
        sommaCFU += cfu_esami[i];
    }
    return (float)prodottoV_C/sommaCFU;
}

bool bestStudents(const Stu studenti[], unsigned numeroStudenti){
    for(unsigned i=0; i<numeroStudenti; ++i){
        if (studenti[i].getMediaPonderata() < 28)
            return false;
    }
    return true;
}

unsigned numeroEsamiAllaLaurea(const Stu studenti[], unsigned numeroStudenti){
    if (numeroStudenti == 0)
        return NUM_ESAMI;
    unsigned max_esami = studenti[0].getEsami_sost();
    for(unsigned i=1; i<numeroStudenti; ++i){
        if (max_esami < studenti[i].getEsami_sost())
            max_esami = studenti[i].getEsami_sost();
    }
    return NUM_ESAMI - max_esami;
}

bool stessiVoti(const Stu& s1, const Stu& s2){      //da finì
    if (s1.getEsami_sost() != s2.getEsami_sost())
        return false;

    return true;
}

string getMatricolaStudenteGiovaneEBravo(const Stu studenti[], unsigned numeroStudenti){    //si può fare con variabile "indicemigliore"
    Stu migliore;
    int start = -1;
    for (unsigned i=0; i<numeroStudenti; ++i){
        if (studenti[i].getEta() <= 20 && studenti[i].getEsami_sost() >= 3){
            migliore = studenti[i];
            start = i;
            break;
        }    
    }
    if (start == -1)
        return "---";
    for (unsigned i=start; i<numeroStudenti; ++i){
        if (studenti[i].getEta() <= 20 && studenti[i].getEsami_sost() >= 3){
            if (migliore.getMediaVoti() < studenti[i].getMediaVoti())
                migliore = studenti[i];
            if (migliore.getMediaVoti() == studenti[i].getMediaVoti() && migliore.getEta() > studenti[i].getEta())
                migliore = studenti[i];
        }
    }
    return migliore.getMatricola();
}

int main(){
    int k;
    cout << "Inserire il numero di studenti che si vogliono \n";
    cin >> k;
    Stu studenti[k];
    cout << bestStudents(studenti,k);
    cout << numeroEsamiAllaLaurea(studenti,k);
    cout << stessiVoti(studenti[0],studenti[1]);
    return 0;
}