#include "puntocartesiano.hpp"
#include <iostream>
#include <cmath>
using namespace std;

PuntoCartesiano::PuntoCartesiano():x(0),y(0){   //: ecc... è la lista di inizializzazione, usabile solo nei costruttori
    cout << "costruttore di base";
};

PuntoCartesiano::PuntoCartesiano(int x1, int y1):x(x1),y(y1){
    cout << "costruttore per passaggio di valori ";
};

PuntoCartesiano::PuntoCartesiano(const PuntoCartesiano &P):x(P.x),y(P.y){
    cout << "costruttore per copia ";
}

int PuntoCartesiano::getX() const{
    return x;
};

int PuntoCartesiano::getY() const{
    return y;
};

void PuntoCartesiano::setX(int x1){
    this -> x = x1;
};

void PuntoCartesiano::setY(int y1){
    this -> y = y1;
};

void PuntoCartesiano::stampaInvertiti(const PuntoCartesiano &P){
    cout <<"("<<P.getX()<<","<<P.getY()<<")"<<endl;
};

void PuntoCartesiano::stampaPunto() const{
    cout << "(" << x << "," << y << ")" << endl;
};

double PuntoCartesiano::distanza(const PuntoCartesiano &P) const{
    return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y));
};

/*void PuntoCartesiano::operator=(const PuntoCartesiano &Q){
    x=Q.x;  questo è quello di default
    y=Q.y;
    cout << "operatore di =  ";
};*/

PuntoCartesiano& PuntoCartesiano::operator=(const PuntoCartesiano &P){   //modifichiamo l'operatore =, per riferimento per ottimizzare i costi
    if(this!=&P){   //si fa per controllare che non sia un autoassegnamento, magari quando this punta già a P (in questo caso)
        this -> x = P.x;
        y = P.y;
    }
    return *this;   //stiamo returnando TUTTO l'oggetto P
};

int main(){
    PuntoCartesiano P;  //prende i valori del costruttore di default
    PuntoCartesiano Q(3,4); //prende i valori tramite il secondo costruttore dell'hpp
    PuntoCartesiano R{Q};   //usiamo il costruttore per copia (creiamo un punto R coi valori del punto Q creato prima
    P.stampaPunto();    //sintassi per l'uso dei metodi della classe!
    P=Q;  //assegnamento di defaut fra 2 oggetti, funziona attributo per attributo!!! (originale: P.operator=(Q);, noi l'abbiamo modificato per rendere plausibile P=Q=Z...)
    P=Q=R;  //da dx verso sx anche qua
    return 0;
}

/*
    int x=3, y,z;
    z=y=x;
    tutti e tre gli interi diventano 3,= va da dx verso sx SEMPRE
    con gli oggetti NON si può fare così di default, tocca usare il this
*/