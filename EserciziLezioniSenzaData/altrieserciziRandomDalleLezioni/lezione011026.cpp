#include <iostream>
using namespace std;

//PUNTATORI IN C++

void punta(int* p){     //siccome è passato per valore e non riferimento (senza &)
    *p=27;              //crea un NUOVO puntatore che punta ad y (concetto di alias)
                //e riesce con l'istruzione a modificare il valore della y del main!!!
}

void scambiaInteri(int* p, int* q){         //questa scambia i contenuti ma NON gli indirizzi
    int temp = *p;      //temp = 10
    *p = *q;        //x prende il valore di y
    *q = temp;      //y prende il vecchio valore di x (temp)
}

void scambiaPuntatori(int* p, int* q){
    //int* temp=&p; NO, così il puntatore temp punta all'indirizzo del putnatore p
    int* temp=p;    //assegna l'indirizzo di x al puntatore temp
    p=q;    //ora p contiene l'indirizzo di y
    q=temp; //q ora contiene l'indirizzo di temp(che era quello di x)
}       //alla fine comunque gli indirizzi vengono scambiati solo
        //alle variabili p e q della funzione, NON a quelli del main :(
        //se i parametri fossero stati (int* &p,int* &q) allora sarebbero effettivamente cambiati!!!

int main(){
    int x=3;        //variabile AUTOMATICA (visibilità di scope)
    int* p=&x;         //inizializzazione di un puntatore ad x
    cout << *p;     //accedi all'oggetto puntato, deferenziare il puntatore
    cout << p;      //stampa l'indirizzo dell'oggetto puntato (x)
    //p = 7;   NOOOOOOOOO
    *p = 7;     //assegna 4 all'oggetto puntato (x)
    int y=0;
    p=&y;       //punta p ad y
    punta(p);    //passo il puntatore p alla funzione punta
    x=10;
    y=20;
    p=&x;
    int* q=&y;
    scambiaInteri(p,q);
    scambiaPuntatori(p,q);      //MAI con & qui!!!

    /*if (x==0){
        int h=3;
        p=&h;
    }cout << h;     NON FUNZIONA - h ha valore solo dentro l'if

    Praticamente MAI puntare alla cella di una variabile locale
    altrimenti potremmo avere errori o comunque stiamo usando una cella
    che non ci serve effettivamente!!
    */





    return 0;
}