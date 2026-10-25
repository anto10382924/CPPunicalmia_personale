#include "rettangolo.hpp"   //quando includiamo files tra "" e non <>
#include <cassert>      //se si vuole usare l'operatore assert
using namespace std;

rettangolo::rettangolo(){   //implementazione costruttore
    lunghezza = 2.0;
    altezza = 2.0;
}

float rettangolo::getPerimetro const(){     //le funzioni della classe le sviluppiamo nel file source
    return 2*(lunghezza+altezza);       //stiamo modificando la classe stessa quindi non abbiamo problemi ad accedere al private, indipendentemente dal file   
}

float rettangolo::getArea const(){
    return lunghezza*altezza;
}

float rettangolo::getLunghezza() const{
    return lunghezza;
}

float rettangolo::getAltezza() const{
    return altezza;
}

void rettangolo::setLunghezza(float lunghezza){
    if (lunghezza > 1.0 && lunghezza < 10.0)
        this->lunghezza = lunghezza;    //this è un puntatore che punta al membro della classe (-> è un operatore del puntatore), il secondo "lunghezza" è il parametro della funzione
}

void rettangolo::setAltezza(float altezza){
    if (altezza > 1.0 && altezza < 10.0)    //se scriviamo assert invece che if, se la condizione è falsa allora dà errore in compilazione
        this->altezza = altezza;
}

int main(){
    rettangolo r;   //è uguale a rettangolo r = rettangolo();
    cout << r.getLunghezza();   //richiamo della funzione getlunghezza dalla classe rettangolo
    return 0;
}