#include "gestoretemperature.hpp"

GestoreTemperature::GestoreTemperature():temperature(nullptr),dimensione(0){};

GestoreTemperature::GestoreTemperature(const int* temper, int dim):temperature(nullptr),dimensione(dim){
    setTemperature(temper,dim);
}

GestoreTemperature::GestoreTemperature(const GestoreTemperature& other):temperature(nullptr),dimensione(other.dimensione){
    setTemperature(other.temperature,other.dimensione);
}

GestoreTemperature::~GestoreTemperature(){
    delete [] temperature;
}

void GestoreTemperature::setTemperature(const int* temp, int dim){
    if (temp == nullptr || dim <= 0) {  //serve nel caso in cui temp sia un array vuoto
        delete[] temperature;
        temperature = nullptr;
        dimensione = 0;
        return;
    }
    if (this->temperature == temp){ //se sono già lo stesso array non ha senso la funzione set
        return ;
    }
    delete [] temperature;  //IMPORTANTE PORCAMADONNA
    dimensione = dim;
    temperature = new int [dimensione];
    for(unsigned i=0;i<dim;++i)
        temperature[i] = temp[i];
}

void GestoreTemperature::registraTemperatura(int temp){
    int* nuovo = new int[dimensione+1];
    for(unsigned i=0;i<dimensione;++i)
        nuovo[i] = temperature[i];
    nuovo[dimensione] = temp;
    delete [] temperature;
    temperature = nuovo;
    dimensione++;
}

void GestoreTemperature::modificaTemperatura(unsigned pos,int temp){
    if (temperature == nullptr || dimensione ==0)   
        registraTemperatura(temp);  //meglio dare un messaggio di errore in cout, il metodo è di modifica, non di aggiunta.
        return ;
    if ((unsigned)dimensione <= pos)    //unsigned cast perchè potrebbe andare in overloading confrontando unsigned/signed
        cout << "Non esiste una posizione " << pos << " modificabile!!! \n";
    else
        temperature[pos] = temp;
}

void GestoreTemperature::rimuoviTemperatura(){
    if (temperature == nullptr)
        return ;
    if (dimensione == 1){
        delete [] temperature;
        temperature = nullptr;
        dimensione = 0;
        return ;
    }
    int * nuovo = new int [dimensione-1];   //IMPORTANTISSIMO: NON va bene [dimensione--], decrementa anche la variabile stessa, non è mai solo nominale l'operatore --, come il ++.
    for(unsigned i=0;i<dimensione-1;++i)
        nuovo[i] = temperature[i];
    delete [] temperature;
    temperature = nuovo;
    dimensione --;
}

ostream& operator<<(ostream& o, const GestoreTemperature& temp){
    if (temp.temperature == nullptr){
        o << "oggetto vuoto! \n";
        return o;
    }
    for(unsigned i=0;i<temp.dimensione;++i)
        o << " " << temp.temperature[i] << "\n";
    return o;
}