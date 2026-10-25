#include <iostream>
using namespace std;

int prodotto(const int &a,int &b){
    int risultato = 0;
    int i=0;
    while (i<b){
        risultato += a;
        ++i;
    }
    return risultato;
}


int main(){

    int x,y;
    cin >> x >> y;
    cout << prodotto(x,y);

    return 0;
}