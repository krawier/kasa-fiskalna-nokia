#include <iostream>
#include "kasaFiskalna.hpp"
#include <string>
#include <vector>

kasaFiskalna::kasaFiskalna() {}
kasaFiskalna::~kasaFiskalna() {}

void kasaFiskalna::dodajTowarDoRejestru(int id, const std::string& nazwa, double cena){

    Towar nowyTowar;
    nowyTowar.id = id;
    nowyTowar.nazwa = nazwa;
    nowyTowar.cena = cena;

    rejestr.push_back(nowyTowar);
    balans += nowyTowar.cena;


}

void kasaFiskalna::usunTowarZRejestru(int id){

    for(size_t i = 0; i < rejestr.size(); i++){

        Towar currentProdukt  = rejestr[i];

        if(currentProdukt.id == id){
            balans -= currentProdukt.cena;
           rejestr.erase(rejestr.begin() + i);
           break;
        }

    }

}

double kasaFiskalna::getBalans(){
    return balans;
}

int kasaFiskalna::getRozmiarRejestru() {
    return rejestr.size();
}