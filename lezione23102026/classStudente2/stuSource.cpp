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