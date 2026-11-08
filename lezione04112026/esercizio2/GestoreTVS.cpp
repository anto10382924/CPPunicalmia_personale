#include "GestoreTVS.hpp"
#include <algorithm>

void GestoreVTS::registraTemperatura(int temp){
    if (temp >= -50 && temp <= 60)
        temperature.push_back(temp);
    else
        scartate ++;
}

void GestoreVTS::modificaTemperatura(unsigned pos, int temp){
    if (temperature.size() <= pos){
        scartate ++;
        return ;
    }
    if (temp >= -50 && temp <= 60)
        temperature.at(pos) = temp;
    else
        scartate ++;
}

int GestoreVTS::massima() const{
    if (temperature.empty())
        return 0;
    return *(std::max_element(temperature.begin(),temperature.end()));
}

int GestoreVTS::minima() const{
    if (temperature.empty())
        return 0;
    return *(std::min_element(temperature.begin(),temperature.end()));
}

double GestoreVTS::media() const{
    if (temperature.empty())
        return 0.0;
    int somma=0;
    for (int n : temperature)
        somma += n;
    return static_cast<double>(somma)/temperature.size();
}

std::ostream& operator<<(std::ostream& o, const GestoreVTS& t){
    o << static_cast<const GestoreVT&>(t) << "\n";  //chiama la funzione operator<< ridefinita nella classe padre GestoreVT
    o << t.scartate << "\n";
    return o;
}