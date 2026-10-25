#include <iostream>
using namespace std;

void stampa(){          //una funzione void esegue le operazioni ma non restituisce un risultato, può mancare di return
    cout << "dio \n";
}

int quadrato(int n){    //se metti una & davanti ad n la modifica avviene anche sulla variabile numero del main, modifichi per variabile e non per valore diooooo
    return n*n;
}

int main(){
    const unsigned n = 5;
    int A[n] = {1};   //la pos. 0 al valore 1, tutte le altre allo 0
    int num;
    cout << "inserisci numeri finchè non inserisci 0 \n";
    cin >> num;
    int j = 0;
    while (num!=0 && j<n){
        A[j++] = num;
        cin >> num;
    }
    // j è il numero di elementi che ho effettivamente inserito
    for (unsigned i=0; i < j; ++i){
        cout << A[i] << " ";    //stampiamo solo i primi j elementi (quelli inseriti dei 5 spazi)
    }
    int x;
    cout << "Quale elemento vuoi cercare e rimuovere??? \n";
    cin >> x;
    unsigned i;
    for (i=0; i<j; ++i){
        if (A[i] == x){
            break;
        }
    }
    if (i < j){
        cout << "ho trovato l'elemento in posizione " << i << endl;
        j-=1;    //ERRORE QUI NON SO COME MAI
        for (unsigned k=0; k<j; ++k)
            A[k] = A[k+1];
        for (unsigned u=0;u<j;++u)
            cout << A[u] << " ";
    }else{    //sarebbe if i==j
        cout << "non ho trovato l'elemento " << x << endl;
    }
    int numero = 2;
    int q=quadrato(numero);      //passo numero alla funzione
    cout<<q;
    stampa();       //non serve il cout non avendo un return!!!
    return 0;
}

/*
    1.usiamo il do while quando ci serve fare le istruzioni dentro al ciclo almeno 1 volta
    char x;
    do{       
        cin>>x;
        cout<<x;
    }while(x!='o');

    2. usiamo lo switch per descrivere dei casi possibili, in maniera limitata
    int a,b;
    cin>>a>>b;
    char op;
    cin>>op;
    switch(op){
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        default:                    //serve se nessun caso è stato "scelto"
            cout<<"boh ";
            break;
    }
*/