#ifndef LISTAVOTI_H
#define LISTAVOTI_H

#include <iostream>
#include <vector>

class Listavoti: private std::vector<int>{
    public:
        void aggiungi(int voto);
        int primo() const;
        void rimuovi();
        int size() const;
        double media() const;
        void stampa() const;
};

#endif