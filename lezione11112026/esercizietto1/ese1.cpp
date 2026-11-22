#include <iostream>
#include <utility>

class Array {
private:
    int* punt;
    int d;
public:
    // 1. Costruttore normale (fa anche da default se dim = 0)
    explicit Array(int dim = 0) {
        d = dim;
        if (d > 0) {
            punt = new int[d];
        } else {
            punt = nullptr;
        }
        std::cout << "Costruttore\n";
    }

    // 2. Distruttore (Regola del 5 - parte 1)
    ~Array() {
        delete[] punt;
        std::cout << "Distruttore\n";
    }

    // 3. Costruttore di copia (Regola del 5 - parte 2)
    Array(const Array& other) {
        d = other.d;
        if (d > 0) {
            punt = new int[d];
            for (int i = 0; i < d; ++i) {
                punt[i] = other.punt[i];
            }
        } else {
            punt = nullptr;
        }
        std::cout << "Costruttore di copia\n";
    }

    // 4. Assegnazione per copia (Regola del 5 - parte 3)
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] punt;
            d = other.d;
            if (d > 0) {
                punt = new int[d];
                for (int i = 0; i < d; ++i) {
                    punt[i] = other.punt[i];
                }
            } else {
                punt = nullptr;
            }
        }
        std::cout << "Assegnazione per copia\n";
        return *this;
    }

    // 5. Costruttore di spostamento (Regola del 5 - parte 4)
    Array(Array&& other) noexcept {
        punt = other.punt;
        d = other.d;
        other.punt = nullptr;   //grazie a queste istruzioni qui diventa un contenitore vuoto, no grazie a move()
        other.d = 0;
        std::cout << "Costruttore di spostamento\n";
    }

    // 6. Assegnazione per spostamento (Regola del 5 - parte 5)
    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] punt;
            punt = other.punt;
            d = other.d;
            other.punt = nullptr;
            other.d = 0;
        }
        std::cout << "Assegnazione per spostamento\n";
        return *this;
    }
};

Array creaArray(size_t n){
    Array tmp(n);
    return tmp;
}

void stampa(int& x){
    std::cout << x << std::endl;
}

void stampa(int&& x){
    std::cout << x << std::endl;
}

int main(){
    int a=1;
    int b=2;
    stampa(a);  //lvalue 1
    stampa(5);  //rvalue 5
    stampa(a + b);  //rvalue 3
    stampa(std::move(a));   //rvalue (per via del cast) 1
    Array x;    //costruttore
    Array y=x;  //costruttore di copia
    Array z=std::move(x);   //costruttore di spostamento
    Array d;    //costruttore
    d = Array(2);   //prima costruttore per array(2), poi assegnatore di spostamento e infine array(2) muore e chiama distruttore
    Array e = creaArray(4);  //prima costruttore su tmp, poi costruttore per spostamento su e, infine distruttore per tmp
    //anche avendo impostato c++11 a quanto pare stampa solo costruttore su e, distruttore su tmp... OK!
    return 0;
}