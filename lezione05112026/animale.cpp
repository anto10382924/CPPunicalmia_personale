#include <iostream>
#include <string>
using namespace std;

class Animale{
    private:
        string nome;
    public:
        Animale(const string& n):nome(n){}
        virtual void faiIlverso() const{cout << "non so che verso faccio \n";}
        virtual string getTipo()const{return "animale";}    //virtual serve a eliminare il binding statico!!!
        virtual ~Animale(){cout << "distruttore di animale \n";}    //si elimina il binding statico anche sui distruttori SEMPRE
};

class Cane:public Animale{
    public:
        Cane(const string& n):Animale(n){}
        void faiIlverso() const override{cout << "bau bau \n";} //override serve a far controllare al compilatore se la funzione è effettivamente un overraid di quella del padre
        string getTipo()const{return "cane";}
        ~Cane(){cout << "distruttore di cane\n";}
};

class Gatto:public Animale{
    public:
        Gatto(const string& n):Animale(n){}
        void faiIlverso() const{cout << "miao miao \n";}
        string getTipo()const{return "gatto";}
        ~Gatto(){cout << "distruttore di gatto\n";}
};

void Faiilverso(const Animale& a){   //se non si usa il riferimento ma solo la copia stamperà SOLO il metodo della classe passatagli (Animale)
    a.faiIlverso(); //funziona solo sulle classi figlie overridete perfettamente,altrimenti stampera sempre "non so che verso faccio"
}

int main(){
    Cane c{"cane"};
    Gatto g{"gatto"};
    Cane *pc=&c;
    Animale a=c;
    Animale *pa=&c;
    Animale *pac=&c;    //senza fare nulla avviene "binding statico", la funzione cambia sulla base del tipo del puntatore (richiamerà prima i metodi di Animale qui)
    Animale *pag=&g;
    Animale *p=new Cane("cane");    //si può fare
    delete p;
    //c=a; NO perché non puoi assegnare un figlio ad un padre
    pc -> faiIlverso(); //???
    //pc = &a;  di default NO
    //pc = pa;  idem qui NO
    cout << (*pag).getTipo() << endl;
    return 0;
}