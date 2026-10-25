#include <iostream>
using namespace std;

void convertitore_valute(){
    float euro;
    cout << "Inserire valore in euro \n";
    cin >> euro;
    short unsigned valuta;
    cout << "In che valuta vuoi cambiare gli euro? 1=dollari, 2=Yen, 3=Pound \n";
    cin >> valuta;
    switch(valuta){
        case 1:
            cout << euro << "$ " << "in dollari: " << euro*1.08 << endl;
            break;
        case 2:
            cout << euro << "$ " << "in Yen: " << euro*168.22 << endl;
            break;
        case 3:
            cout << euro << "$ " << "in Sterline: " << euro*0.86 << endl;
            break;
        default:
            cout << "Nessun risultato possibile \n";
            break;
    }
}

long unsigned fattoriale_iterativo(long unsigned n){
    long unsigned fat = 1;
    if (n==0) return 1;
    for (unsigned i=n; i>1; --i){
        fat *= i;
    }
    return fat;
}

int main(){

    //unsigned x;
    //cin >> x;
    //cout << fattoriale_iterativo(x);
    //convertitore_valute();

    return 0;
}