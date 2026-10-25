#include <iostream>
using namespace std;

int main(){
    int n, card_fam, card_max=0, valprec,count=0;
    cout << "Inserisci quanti numeri vuoi, terminati con -1, usa 0 se vuoi cambiare famiglia di numeri \n";
    while (n!=-1){
        cin >> n;
        ++count;
        if (n==0){
            card_fam++;
            --count;
            if (count>card_max){
                card_max=count;
            }
            count = 0;
        }
    }
    cout << "il numero di famiglie: " << card_fam << " count famiglia più alta: " << card_max << endl;

    return 0;
}