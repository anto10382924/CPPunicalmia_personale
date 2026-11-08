#include "GestoreTV.hpp"

void GestoreVT::registraTemperatura(int temp){
    temperature.push_back(temp);
}

void GestoreVT::modificaTemperatura(unsigned pos, int temp){
    if(temperature.size()<=pos)
        return ;
    temperature.at(pos) = temp;
}

void GestoreVT::rimuoviTemperatura(){
    if (temperature.empty())
        return ;
    temperature.pop_back();
}

std::ostream& operator<<(std::ostream& o, const GestoreVT& t){
    for (int i : t.temperature){
        o << i << "\n";
    }   
    return o;
}