#include "stu.hpp"

class Esame{
    private:
        string nome;
        unsigned voto;
        unsigned cfu;
    public:
        Esame(string n, unsigned v, unsigned c):nome(n),voto(v),cfu(c){}
        Esame(const Esame & other){
            nome = other.nome;
            voto = other.voto;
            cfu = other.cfu;
        }

        //getter
        const string& getNome() const{return nome;} //per tipi composti meglio returnare un const &
        unsigned getVoto() const{return voto;}
        unsigned getCfu() const{return cfu;}
        
        //setter
        void setNome(string n){nome = n;}
        void setVoto(unsigned v){voto=v;}
        void setCfu(unsigned c){cfu = c;}
};

Stu::Stu(const Stu &other):matricola(other.matricola),eta(other.eta),esami_sost(other.esami_sost){
    for (unsigned i=0; i < NUM_ESAMI; ++i){
        nomi_esami[i] = other.nomi_esami[i];
        voti_esami[i] = other.voti_esami[i];
        cfu_esami[i] = other.cfu_esami[i];
    }
}

void Stu::setNomi_esami(string nuoviNomi[]){
    for (unsigned i=0; i<NUM_ESAMI; ++i)
        nomi_esami[i] = nuoviNomi[i];
}

void Stu::setVoti_esami(unsigned nuoviVoti[]){
    for (unsigned i=0; i<NUM_ESAMI; ++i)
        voti_esami[i] = nuoviVoti[i];
}

void Stu::setCfu_esami(unsigned nuoviCFU[]){
    for (unsigned i=0; i<NUM_ESAMI; ++i)
        cfu_esami[i] = nuoviCFU[i];
}

Stu & Stu::operator=(const Stu &other){
    if (this != &other){
        matricola = other.matricola;
        eta = other.eta;
        esami_sost = other.esami_sost;
        for (unsigned i=0; i< other.esami_sost; ++i){
            nomi_esami[i] = other.nomi_esami[i];
            voti_esami[i] = other.voti_esami[i];
            cfu_esami[i] = other.cfu_esami[i];
        }
    }
    return *this;
}

void Stu::aggiungiEsame(const string& esame, unsigned voto, unsigned cfu){
    if (esami_sost < NUM_ESAMI){
        nomi_esami[esami_sost] = esame;
        voti_esami[esami_sost] = voto;
        cfu_esami[esami_sost] = cfu;
        ++esami_sost;
    }
    else
        cout << "Numero esami sostenuti già al massimo!!! \n";
}

void Stu::rimuoviUltimoesame(){
    if (esami_sost == 0)
        cout << "Non ci sono esami \n";
    else{
        --esami_sost;
        nomi_esami[esami_sost] = " ";
        voti_esami[esami_sost] = 0;
        cfu_esami[esami_sost] = 0; 
    }
}

float Stu::getMediaVoti() const{
    int somma = 0;
    for (unsigned i=0; i < esami_sost; ++i)
        somma += voti_esami[i];
    return (float)somma/esami_sost;
}

float Stu::getMediaPonderata() const{
    if (esami_sost == 0)    
        return 0;
    int prodottoV_C = 0;
    int sommaCFU = 0;
    for (unsigned i=0; i < esami_sost; ++i){
        prodottoV_C += (voti_esami[i]*cfu_esami[i]);
        sommaCFU += cfu_esami[i];
    }
    return (float)prodottoV_C/sommaCFU;
}

bool bestStudents(const Stu studenti[], unsigned numeroStudenti){
    for(unsigned i=0; i<numeroStudenti; ++i){
        if (studenti[i].getMediaPonderata() < 28)
            return false;
    }
    return true;
}

unsigned numeroEsamiAllaLaurea(const Stu studenti[], unsigned numeroStudenti){
    if (numeroStudenti == 0)
        return NUM_ESAMI;
    unsigned max_esami = studenti[0].getEsami_sost();
    for(unsigned i=1; i<numeroStudenti; ++i){
        if (max_esami < studenti[i].getEsami_sost())
            max_esami = studenti[i].getEsami_sost();
    }
    return NUM_ESAMI - max_esami;
}

bool stessiVoti(const Stu& s1, const Stu& s2){      //da finì
    if (s1.getEsami_sost() != s2.getEsami_sost())
        return false;

    return true;
}

string getMatricolaStudenteGiovaneEBravo(const Stu studenti[], unsigned numeroStudenti){    //si può fare con variabile "indicemigliore"
    Stu migliore;
    int start = -1;
    for (unsigned i=0; i<numeroStudenti; ++i){
        if (studenti[i].getEta() <= 20 && studenti[i].getEsami_sost() >= 3){
            migliore = studenti[i];
            start = i;
            break;
        }    
    }
    if (start == -1)
        return "---";
    for (unsigned i=start; i<numeroStudenti; ++i){
        if (studenti[i].getEta() <= 20 && studenti[i].getEsami_sost() >= 3){
            if (migliore.getMediaVoti() < studenti[i].getMediaVoti())
                migliore = studenti[i];
            if (migliore.getMediaVoti() == studenti[i].getMediaVoti() && migliore.getEta() > studenti[i].getEta())
                migliore = studenti[i];
        }
    }
    return migliore.getMatricola();
}

ostream& operator<<(ostream& out, const Stu& s){
    out << s.matricola << s.eta << s.esami_sost << "\n";
    for (unsigned i=0;i<s.esami_sost;++i){
        out << s.nomi_esami[i] << s.voti_esami[i] << s.cfu_esami[i] << "\n";
    }
    return out;
}

istream& operator>>(istream& in, Stu & s){
    in >> s.matricola >> s.eta >> s.esami_sost;
    for (unsigned i=0;i<s.esami_sost;++i){
        in >> s.nomi_esami[i] >> s.voti_esami[i] >> s.cfu_esami[i];
    }
    return in;
}

bool operator>(const Stu& a, const Stu& b){ //si può fare molto più rapidamente returnando direttamente > (vedi operator<)
    if (a.eta > b.eta)
        return true;
    if (a.eta == b.eta && a.esami_sost > b.esami_sost)
        return true;
    if (a.eta == b.eta && a.esami_sost == b.esami_sost && a.matricola > b.matricola)    //qui confronta i caratteri ASCII delle stringhe, la "minore" sarà quella vera.
        return true;
    return false;
}

bool operator<(const Stu& a, const Stu& b){
    if (a.eta != b.eta)
        return a.eta < b.eta;
    if (a.esami_sost != b.esami_sost)
        return a.esami_sost < b.esami_sost;
    if (a.matricola != b.matricola)
        return a.matricola < b.matricola;
    return true;    //se sono completamente uguali bohhh (aggiunta mia)
}

Stu& Stu::operator+=(const Esame& e){
    if (esami_sost == NUM_ESAMI){
        cout << "numero esami al massimo, restituisco lo stesso studente.";
        return *this;
    }
    nomi_esami[esami_sost] = e.getNome();
    voti_esami[esami_sost] = e.getVoto();
    cfu_esami[esami_sost] = e.getCfu();
    esami_sost ++;
    return *this;
}

int main(){
    int k;
    cout << "Inserire il numero di studenti che si vogliono \n";
    cin >> k;
    Stu studenti[k];
    cout << bestStudents(studenti,k);
    cout << numeroEsamiAllaLaurea(studenti,k);
    cout << stessiVoti(studenti[0],studenti[1]);
    return 0;
}