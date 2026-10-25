#include <iostream>
using namespace std;

void fatt_iterativo(unsigned n){
    int risultato=n;
    for (unsigned i=n-1;i!=0;--i){
        risultato *= i;
    }
    cout << risultato << endl;
}

int fatt_rico(unsigned n, unsigned risultato){
    if (n==1)
        return risultato;
    else
        return fatt_rico(n-1,risultato*=n);
}

int main(){
    unsigned n;
    cin >> n;
    if (n%2==0)
        fatt_iterativo(n);
    else cout << fatt_rico(n,1) << endl;

    return 0;
}