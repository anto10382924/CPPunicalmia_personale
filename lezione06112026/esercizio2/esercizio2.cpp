#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Mappa{
    private:
    vector <string> griglia;
    public:
        Mappa(const vector<string>& righe):griglia(righe){}
        int righe() const{return griglia.size();}
        int colonne() const{
            if (griglia.empty())
                return 0;
            string prima_riga = griglia.at(0);
            int numero_colonne = 0;
            for (int i=0;i < prima_riga.size(); ++i)    //return griglia.at(0).size();
                numero_colonne += 1;
            return numero_colonne;
        }
        bool libera(int x, int y) const{
            if (x < righe() && y < colonne() && x >=0 && y>=0)
                return griglia[x][y] != '#';
            return false;
        }
        bool raccogli(int x, int y){
            if (x >=0 && x<righe() && y>=0 && y < colonne()){
                if (griglia[x][y] =='o'){
                    griglia[x][y] = '.';
                    return true;
                }
            }
            return false;
        }
        int campioniRimasti() const{
            if (griglia.empty())
                return 0;
            int count = 0;
            for (int i=0;i<righe();++i){
                for (int j=0; j<colonne();++j){
                    if (griglia[i][j] == 'o')
                        count ++;
                }
            }
            return count;
        }
        void stampa(int rx, int ry, char simbolo) const{
            if (griglia.empty()){
                cout << "La mappa è vuota \n";
                return ;
            }
            if (!libera(rx,ry))
                return ;
            for (int i=0;i<righe();++i){
                for (int j=0; j<colonne();++j){
                    if (i==rx && j==ry)
                        cout << simbolo << "\t";
                    else
                        cout << griglia[i][j] << "\t";
                }
                cout << endl;
            }
        }
};

class Rover{
    private:
        int x;
        int y;
        int batteria;
        int direzione;
        int campioni = 0;
    public:
        Rover(int x, int y, int direzione, int batteria):x(x),y(y),batteria(batteria),direzione(direzione){}
        int getX() const{return x;}
        int getY() const{return y;}
        int getBatteria() const{return batteria;}
        int getCampioni() const{return campioni;}
        void sposta(int dx, int dy){
            x += dx;
            y += dy;
        }
        void ruota(int delta){
            if (delta != -1 && delta !=1){
                cout << "direzione non valida \n";
                return ;
            }
            if (delta == 1) {
                if (direzione == 3) //se guarda ad ovest e gira a dx guarda a nord
                    direzione = 0;
                else
                    direzione += 1;
            } else { // qui delta è sicuramente -1
                if (direzione == 0) //se guarda a nord e gira a sx guarda a ovest
                    direzione = 3;
                else
                    direzione -= 1;
            }
        }
        int dx() const{
            if (direzione == 0)
                return -1;
            if (direzione == 1)
                return  0;
            if (direzione == 2)
                return  +1;
            return 0;
        }
        int dy() const{
            if (direzione == 0)
                return 0;
            if (direzione == 1)
                return  +1;
            if (direzione == 2)
                return  0;
            return -1;
        }
        bool consuma(int unita){
            if (batteria < unita)
                return false;
            batteria -= unita;
            return true;
        }
        void aggiungiCampione(){campioni +=1;}
        char simbolo() const{
            if (direzione == 0)
                return '^';
            if (direzione == 1)
                return '>';
            if (direzione == 2)
                return 'v';
            return '<';
        }
};

class Comando{
    public:
        virtual ~Comando() {}
        virtual bool esegui(Rover& r, Mappa& m) const = 0;
        virtual string descrizione() const = 0;
        virtual int costo() const { return 1; }
        virtual Comando* clone() const = 0;
};

class Avanza:public Comando{
    private:
        int passi;
    public:
        Avanza(int p):passi(p){}
        bool esegui(Rover& r, Mappa& m) const override{
            int rx = r.getX();
            int ry = r.getY();
            for (int i=0;i<passi;++i){
                rx += r.dx();
                ry += r.dy();
                if (!m.libera(rx, ry))
                    return false;
            }
            if(!r.consuma(costo())){
                return false;
            }
            r.sposta(r.dx() * passi, r.dy() * passi);
            return true;
        }
        string descrizione() const override{
            return "muove il rover di" + to_string(passi) + "celle; non si muove e restituisce false se sul percorso c'è una roccia \n";
        }
        int costo() const override{
            return passi;
        }
        Comando* clone() const override { return new Avanza(*this); }
};

class Ruota:public Comando{
    private:
        bool destra;
    public:
        Ruota(bool direzione):destra(direzione){}
        string descrizione() const override{
            if (!destra)
                return "gira di 90° a sinistra \n";
            else
                return "gira di 90° a destra\n";
        }
        bool esegui(Rover& r, Mappa& m) const override{
            if (!r.consuma(costo()))
                return false;
            if (!destra)
                r.ruota(-1);
            else
                r.ruota(1);
            return true;
        }
        Comando* clone() const override { return new Ruota(*this); }
};

class Raccogli:public Comando{
    public:
    using Comando::Comando;
        string descrizione() const override{
            return "raccoglie il campione nella cella corrente \n";
        }
        int costo() const override{return 3;}
        bool esegui(Rover& r, Mappa& m) const override{
            if (r.getBatteria()<costo()){
                return false;
            }
            if (!m.raccogli(r.getX(),r.getY())){
                return false;
            }
            r.consuma(costo());
            r.aggiungiCampione();
            return true;
        }
        Comando* clone() const override { return new Raccogli(*this); }
};

