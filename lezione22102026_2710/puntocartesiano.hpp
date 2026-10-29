#ifndef PUNTOCARTESIANO_H
#define PUNTOCARTESIANO_H
using namespace std;

class PuntoCartesiano{

    //è consigliato mettere tutte le funzioni operator di una classe come friend, anziché direttamente come metodi

    friend bool operator>(const PuntoCartesiano &, const PuntoCartesiano &);  //la funzione esterna alla classe viene riconosciuta "friend", può accedere direttamente ai dati privati della classe
    friend ostream& operator<<(ostream&,const PuntoCartesiano &);  //ostream è il tipo di cout
    friend istream& operator>>(istream &,PuntoCartesiano &);   //istream è il tipo di cin
    friend PuntoCartesiano operator+(const PuntoCartesiano &, const PuntoCartesiano &);

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
        PuntoCartesiano& operator++(int){   //lezione del 29, l'int serve solo a far capire se è pre o post
            ++ x;                         
            ++ y;
            return *this;   //tutto l'oggetto
        }
        PuntoCartesiano operator++(){   //post-incremento
            PuntoCartesiano temp = *this;    //copiamo l'oggetto che stiamo modificando
            ++(*this);      //invochiamo il metodo di prima
            return temp;    //non abbiamo un riferimento al tipo di ritorno per questo, restituiamo una copia del PuntoCartesiano iniziale
        }
        PuntoCartesiano& operator+=(const PuntoCartesiano& other){
            this -> x += other.x;
            this -> y += other.y;
            return *this;
        }
};

#endif