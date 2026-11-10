#include <iostream>
#include <string>
using namespace std;

template<typename T>    //serve a "creare" un tipo (al posto di typename potrebbe esserci class, antico)
T massimo(T a, T b){    //funziona un po' come auto 
    if (a>b)
        return a;
    return b;
}

template<typename T1, typename T2>
void stampa(T1 dato1, T2 dato2){
    cout << dato1 << "\n" << dato2 << endl; //entrambi i tipi passati devono avere operator<< (come in questo caso string dal main), altrimenti va in errore di compilazione
}

template<typename T1, typename T2>  //lo fa durante l'esecuzione tipo PORCODDIO
class Pair{
    T1 primo;
    T2 secondo;
    public:
        Pair(const T1& p, const T2& s):primo(p),secondo(s){}
        T1 getPrimo(){return primo;}
        T2 getSecondo(){return secondo;}
};

int main(){
    int a=3, b=5;
    string x="Simona";
    string y = "Perri";
    cout << massimo(x,y) << endl;
    stampa(3,"dio");
    stampa(false,5454.76);
    Pair<int,char>p(3,'a');
    cout << p.getPrimo() << p.getSecondo() << endl;
    return 0;
}