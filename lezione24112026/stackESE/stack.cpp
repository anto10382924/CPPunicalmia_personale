#include <vector>
#include <iostream>
#include <cassert>

using std::vector;
//lo stack funziona come FIFO - first input first output
template <typename T>
class Stack     //questa classe potrebbe anche ereditare da vector per ridefinire le sue funzioni
{
    private:
        vector<T> S;
    public:
        void push(const T& x){S.push_back(x);}
        void pop()
        {
            assert (!S.empty());    //se empty è false esce
            S.pop_back();
        }
        T& top()
        {
            assert (!S.empty());
            return S.back();    //restituisce un riferimento (all'ultimo elemento di S) può anche essere direttamente modificato vb
        }
        bool empty(){return S.empty();}
        unsigned size(){return S.size();}
};

int main()
{
    Stack <int> st;
    st.push(3);
    st.push(5);
    st.push(7);
    while(!st.empty())
    {
        std::cout<<st.top()<<std::endl;
        st.pop();
    }

    return 0;
}