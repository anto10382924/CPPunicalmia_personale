#ifndef GESTORETEMPERATUREVECTOR_H
#define GESTORETEMPERATUREVECTOR_H

#include <iostream>
#include <vector>
using namespace std;

class VectorGT{
    private:
        vector<int> temperature;
    public:
        VectorGT():temperature(){}  //richiama la creazione di deafult della libreria vector (che è un vettore vuoto)
        VectorGT(const vector<int>& v):temperature(v){}
        VectorGT(const VectorGT& other):temperature(other.temperature){}

        const vector<int>& getTemperature() const{return temperature;}

        void setTemperature(const vector<int>& t){temperature = t;}
        void registraTemperatura(int t){temperature.push_back(t);}
        void modificaTemperatura(unsigned pos, int temp){
            if (pos > temperature.size())
                return ;
            temperature.at(pos) = temp;
        }
        void rimuoviTemperature(){
            if (temperature.size() > 0)
                temperature.pop_back();
        }
};

#endif