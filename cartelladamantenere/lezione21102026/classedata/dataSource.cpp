#include "Data.hpp"
#include <iostream>
using namespace std;

Data::Data(){
    giorno = 1;
    mese = 1;
    anno = 2026;
}

Data::Data(int giorno, int mese, int anno){
    if (giorno >= 1 && giorno <=31)
        this -> giorno = giorno;
    if (mese >= 1 && mese <=12)
        this -> mese = mese;
    if (anno >= 1900 && anno <=2029)
        this -> anno = anno;
}

int Data::getGiorno() const{
    return giorno;
}

int Data::getMese() const{
    return mese;
}

int Data::getAnno() const{
    return anno;
}

void Data::setGiorno(int giorno){
    this -> giorno = giorno;
}

void Data::setMese(int mese){
    this -> mese = mese;
}

void Data::setAnno(int anno){
    this -> anno = anno;
}

void Data::stampaData() const{
    cout << giorno << "/" << mese << "/" << anno << endl;
}

void Data::leggiData(){
    int g,a,m;
    cout << "Inserisci giorno \n";
    cin >> g;
    cout << "Inserisci mese \n";
    cin >> m;
    cout << "Inserisci anno \n";
    cin >> a;
    setGiorno(g);
    setMese(m);
    setAnno(a);
}

int main(){
    Data oggi;
    oggi.setGiorno(23);
    oggi.setMese(10);
    oggi.setAnno(2026);
    oggi.stampaData();
    oggi.leggiData();
    oggi.stampaData();
    return 0;
}