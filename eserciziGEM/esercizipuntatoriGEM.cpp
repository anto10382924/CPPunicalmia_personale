#include <iostream>
using namespace std;

void scambia(int* p1, int* p2){     //esercizio facile scambio di due interi tramite deferenzazione e non passaggio per NON valore (&)
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void invertiArray(int* inizio, int dimensione) {        //esercizio intermedio
    int* fine = inizio + (dimensione-1);    //funziona perchè in c++ le celle di memoria di un array sono CONTIGUE
    while(inizio<fine){
    scambia(fine,inizio);   
    inizio ++;  //qui il puntatore inizio punterà alla seconda cella dell'array e cioè avanzerà di 4 byte in memoria (puntatore ad intero sizeoff(int)==4!!!)
    fine --;    //funziona allo stesso modo di ++ ma ovviamente scala la cella
    }
}

int main() {
    const int DIM = 5;
    int numeri[DIM] = {1, 2, 3, 4, 5};

    cout << "Array originale: ";
    for (int i = 0; i < DIM; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;

    invertiArray(numeri, DIM);  //passando numeri ad un array nella funzione è come fare &numeri[0]

    cout << "Array invertito: ";
    for (int i = 0; i < DIM; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;

    return 0;
}