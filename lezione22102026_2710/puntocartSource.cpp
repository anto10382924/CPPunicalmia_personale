#include "puntocartesiano.hpp"
#include <iostream>
#include <cmath>

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
};*/

PuntoCartesiano& PuntoCartesiano::operator=(const PuntoCartesiano &P){   //modifichiamo l'operatore =, per riferimento per ottimizzare i costi
    if(this!=&P){   //si fa per controllare che non sia un autoassegnamento, magari quando this punta già a P (in questo caso)
        this -> x = P.x;
        y = P.y;
    }
    return *this;   //stiamo returnando TUTTO l'oggetto P
};

bool PuntoCartesiano::operator==(const PuntoCartesiano &P) const{
    /*if (this -> x != P.x || this -> y != P.y)
        return false;
    return true;*/
    return (this -> x==P.x && this->y==P.y);
}

bool PuntoCartesiano::operator>(const PuntoCartesiano &P) const{
    PuntoCartesiano O (0,0);    //creiamo un punto origine
    return (this -> distanza(O) > P.distanza(O));   //true se e solo se la distanza tra P e O è minore rispetto a quella tra il primo punto (nel mio main P) e O
}

bool operator>(const PuntoCartesiano &P, const PuntoCartesiano &Q){     //se lo facciamo come funzione standalone dobbiamo usare 2 oggetti come parametri (non potendo usare this)(vedi prima di private in .hpp)
    //...
}

ostream& operator<<(ostream &out,const PuntoCartesiano &P){    //out è il canale che viene riempito con gli oggetti che vengono mandati in stampa
    out << "(" << P.x << "," << P.y << ")" << endl;
    return out;
}

istream& operator>>(istream &in,PuntoCartesiano &P){   //in è il canale su cui vengono presi i dati (credo)
    in >> P.x >> P.y;
    return in;
}

PuntoCartesiano operator+(const PuntoCartesiano &P1,const PuntoCartesiano & P2){    //non per riferimento perchè returniamo un punto creato nuovo.
    PuntoCartesiano P(P1.x+P2.x,P1.y+P2.y);
    return P;
}

int main(){
    PuntoCartesiano P;  //prende i valori del costruttore di default
    PuntoCartesiano Q(3,4); //prende i valori tramite il secondo costruttore dell'hpp
    PuntoCartesiano R{Q};   //usiamo il costruttore per copia (creiamo un punto R coi valori del punto Q creato prima
    P.stampaPunto();    //sintassi per l'uso dei metodi della classe!
    P=Q;  //assegnamento di defaut fra 2 oggetti, funziona attributo per attributo!!! (originale: P.operator=(Q);, noi l'abbiamo modificato per rendere plausibile P=Q=Z...)
    P=Q=R;  //da dx verso sx anche qua
    if (P==Q)   //compila solo implementando il metodo operator==
        cout << "sono uguali? \n";
    if (P>Q)    //compila solo implementando il metodo operator>
        cout << "è maggiore? \n"; 
    return 0;
}

/*
    int x=3, y,z;
    z=y=x;
    tutti e tre gli interi diventano 3,= va da dx verso sx SEMPRE
    con gli oggetti NON si può fare così di default, tocca implementare il metodo operator=

    OVERLOADING vuol dire creare funzioni con lo stesso nome ma parametri diversi, utile sopratutto con gli operators.
*/