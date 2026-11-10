#include <iostream>
using namespace std;

enum Stagione{Autunno /*0*/, Inverno/*1*/, Primavera/*2*/, Estate/*3*/}; //le stagioni sono enumerabili, per questo enum (si usa per cose del genere), questa è la versione CLASSICA
enum class StagioneNuova{AUT=2,INV=4,PRIM,EST}; //versione MODERNA, gli assegnamenti anche con quella classica si possono fare

int chiamate(){
    static int x = 0;   //siccome è dichiarata static "persiste in memoria" anche uscendo dal suo scope
    return ++x;
}

class Contatore{
    public:
        static int counter; //un attributo statico è condiviso fra TUTTI gli oggetti della classe, si inizializza fuori dalla classe.
        Contatore(){++counter;}
        Contatore(const Contatore& other) = delete; //serve a rendere impossibile l'operatore per copia (usabile anche su altri metodi)
        static int getCounter(){return counter;}    //la dichiariamo static anche qui in modo da non doverla richiamare PERFORZA su un singolo oggetto (basta fare Contatore::getCounter)
};

int Contatore::counter = 0; //inizializzo fuori da qualsiasi scope la variabile statica

class Temperatura{
    double gradi;
    public:
        explicit Temperatura(double t):gradi(t){}   //serve a vietare che venga chiamato il costruttore facendo conversioni (3 esempio del main)
};

constexpr int quadrato(int x){  //con questa dicitura compilerbbe anche senza la magia del g++
    return x*x;
}

int main(){
    int x = 10;
    auto a=x;   //intero
    auto b= 3.14;   //double
    auto c = '1';   //char
    auto &r = x;    //riferimento ad intero
    const auto& cr = x; //riferimento costante ad intero

    int numeri[]={10,20,30};
    for (int n : numeri){   //n è una nuova variabile che volta per volta diventa = all'elemento dell'array
        n = 7;
        cout << n << endl;
    }
    cout << numeri[0];  //quindi qui torna 10, n non c'è più, sarebbe 7 se nel for fosse int& n!!!

    Stagione s = Autunno;   //autunno è una costante e la stiamo assegnando ad s, come intero 0!
    //cin >> s; NOOO, il valore è assegnato solo sullo script
    StagioneNuova sn;
    sn = StagioneNuova::AUT;    //se si usa moderna allora bisogna specificare la classe (così se abbiamo cosstanti con lo stesso nome non ci sono ambiguità)

    for (unsigned i=0;i<3;++i)
        cout << chiamate() << endl; //stampa 1 2 e poi 3, siccome è static la x della funzione

    Contatore c0;
    Contatore c1;
    c0.counter++;    //modifica il counter di tutti gli oggetti della classe
    Contatore::counter ++;  //è il metodo più adatto per modificare un'attributo statico di una classe, non ha molto senso farlo su un solo oggetto siccome lo modifica comunque per tutti.

    Temperatura t(3.14);
    Temperatura t1{1.14};   //in tutti e 3 i casi richiama il costruttore
    //Temperatura t2=3.5; in questo caso fa una conversione per poter usare il costruttore (con explicit non va appunto)

    int array[quadrato(3)]; //questa dichiarazione non è standard, deve essere un valore noto in tempo di compilazione.(non da errore per il g++)
    int array[3*3]; //qui compila con lo std perchè l'operazione sta nel main

    return 0;
}