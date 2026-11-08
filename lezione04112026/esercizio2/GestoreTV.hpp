#ifndef GESTOREVT_H
#define GESTOREVT_H

#include <iostream>
#include <vector>

class GestoreVT{

    friend std::ostream& operator<<(std::ostream&, const GestoreVT&);

    protected:
        std::vector<int> temperature;
    public:
        GestoreVT():temperature(){}
        GestoreVT(const std::vector<int> &t):temperature(t){}
        void registraTemperatura(int);
        void modificaTemperatura(unsigned, int);
        void rimuoviTemperatura();
};

#endif