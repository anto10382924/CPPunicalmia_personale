#include <list>
#include <iostream>

using std::list;

template <typename T>
class Queue:protected list<T> //usi ereditarietà privata siccome non ti servono TUTTI i metodi di lista ma solo alcuni, quelli che usi poi all'interno della classe (alla fine usiamo protected per l'ereditarietà)
{
    public:
        using list<T>::front;     //gli sto dicendo prendi il metodo privato da lista e inseriscilo nell'interfaccio pubblica
        using list<T>::back;
        using list<T>::empty;
        using list<T>::size;
        void push(const T& x)
        {
            list<T>::push_back(x);  //usiamo questa sintassi siccome ereditiamo da template
            //oppure this -> push_back(x); va bene anche questa sintassi, basta far capire al compilatore che è template list
        }
        void pop(){list<T>::pop_front();}   //non c'è manco bisogno di implementare questi due metodi se non per il nome (all'utente non frega nulla siccome siamo nella coda quindi è ovvio che inserisci alla fine e rimuovi all'inizio)
};

template<typename T>
class PriorityQueue: public Queue<T> //eredito la classe che ereditava pretected e quindi posso usare TUTTO di list<T>
{
    public:
        void push(const T& x)
        {
            auto it=this->begin();
            while(it!=this->end() && *it >= x)   //>= per rispettare il FIFO, facciamo questa condizione per la priorità, è a questo che serve l'override
                ++it;
            this -> insert(it, x);  //inseriesce x prima di it
        }
};
int main()
{
    Queue <int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    while(!q.empty())
    {
        std::cout<<q.front()<<std::endl;
        q.pop();
    }
    PriorityQueue<int> PT;
    PT.Queue<int>::push(3);
    PT.Queue<int>::push(4);
    PT.Queue<int>::push(5);
    PT.push(3);
    return 0;
}