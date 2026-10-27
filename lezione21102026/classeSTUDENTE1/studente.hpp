#include "Data.hpp"
#ifndef STUDENTE_H
#define STUDENTE_H

class studente{
    private:
        int mat;
        Data nascita;   //questa è chiamata composizione
        int voti[25];
    public:
        studente();
        studente(int, Data);
        int getMat() const{return mat;};
        void setMat(int matr){mat=matr;};
        int getVoto(int) const;
        void setVoto(int, int);
        const int* getVoti() const;
        void setVoti(int []);
        void setNascita(int, int, int);
        void getNascita() const;
        void stampaStudente() const;
        void leggiStudente();
        double getMedia();
        int getvotoMax() const;
        int getNumEsamiAllaLaurea() const;
        bool studentePiuGiovaneDi(const studente & S) const;
};

#endif