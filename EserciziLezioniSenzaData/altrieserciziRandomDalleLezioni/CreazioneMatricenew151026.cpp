#include <iostream>
using namespace std;

void stampaMat(int ** M, int r, int c){
    for(unsigned i=0; i<r; ++i){
        for(unsigned j=0; j<c; ++j)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void leggiMat(int **M, int r, int c){   //M è per valore perché tanto NON modifichiamo M direttamente ma gli elementi al suo interno (le righe)
    for(unsigned i=0; i<r; ++i){
        for(unsigned j=0; j<c; ++j)
            cin >> M[i][j];
    }
}

int main(){
    int **M = new int* [4];    //array di puntatori ad intero
    //M[0] = new int [4];   crea una riga della matrice da 4 interi
    for(unsigned i=0;i<4;++i)  //creiamo le 4 righe
        M[i] = new int [3];
    //M[0][0] = 1;  entro nel primo array puntato da M (M[0]) e nella prima colonna (cella di M[0]) posiziono 1
    leggiMat(M,4,3);
    stampaMat(M,4,3);
    for(unsigned i=0;i<4;++i)
        delete [] M[i];    //devo rimuovere TUTTE le righe prima della matrice
    delete[] M;
    return 0;
}