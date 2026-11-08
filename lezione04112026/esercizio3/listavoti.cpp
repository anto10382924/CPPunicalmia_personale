#include "listavoti.hpp"

void Listavoti::aggiungi(int voto){
    if (voto >=18 && voto <=30)
        push_back(voto);
}

int Listavoti::primo() const{
    if (empty())
        return 0;
    else
        return at(0);
}

void Listavoti::rimuovi(){
    if (empty())
        return ;
    else
        erase(begin());
}

int Listavoti::size() const{
    return size();
}

double Listavoti::media() const{
    if (empty())
        return 0.0;
    int somma = 0;
    for (int i : *this) //*this sarebbe il vettore ereditato sium
        somma += i;
    return static_cast<double>(somma) / size();
}

void Listavoti::stampa() const{
    for (int i : *this)
        std::cout << i << std::endl;
}