#ifndef STU_H
#define STU_H
#include <string>
using namespace std;

const int NUM_ESAMI = 24;

class stu{
    private:
        string matricola;
        unsigned eta;
        unsigned esami_sostenuti;
        string nomi_esami[NUM_ESAMI];
        unsigned voti_esami[NUM_ESAMI];
        unsigned cfu_esami[NUM_ESAMI];
    public:
        stu():matricola(""),eta(0),esami_sostenuti(0){
            for (int i=0;i<NUM_ESAMI;++i)
                nomi_esami[i] = " ";
            for (int i=0;i<NUM_ESAMI;++i)
                voti_esami[i] = 0;
            for (int i=0;i<NUM_ESAMI;++i)
                cfu_esami[i] = 0;
            
        };
        stu(string s, unsigned e):matricola(s),eta(e){};

        //getter
        string getMatricola();
        unsigned getEta();
};

#endif