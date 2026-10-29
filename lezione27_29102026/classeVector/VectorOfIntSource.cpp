#include "VectorOfInt.hpp"

void stampa(const VectorOfInt &v){
    for(unsigned i=0; i<v.getSize(); ++i){
        cout << v[i] << " ";
    }
}

int main(){
    VectorOfInt V(7);   //se scrivo così il 7 è "cap" (int cap)
    VectorOfInt Q(V);   //NO, finchè non implementi il costruttore per copia (vedi .hpp), così il distruttore di default agiusce sullo stesso array dell'heap (A)
    VectorOfInt* VD = new VectorOfInt(7);   //facendo così se poi NON fai delete VD sei fottuto, il distruttore è per l'array al suo interno, non per l'oggetto in se
    delete VD;
    V=Q;    //anche qui di default NO, va implementato (vedi .hpp)
    V.push_back(3);
    V.push_back(4);
    V.push_back(5);
    V[2]=0; //NOOOO, finchè non implementi l'operatore [] (cioè devono essere dei valori da cambiare prima)
    return 0;
}