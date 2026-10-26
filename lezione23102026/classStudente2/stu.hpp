#ifndef STU_H
#define STU_H
#include <string>
using namespace std;

const unsigned NUM_ESAMI = 24;

class Stu{
    private:
        string matricola;
        unsigned eta;
        unsigned esami_sost;
        string nomi_esami[NUM_ESAMI];
        unsigned voti_esami[NUM_ESAMI];
        unsigned cfu_esami[NUM_ESAMI];
    public:
        Stu():matricola(""),eta(0),esami_sost(0){
            for (int i=0;i<NUM_ESAMI;++i)
                nomi_esami[i] = " ";
            for (int i=0;i<NUM_ESAMI;++i)
                voti_esami[i] = 0;
            for (int i=0;i<NUM_ESAMI;++i)
                cfu_esami[i] = 0;
            
        };
        Stu(string s, unsigned e):matricola(s),eta(e){};
        Stu(const Stu &);

        //getter
        string getMatricola() const{return matricola;}
        unsigned getEta() const{return eta;}
        unsigned getEsami_sost() const{return esami_sost;}
        string getNome_esame(int i) const{return nomi_esami[i];}
        const string* getNomi_esami() const{return nomi_esami;}
        unsigned getVoto_esame(int i) const{return voti_esami[i];}
        const unsigned* getVoti_esami() const{return voti_esami;}
        unsigned getCfu_esame(int i) const{return cfu_esami[i];}
        const unsigned* getCfu_esami() const{return cfu_esami;}

        //setter
        void setMatricola(string m){matricola = m;}
        void setEta(unsigned e){eta = e;}
        void setEsami_sost(unsigned e){esami_sost = e;}
        void setNomi_esami(string []);
        void setNome_esame(string n, int i){nomi_esami[i]=n;}
        void setVoti_esami(unsigned []);
        void setVoto_esame(int i, unsigned v){voti_esami[i]=v;}
        void setCfu_esami(unsigned []);
        void setCfu_esame(int i, unsigned cfu){cfu_esami[i]=cfu;}

        Stu &operator=(const Stu &);
        void aggiungiEsame(const string&, unsigned, unsigned);
        void rimuoviUltimoesame();
        float getMediaVoti() const;
        float getMediaPonderata() const;
};

#endif