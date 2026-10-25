#include "studente.hpp"
#include "Data.hpp"
#include <iostream>
using namespace std;

const int dim = 25;

studente::studente():mat(000000),nascita(){}

studente::studente(int mat, Data nasc){
    this -> mat = mat;
    nascita = nasc;     //operator=!!!
}

int studente::getVoto(int i) const{
    return voti[i];
}

void studente::setVoto(int i, int v){
    if (v >=0 && v <=30)
        voti[i] = v;
    else
        cout << "voto inserito non valido \n";
}

const int* studente::getVoti() const{   //problema di dimensione???
    return voti;
}

void studente::setVoti(int nuovivoti[]){    //devo assicurarmi che l'array inserito nel main abbia ESATTAMENTE 25 valori
    for(unsigned i=0;i < dim;++i){
        setVoto(i,nuovivoti[i]);
    }
}

void studente::setNascita(int g, int m, int a){
    nascita.setGiorno(g);   //anche direttamente nascita = Data(g,m,a);
    nascita.setMese(m);
    nascita.setAnno(a);
}

void studente::getNascita() const{
    nascita.stampaData();
}

void studente::stampaStudente() const{
    cout << "Matricola: " << mat << endl;
    cout << "Data di nascita: " << endl;
    nascita.stampaData();
    cout << "Voti: " << getVoti() << endl;
}

void studente::leggiStudente(){
    int matrice,num;
    cin >> matrice;
    mat = matrice;
    nascita.leggiData();
    for (unsigned i=0;i<dim;++i){
        cin >> num;
        voti[i] = num;
    }
}

double studente::getMedia(){
    int somma;
    for (unsigned i=0;i<dim;++i)
        somma += voti[i];
    return (double)somma/dim;
}

int studente::getvotoMax() const{
    int max = voti[0];
    for (unsigned i=1;i<dim;++i){
        if (voti[i] > max)
            max = voti[i];
    }
    return max;
}

int studente::getNumEsamiAllaLaurea() const{
    int count;
    for(unsigned i=0;i<dim;++i){
        if (voti[i] < 18)
            count += 1;
    }
    return count;
}

bool studente::studentePiuGiovaneDi(const studente & S) const{
    if (nascita.getAnno() < S.nascita.getAnno())
        return true;
    if (nascita.getAnno() == S.nascita.getAnno() && nascita.getMese() < S.nascita.getMese())
        return true;
    if (nascita.getAnno() == S.nascita.getAnno() && nascita.getMese() == S.nascita.getMese() && nascita.getGiorno() < S.nascita.getGiorno())
        return true;
    else
        return false;
}

int main(){

    return 0;
}