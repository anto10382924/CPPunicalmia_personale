#ifndef Data_H
#define Data_H

class Data{
    private:
        int giorno;
        int mese;
        int anno;
    public:
        Data();
        Data(int, int, int);

        int getGiorno() const;
        int getMese() const;
        int getAnno() const;

        void setGiorno(int);
        void setMese(int);
        void setAnno(int);

        void stampaData() const;
        void leggiData();
};

#endif