#ifndef CERCHIO_H
#define CERCHIO_H

#include <iostream>
#include "puntocartesiano.hpp"
using namespace std;

class Cerchio{

    private:
        PuntoCartesiano centro;
        int raggio;
    public:
        Cerchio()=default;
        Cerchio(const PuntoCartesiano &c, int r):centro(c),raggio(r){}
        Cerchio(const Cerchio &other){
            centro = other.centro;
            raggio = other.raggio;
        }

        const int getRaggio() const{return raggio;}
        const PuntoCartesiano getCentro() const;
        void setRaggio(int r){raggio = r;}
        void setCentro(PuntoCartesiano &c){centro = c;}
};

#endif