class Programma{
    private:
        vector <Comando*> comandi;
    public:
        Programma():comandi(){} //costruttore
        Programma(const Programma& p){  //costruttore per copia
            for (int i=0;i<p.comandi.size();++i)
                comandi.push_back(p.comandi[i] -> clone());
        }
        ~Programma(){   //distruttore che pulisca profondamente il vettore dei new "copie"
            for (int i=0;i<comandi.size();++i)
                delete comandi[i];
        }
        Programma& operator=(const Programma& p){   //operator= ,profondo
            if (this != &p){
                for (int i=0;i<comandi.size();++i){
                    delete comandi[i];
                }
                comandi.clear();
                for (int i=0;i<p.comandi.size();++i)
                    comandi.push_back(p.comandi[i] -> clone());
            }
            return *this;
        }
        void aggiungi(const Comando& c){
            Comando* c1 = c.clone();
            comandi.push_back(c1);
        }
        int size() const{return comandi.size();}    //l'ho inteso come "restituiscimi il numero di comandi salvati"
        int costoTotale() const{
            int tot=0;
            for (int i=0;i<size();++i)
                tot += comandi[i]->costo();
            return tot;
        }
        void stampa() const{    //l'ho inteso come "stampa che cosa fanno i vari comandi al suo interno"
            if (size() <= 0)
                cout << "Nessun comando eseguito \n";
            for (int i=0;i<size();++i)
                cout << comandi[i] -> descrizione() << endl;
        }
        bool esegui(Rover& r, Mappa& m, bool passoPasso) const{
            for (int i=0;i<size();++i){
                if(!comandi[i]->esegui(r,m))
                    return false;
                if (passoPasso == true)
                    m.stampa(r.getX(),r.getY(),r.simbolo());
            }
            return true;
        }
};

int main() {
    vector<string> g = {
        "#########",
        "#...o...#",
        "#.##.##.#",
        "#.#o..#.#",
        "#...##..#",
        "#o......#",
        "#########"
    };

    Mappa m(g);
    Rover r(1, 1, 1, 40);

    // 1. Costruzione programma completo per raccogliere tutti e 3 i campioni
    Programma p1;
    p1.aggiungi(Avanza(3));
    p1.aggiungi(Raccogli());
    p1.aggiungi(Ruota(true));
    p1.aggiungi(Avanza(2));
    p1.aggiungi(Ruota(true));
    p1.aggiungi(Avanza(1));
    p1.aggiungi(Raccogli());
    // Continuazione per il 3° campione in (5,1):
    p1.aggiungi(Ruota(false));
    p1.aggiungi(Avanza(2));
    p1.aggiungi(Ruota(true));
    p1.aggiungi(Avanza(2));
    p1.aggiungi(Raccogli());

    cout << "=== PROGRAMMA P1 ===" << endl;
    p1.stampa();
    cout << "Costo totale: " << p1.costoTotale() << endl;

    bool esito = p1.esegui(r, m, false); // metti true se vuoi vederlo passo passo
    cout << "\nEsito esecuzione: " << (esito ? "SUCCESSO" : "FALLITO") << endl;
    cout << "Posizione finale: (" << r.getX() << ", " << r.getY() << ")" << endl;
    cout << "Campioni raccolti: " << r.getCampioni()
         << " (rimasti sulla mappa: " << m.campioniRimasti() << ")" << endl;
    cout << "Batteria residua: " << r.getBatteria() << endl;
    m.stampa(r.getX(), r.getY(), r.simbolo());

    // 2. Test copia profonda: Programma p2 = p1;
    cout << "\n=== TEST COPIA PROFONDA (P2 = P1) ===" << endl;
    Programma p2 = p1;
    p2.aggiungi(Ruota(true));
    cout << "Comandi in p1 (deve restare invariato): " << p1.size() << endl;
    cout << "Comandi in p2 (deve avere 1 comando in piu'): " << p2.size() << endl;

    // 3. Test collisione contro una roccia
    cout << "\n=== TEST COLLISIONE ROCCIA ===" << endl;
    Mappa mRoccia(g);
    Rover rRoccia(1, 1, 2, 40); // guarda a Sud (2): in (2,1) e' libero, in (2,2) c'e' roccia '#'
    Programma pRoccia;
    pRoccia.aggiungi(Avanza(1));    // va in (2,1) -> OK
    pRoccia.aggiungi(Ruota(false)); // guarda a Est (1) -> OK
    pRoccia.aggiungi(Avanza(2));    // sbatte contro '#' in (2,2) -> DEVE FERMARSI QUI
    pRoccia.aggiungi(Raccogli());   // NON deve essere eseguito

    bool esitoRoccia = pRoccia.esegui(rRoccia, mRoccia, false);
    cout << "Esito (atteso 0/false): " << esitoRoccia << endl;
    cout << "Posizione (attesa 2, 1): (" << rRoccia.getX() << ", " << rRoccia.getY() << ")" << endl;
    cout << "Batteria residua (attesa 38): " << rRoccia.getBatteria() << endl;

    // 4. Test batteria insufficiente
    cout << "\n=== TEST BATTERIA INSUFFICIENTE ===" << endl;
    Mappa mBatteria(g);
    Rover rBatteria(1, 1, 1, 4); // solo 4 di batteria
    Programma pBatteria;
    pBatteria.aggiungi(Avanza(3));  // costa 3 -> OK (resta 1)
    pBatteria.aggiungi(Raccogli()); // costa 3 -> NON BASTA -> DEVE FERMARSI QUI

    bool esitoBatteria = pBatteria.esegui(rBatteria, mBatteria, false);
    cout << "Esito (atteso 0/false): " << esitoBatteria << endl;
    cout << "Campioni raccolti (attesi 0): " << rBatteria.getCampioni() << endl; 
    cout << "Batteria residua (attesa 1): " << rBatteria.getBatteria() << endl;

    return 0;
}