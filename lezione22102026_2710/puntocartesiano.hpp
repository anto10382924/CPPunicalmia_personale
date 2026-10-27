#ifndef PUNTOCARTESIANO_H
#define PUNTOCARTESIANO_H

class PuntoCartesiano{

    friend bool operator>(const PuntoCartesiano &P, const PuntoCartesiano &Q);  //la funzione esterna alla classe viene riconosciuta "friend", può accedere direttamente ai dati privati della classe!
    
    private:
        int x;
        int y;
    public:
        //se ho PuntoCartesiano(int, int); DEVO scrivere anche quello di default altrimenti non compilerà quando dichiareremo un oggetto senza dargli valori.
        //PuntoCartesiano()=default; se vuoi lasciarlo come dice cpp, puoi usarlo sui costruttori che hanno comportamenti di default (tipo senza parametri o per copia)
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
        bool operator==(const PuntoCartesiano &) const;
        bool operator>(const PuntoCartesiano &) const;
};

#endif