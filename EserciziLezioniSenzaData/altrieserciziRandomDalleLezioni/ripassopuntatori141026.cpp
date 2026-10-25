#include <iostream>
using namespace std;

void f(int* &p1, int* p2,int* &p3){     //con le & i puntatori si passano per riferimento e non per valore(copia)
    p1=p2;
    p2=p3;
    p3= new int(2);     //crea un intero nell'heap
    cout << *p1 << *p2 << *p3;
}

int main(){
    int a=5,b=6,c=7,*p=&a,*q=&b,*z=&c;
    cout << *p << *q << *z;
    f(p,q,z);
    cout << *p << *q << *z;
    delete z;       //siccome e passato per riferimento p3 cambia effettivamente z, quindi va bene.
    int A[10];
    int *p = A;     //A "punta" alla prima cella dell'array quindi va bene
    return 0;
}