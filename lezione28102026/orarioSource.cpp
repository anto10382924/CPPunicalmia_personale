#include "orario.hpp"

ostream& operator<<(ostream& out, const Orario& o){
    out << o.ore <<":"<< o.minuti <<":"<< o.secondi << "\n";
    return out; 
}

istream& operator>>(istream& in, Orario& o){
    in >> o.ore >> o.minuti >> o.secondi;
    return in;
}

bool operator>(const Orario& A, const Orario& B){
    if (A.ore != B.ore)
        return A.ore > B.ore;
    if (A.minuti != B.minuti)
        return A.minuti > B.minuti;
    if (A.secondi != B.secondi)
        return A.secondi > B.secondi;
    return false;
}

bool operator<(const Orario& A, const Orario& B){
    if (A.ore != B.ore)
        return A.ore < B.ore;
    if (A.minuti != B.minuti)
        return A.minuti < B.minuti;
    if (A.secondi != B.secondi)
        return A.secondi < B.secondi;
    return false;
}

bool operator==(const Orario& A, const Orario& B){
    if (A.ore == B.ore && A.minuti == B.minuti && A.secondi == B.secondi)
        return true;
    return false; 
}

void stampaOrari(const Orario orari[], unsigned dim){
    for(unsigned i=0; i<dim; ++i){
        cout << orari[i];
    }
}

Orario calcolaDifferenzaMassima(const Orario orari[], unsigned dim){
    if (dim < 2)
        return orari[0];
    Orario massimo = orari[0];
    Orario minimo = orari[0];
    for(unsigned i=1; i<dim; ++i){
        if (orari[i] > massimo)
            massimo = orari[i];
        else if(orari[i] < minimo)
            minimo = orari[i];
    }
    return massimo -= minimo;
}

int main(){
    Orario o(12,7,54);
    Orario u(20,45,36);
    Orario arr[2];
    arr[0] = o;
    arr[1] = u;
    stampaOrari(arr,2);
    return 0;
}