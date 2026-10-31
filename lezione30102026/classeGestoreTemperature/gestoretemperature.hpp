#ifndef GESTORETEMPERATURE_H
#define GESTORETEMPERATURE_H

#include <iostream>
using namespace std;

class GestoreTemperature{

    friend ostream& operator<<(ostream&,const GestoreTemperature&);

    private:
        int* temperature;
        int dimensione;
    public:
        GestoreTemperature();
        GestoreTemperature(const int*, int);
        GestoreTemperature(const GestoreTemperature&);
        ~GestoreTemperature();

        const int* getTemperature() const;
        int getDimensione() const;

        void setTemperature(const int*, int);

        void registraTemperatura(int);
        void modificaTemperatura(unsigned, int);
        void rimuoviTemperatura();
};

#endif