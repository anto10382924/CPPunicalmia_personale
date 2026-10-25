#ifndef PUNTOCARTESIANO_H
#define PUNTOCARTESIANO_H

class PuntoCartesiano{
    private:
        int x;
        int y;
    public:
        //PuntoCartesiano()=default; se vuoi lasciarlo come dice cpp
        PuntoCartesiano();
        PuntoCartesiano(int, int);
        PuntoCartesiano(const PuntoCartesiano &);   //costruttore per copia, obbligatoriamente scritto così

        int getX() const;
        int getY() const;

        void setX(int);
        void setY(int);
        void stampaPunto() const;
        void stampaInvertiti(const PuntoCartesiano &);

        double distanza(const PuntoCartesiano &) const;

        //void operator=(const PuntoCartesiano &);    //vecchio metodo, possiamo modificarlo a nostro piacimento implementandolo
        PuntoCartesiano& operator=(const PuntoCartesiano &); //nuovo metodo per permettere tripla (o +) assegnazione
        //L'& nel datatype della funzione va messo in modo da non creare una copia dell'oggetto e quindi per effettivamente cambiarlo.
};

#endif