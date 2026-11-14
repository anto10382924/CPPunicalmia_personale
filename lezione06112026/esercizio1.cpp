#include <iostream>
#include <vector>
using namespace std;

//POLIMORFISMO = BINDING DINAMICO FRA LA CLASSE PRINCIPALE E LE FIGLIE.

class Notifica {
    protected:
        string destinatario;
        string testo;
    public:
        Notifica(string destinatario, string testo):destinatario(destinatario),testo(testo){}
        virtual ~Notifica() {}
        virtual void invia() const = 0;
        virtual double costo() const {return 0;}
};

class Email: public Notifica{
    public:
        using Notifica::Notifica;
        void invia() const override{
            cout << "[EMAIL a <" << destinatario << ">] " << testo << endl;
        }
};

class SMS:public Notifica{
    public:
        using Notifica::Notifica;
        void invia() const override{
            cout << "[SMS a <" << destinatario << ">] " << testo << endl;
        }
        double costo() const override {
            return 0.10;
        }
};

class Push:public Notifica{
    public:
        using Notifica::Notifica;
        void invia() const override{
            cout << "[PUSH a <" << destinatario << ">] " << testo << endl;
        }
};

class CentroNotifiche{
    private:
        vector<Notifica*> v;
    public:
        ~CentroNotifiche(){
            for (Notifica* n : v)
                delete n;
        }
        void aggiungi(Notifica* n){
            v.push_back(n);
        }
        void inviaTutte() const{
            for (Notifica* n : v)
                n -> invia();
        }
        double costoTotale() const{
            double totale=0;
            for (Notifica* n : v)
                totale += n->costo();   //perchè n è un puntatore
            return totale;
        }
};

int main(){

    CentroNotifiche centro;
    centro.aggiungi(new Email("mario@email.it", "Benvenuto!"));
    centro.aggiungi(new Email("anna@email.it", "Fattura disponibile"));
    centro.aggiungi(new SMS("3331234545", "Codice OTP: 4829"));
    centro.aggiungi(new SMS("3331234568", "Codice OTP: 4828"));
    centro.aggiungi(new SMS("3331294567", "Codice OTP: 4867"));
    centro.aggiungi(new Push("user_99", "Hai un nuovo follower"));
    centro.inviaTutte();
    cout << centro.costoTotale();

    return 0;
}