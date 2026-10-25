#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int* ptr = &a;      //referenzazione
    *ptr += 5;      //deferenzazione
    int b = 50;
    ptr = &b;
    *ptr =+ 5;
    cout << a << " " << b << endl;

    return 0;
}