#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Nodo {
    public:
        virtual ~Nodo() {}
        virtual bool valore(const vector<bool>& ingressi) const = 0;
        virtual string espressione() const = 0;
        virtual Nodo* clone() const = 0;
};

class Ingresso:public Nodo{
    private:
        int indice;
        string nome;
    public:
        Ingresso(int indice, string nome):indice(indice),nome(nome){}
        bool valore(const vector<bool>& ingressi) const override{
            return ingressi[indice];
        }
        string espressione() const override{
            return nome;
        }
        Nodo* clone() const override{
            return new Ingresso(*this);
        }
};

class PortaNot:public Nodo{
    private:
        Nodo* figlio;
    public:
        PortaNot(const Nodo& figlio):figlio(figlio.clone()){}
        ~PortaNot(){delete figlio;}
        string espressione() const override{
            return "NOT(" + figlio->espressione() + ")";
        }
        bool valore(const vector<bool>& ingressi) const override{
            return !figlio -> valore(ingressi);
        }
        Nodo* clone() const override{
            return new PortaNot(*this);
        }
        PortaNot(const PortaNot& altro) : figlio(altro.figlio->clone()) {}
        PortaNot& operator=(const PortaNot& altro) {
            if (this != &altro) {
                delete figlio;
                figlio = altro.figlio->clone();
            }
            return *this;
        }
};

class PortaBinaria:public Nodo{
    protected:
        Nodo* sx;
        Nodo* dx;
    public:
        PortaBinaria(const Nodo& sx, const Nodo& dx):sx(sx.clone()),dx(dx.clone()){}
        PortaBinaria(const PortaBinaria& other):sx(other.sx->clone()),dx(other.dx->clone()){}
        ~PortaBinaria(){
            delete sx;
            delete dx;
        }
        PortaBinaria& operator=(const PortaBinaria& other){
            if (this != &other){
                delete sx,dx;
                sx = other.sx -> clone();
                dx = other.dx -> clone();
            }
            return *this;
        }
};

class PortaAnd:public PortaBinaria{
    public:
        using PortaBinaria::PortaBinaria;
        bool valore(const vector<bool>& ingressi) const override{
            return sx -> valore(ingressi) && dx -> valore(ingressi);
        }
        string espressione() const override{
            return "(" + sx -> espressione() + " AND " + dx -> espressione() + ")";
        }
        Nodo* clone() const override{
            return new PortaAnd(*this);
        }
};  

class PortaOr:public PortaBinaria{
    public:
        using PortaBinaria::PortaBinaria;
        bool valore(const vector<bool>& ingressi) const override{
            return sx -> valore(ingressi) || dx -> valore(ingressi);
        }
        string espressione() const override{
            return "(" + sx -> espressione() + " OR " + dx -> espressione() + ")";
        }
        Nodo* clone() const override{
            return new PortaOr(*this);
        }
};

class PortaXor:public PortaBinaria{
    public:
        using PortaBinaria::PortaBinaria;
        bool valore(const vector<bool>& ingressi) const override{
            /*if (sx -> valore(ingressi) == dx -> valore(ingressi)) questa era la mia espressione ma è poco ottimizzata sicc vede i vettori più volte
                return false;
            return sx -> valore(ingressi) || dx -> valore(ingressi);*/
            return sx->valore(ingressi) != dx->valore(ingressi);
            //anche return sx->valore(ingressi) ^ dx->valore(ingressi); mi pare di aver capito
        }
        string espressione() const override{
            return "(" + sx -> espressione() + " XOR " + dx -> espressione() + ")";
        }
        Nodo* clone() const override{
            return new PortaXor(*this);
        }
};

class Circuito{
    private:
        Nodo* radice;
        int numeroIngressi;
    public:
    Circuito(const Nodo& radice, int numeroIngressi):radice(radice.clone()),numeroIngressi(numeroIngressi){}
    ~Circuito(){delete radice;}
    Circuito(const Circuito& other):radice(other.radice->clone()),numeroIngressi(other.numeroIngressi){}
    Circuito& operator=(const Circuito& other){
        if (this != &other){
            delete radice;
            radice = other.radice->clone();
            numeroIngressi = other.numeroIngressi;
        }
        return *this;
    }
    bool valuta(const vector<bool>& ingressi) const{
        return radice -> valore(ingressi);
    }
    string espressione() const{
        return radice -> espressione();
    }
    void tabellaVerita() const{
        int totRighe = pow(2,numeroIngressi);
        for (int riga = 0; riga < totRighe; ++riga) {
            vector<bool> ingressi(numeroIngressi);
            int temp = riga;
    
            // Riempio il vettore da destra a sinistra convertendo riga in binario
            for (int i = numeroIngressi - 1; i >= 0; --i) {
                ingressi[i] = (temp % 2 == 1);
                temp /= 2;
            }
    
            // Stampo gli ingressi della riga
            for (int i = 0; i < numeroIngressi; ++i) {
                cout << ingressi[i] << " ";
            }
    
            // Stampo il risultato del circuito in ultima colonna
            cout << "| " << valuta(ingressi) << endl;

            //???????????????????????????????????????????BOH.   
        }
    }
};

int main(){
    Ingresso a(0, "A"), b(1, "B"), c(2, "C");
    Circuito c1(PortaOr(PortaAnd(a, b), PortaNot(c)), 3);
    cout << c1.espressione() << endl;
    c1.tabellaVerita();
    Circuito c2 = c1;
    cout << c2.espressione() << endl;
    c2.tabellaVerita();
    Circuito somma(PortaXor(a, b), 2);
    Circuito riporto(PortaAnd(a, b), 2);
    cout << "Somma: " << somma.espressione() << endl;
    somma.tabellaVerita();
    cout << "Riporto: " << riporto.espressione() << endl;
    riporto.tabellaVerita();        

    return 0;
}