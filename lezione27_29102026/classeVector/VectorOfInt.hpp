//com'è la libreria vector? questa ne è una versione semplificata
//in generale serve a creare vettori ancora più dinamici rispetto ai vettori new [].
//regola dei 3: costruttore,distruttore e operator= SEMPRE.
//regola dei 5: si aggiungono altri 2 metodi che sono di ottimizzazione,vedremo...
#ifndef VECTOROFINT_H
#define VECTOROFINT_H

#include <iostream>
using namespace std;

class VectorOfInt{
    private:
        int size;   //posizioni aggiunte, adrebbe bene anche size_t come datatype (o altri tipi)
        int capacity;   //dimensione iniziale
        int *A;
    public:
        VectorOfInt(int cap=10):size(0),capacity(cap){
            if (capacity == 0)  //non avrebbe senso creare un costruttore di un array da 0 elementi (quindi se l'utente passa cap=0 lo famo di 1)
                capacity ++;
            A = new int[capacity];
        }
        ~VectorOfInt(){     //distruttore (si, con la tilde all'inizio), di solito di dafault, qui necessario per via del new int nei costruttori
            delete [] A;    //se ti scordi sta roba addio RAM glu glu glu
        }
        VectorOfInt(const VectorOfInt& other):size(other.size),capacity(other.capacity){    //VectorOfInt Q(V); del main
            A = new int [capacity];     //capacity l'ho già copiata quindi direttamente capacity la dim
            for(unsigned i=0; i<size;++i)   //i<size perché gli indici delle celle che hanno valori al loro interno giustamente
                A[i] = other.A[i];
        }
        VectorOfInt& operator=(const VectorOfInt &other){   //V=Q; nel main
            if (this != &other){
                size = other.size;
                capacity = other.capacity;
                delete [] A;    //eliminiamo l'array che "*this" aveva precedentemente, per poi crearne uno da 0 copiando vaore per valore
                A = new int [capacity];
                for(unsigned i=0; i<size;++i)
                    A[i] = other.A[i];
            }
            return *this;
        }
        void push_back(int x){
            if (size == capacity){
                //raddoppia();    //facciamo finta esista come metodo della classe, crea lo spazio (la capacity)
            }
            A[size++] = x;
        }
        int& operator[](unsigned i){     //V[2]=0; nel main, per forza per riferimento, serve una variabile.
            return A[i];    //questa la chiama se l'oggetto non è const
        }
        int operator[](unsigned i) const{   //v[i] nella funzione stampa
            return A[i];    //questa la chiama se l'oggetto è const
        }
        int getSize() const{return size;}
};

#endif