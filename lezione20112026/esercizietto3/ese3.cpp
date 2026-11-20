#include <iostream>
#include <list>
using namespace std;

int main(){
    srand(time(nullptr));
    list<int> l;
    for (int i = 0; i < 15; ++i) {
        l.push_back(rand() % 100+1);
    }
    for (auto i : l)
        cout << i << " ";
    cout << endl;
    for (auto it=l.begin();it != l.end();){
        if (*it<=50)
            it=l.erase(it);
        else ++it;
    }
    for (auto i : l)
        cout << i << " ";
    cout << endl;
    double somma = 0;
    for (auto n : l)
        somma += n;
    if (!l.empty()) //controlliamo che la lista non sia vuota
        cout << somma/l.size();
    l.unique(); //se ci sono dei numeri duplicati ADIACENTI rimuove quelli.
    return 0;
}

//la libreria ha un sort interno e NON si può utilizzare l'algoritmo sort di algorithm
//perchè gli iteratori delle list sono nodi, non vai a scambiare direttamente i valori 
//dei nodi ma scambi fra loro i puntatori dei nodi appunto. (usare i puntatori costa anche infinitamente meno con oggetti pesanti)