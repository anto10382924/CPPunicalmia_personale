#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    list <string> l = {"Anna","Luca","Giovanni","Paola"};
    l.push_front("Anto");
    l.push_back("Coglione");    //non funonzia bene boh
    l.remove("Luca");
    l.sort();   //li sorta in ordine alfanumerico seguendo ASCII credo
    for (auto i : l)
        cout << i << " ";
    return 0;
}