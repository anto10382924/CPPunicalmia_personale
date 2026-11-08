#ifndef GESTORETVS_H
#define GESTORETVS_H

#include "GestoreTV.hpp"

class GestoreVTS:public GestoreVT{
    
    friend std::ostream& operator<<(std::ostream& o, const GestoreVTS& t);

    private:
        int scartate;
    public:
        GestoreVTS():GestoreVT(),scartate(0){}
        GestoreVTS(int& s):GestoreVT(),scartate(s){}
        int getScartate() const{return scartate;}
        void setScartate(const int& s){scartate=s;}
        void registraTemperatura(int temp);
        void modificaTemperatura(unsigned, int);
        int massima() const;
        int minima() const;
        double media() const;
};

#endif