#include <iostream>
using namespace std;

int main() {
    int n,num,somma=0;
    float media;
    cout << "Quanti numeri vuoi inserire? ";
    cin >> n;
    int *arr = new int [n];

    for (unsigned i=0; i<n; i++){   //qui sarebbe meglio usare int per il confronto con n (che è signed)
        cin >> num;
        arr[i] = num;
        somma += arr[i];
    }

    media = (float)somma/n;
    cout << "somma: " << somma << " media : " << media << endl;
    delete[] arr;   //con array dinamico SEMPRE va scritto prima di uscire dall'esecuzione.
    arr = nullptr;  //è buona prassi !
    return 0;
}