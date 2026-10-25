#include <iostream>
using namespace std;

int MCDricorsivo(unsigned N, unsigned M){
    if (N == 0)
        return M;
    return MCDricorsivo(M%N,N);
}

void stampaStringaContraria(char* stringa, int i){ //char* stringa == char stringa[]
    if (i<0)
        return ;    //per terminare la funzione void
    cout << stringa[i];
    stampaStringaContraria(stringa,i-1);
}

int main(){
    unsigned N,M;
    cin >> N >> M;
    cout << MCDricorsivo(N,M) << endl;
    char stringa[40];    //un array di char è come una stringa (si facevano così in C) e l'ultimo arattere è sempre /0 (speciale e riservato)
    //cin >> stringa;  mi fa inserire una stringa di max 5 caratteri
    cin.getline(stringa ,40 ,'.');     //uguale al cin ma con un separatore (il .), senza il separatore si ferma al primo invio
    //in c++ comunque si usa il type string che è un oggetto fatto apposta (#include <string>)
    cout << stringa;    //a differenza degli altri arr così stampa il contenuto effettivo!
    strlen(stringa);    //non si sa perché non va ma dovrebbe dare la lunghezza della stringa
    stampaStringaContraria(stringa,strlen(stringa)-1);
    return 0;
}