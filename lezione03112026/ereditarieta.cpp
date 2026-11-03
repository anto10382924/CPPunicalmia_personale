#include <iostream>
#include <string>
using namespace std;

class Persona{
    protected:  //serve per dare la possibilità alle classi derivate di accedere direttamente agli attributi privati della classe padre (Persona), rimangono PRIVATE PER IL RESTO DEL FILE!
        string nome;
    private:
        string cognome;
    public:
        Persona():nome(" "){}
        Persona(const string& s):nome(s){}  //non ha senso fare un altro costruttore per copia, farebbe la stessa cosa
        const string& getNome() const{return nome;}
        void setNome(const string& n){nome = n;}
        const string& getCognome() const{return cognome;}
        void stampa(){cout << cognome;}
        int eta;    //per esempio qui se l'ereditarietà con studente fosse protected questo attributo diventerà protected al suo interno (perché qui era public ovv).
};

class Studente:public /*private (prende TUTTA la classe padre ma come private, quindi non puoi usare nulla della classe padre fuori dallo scope della classe stessa) o protected (tutto quello che era public diventa protected, private e protected rimangono tali)*/ Persona{  //"la classe studente deve essere ridefinita partendo dalla classe persona utilizzando l'ereditarietà PUBBLICA"
    private:
        int matricola;  //volendo si possono inizializzare gli attributi se sei gay
    public:
        //tipicamente i costruttori NON si ereditano, quindi per usare quelli della classe padre scriviamo:
        using Persona::Persona; //in questo caso meglio di no avendo, la classe Studente, altri attributi in + rispetto al padre.
        Studente(const string& n, int m):Persona(n),matricola(m){   //proviamo a creare noi il costruttore di studente
            /*nome = n;  nome sta in protected quindi nel nostro caso OK
            matricola = m; */
        }
        Studente(const string& n):Persona(n),matricola(0){}
        Studente(Persona base):Persona(base){}  //costruttore di conversione, converte una Persona in uno Studente
        int getMatricola() const{return matricola;}
        void setMatricola(int m){matricola=m;}
        void stampa(){
            Persona::stampa();  //si scrive così per richiamare un metodo della classe padre
            cout << matricola;
            //cout << nome;  ok perché è protected (in ereditarietà pubblica)
            //cout << getCognome();   così perché è private (in ereditarietà pubblica)
        }
};

int main(){
    Studente S; //funziona grazie al costruttore di default (se non mettiamo using nel ublic di Studente)
    S.getNome();    //idem a sopra, eredita il metodo public da Persona (dato che in Studente non è definito) e quindi compila.
    //questa cosa vale per tutti i metodi pubblici di persona su studente, sono CONDIVISI
    S.stampa(); //qui richiama il metodo di studente, non di persona (il metodo uguale sul padre viene "oscurato")
    S.Persona::stampa();    //con questo operatore specifichiamo da quale classe chiamare il metodo
    return 0;
}