#include <iostream>
#include <list>
using namespace std;

int main(){
    list <int> lista = {1,2,3,4,5,6,7,8};   //si usa una lista stl quando non ci interessa accedere agli elementi per indice
    for (auto i : lista)
        cout << i << " " << endl;
    for (auto it = lista.begin(); it != lista.end();){
        if (*it%2==0)
            it=lista.erase(it);
        else ++it;  //lo mettiamo qui perchè quando facciamo erase it diventa il successivo
    }
    for (auto i : lista)
        cout << i << " " << endl;
    return 0;
}   