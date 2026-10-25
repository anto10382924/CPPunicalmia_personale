#ifndef RETTANGOLO_H    //serve per non definirlo ad ogni include dove lo richiamiamo (ottimizzazione)
#define RETTANGOLO_H

class rettangolo {
    private:    //qualcosa sul principio dell'incapsulamento boh, qui vanno le cose che definiscono la classe stessa
        float lunghezza = 1.0;  //l'inizializzazione è per i valori di default
        float altezza = 1.0;

    public:     //funzioni che verranno poi usate esternamente alla classe stessa
        rettangolo();   //costruttore di default

        float getPerimetro() const;   //nel file header le funzioni vanno solo definite, per ordine
        float getArea() const;

        float getLunghezza() const;
        float getAltezza() const;

        void setLunghezza(float lunghezza);
        void setAltezza(float altezza);
};

#endif