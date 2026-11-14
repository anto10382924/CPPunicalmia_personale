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
            if (direzione==3)
                return 0;
        }
        int dy() const{
            if (direzione == 0)
                return 0;
            if (direzione == 1)
                return  +1;
            if (direzione == 2)
                return  0;
            if (direzione==3)
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
            if (direzione == 3)
                return '<';
        }
};

class Comando{
    public:
        virtual ~Comando() {}
        virtual bool esegui(Rover& r, Mappa& m) const = 0;
        virtual string descrizione() const = 0;
        virtual int costo() const { return 1; }
};

class Avanza:public Comando{
    private:
        int passi;
    public:
        bool esegui(Rover& r, Mappa& m) const override{
            int rx = r.getX();
            int ry = r.getY();
            if(r.simbolo() == '^'){
                if ((rx-passi)<0)
                    return false;
                //if (m.griglia[rx][ry])
            }
            return true;
        }
        string descrizione() const override{
            return "muove il rover di passi celle; non si muove e restituisce false se sul percorso c'è una roccia \n";
        }
        int costo() const override{
            return -(passi);
        }
};

class Ruota:public Comando{
    private:
        bool destra;
    public:

};

class Raccogli:public Comando{
    public:

};