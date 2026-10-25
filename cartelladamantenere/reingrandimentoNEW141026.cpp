#include <iostream>
using namespace std;

void leggi(int* &p,int &dim){        //dim per riferimento siccome lo passiamo da funzione a funzione
    int num;        //IMPORTANTE: l'array dinam. va passato per riferimento sennò si perde durante l'esecuzione tra le funzioni e si ha memory leak
    cout << "Inserisci interi, 0 per terminare \n";
    cin >> num;
    unsigned count = 0;
    while(num != 0){
        if (count == dim)
            raddoppia(p,dim);
        p[count++] = num;       //scrivendolo così (senza l'if sopra) sfora della dimensione!!!
        cin >> num;
    }
}

void raddoppia(int* &p,int &dim){
    int* q = new int[dim*2];        //siccome raddoppia
    for(unsigned i=0; i<dim; ++i)
        q[i]=p[i];
    delete [] p;    //elimina l'array che stava nell'heap puntato da p
    p = q;
    dim *= 2;
}

void stampa(int* p,int dim){        //qui dim per valore tanto non verrà modificato nella funzione ed è un tipo "piccolo"
    for (unsigned i=0; i<dim; ++i)
        cout << p[i] << " ";
    cout << endl;
}

int main(){
    int n = 10;
    int* A= new int [n];
    leggi(A,n);
    stampa(A,n);
    delete [] A;
    return 0;
}

/* 
Non è finito l'esercizio, manca la definizione di capacity 
per togliere le celle non usate dopo il raddoppio! 
*/