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


}

void kasaFiskalna::usunTowarZRejestru(int id){

    for(size_t i = 0; i < rejestr.size(); i++){

        Towar currentProdukt  = rejestr[i];

        if(currentProdukt.id == id){
           rejestr.erase(rejestr.begin() + i);
           break;
        }

    }

}

double kasaFiskalna::getBalans(){
    return aktywnyRachunek.getBalans();
}

int kasaFiskalna::getRozmiarRejestru() {
    return rejestr.size();
}

std::vector<Towar> kasaFiskalna::getRejestr(){
    return rejestr;
}

void kasaFiskalna::dodajDoKoszyka(int id, int ilosc) {
    for(size_t i = 0; i < rejestr.size(); i++) {
        if(rejestr[i].id == id) {
            for(int j = 0; j < ilosc; j++) {
                aktywnyRachunek.dodajTowar(rejestr[i]);
            }
            break; 
        }
    }
}

void kasaFiskalna::usunTowarZKoszyka(int id) {
    aktywnyRachunek.usunZKoszyka(id);
}

std::vector<Towar> kasaFiskalna::getTowaryZKoszyka(){
    return aktywnyRachunek.getTowary();
}

void kasaFiskalna::zamknijRachunek() {
    aktywnyRachunek.wyczysc();
}


void kasaFiskalna::dodajPromocje(int id, std::string nazwa){

    Promocja nowaPromocja;
    nowaPromocja.id = id;
    nowaPromocja.nazwa = nazwa;
    nowaPromocja.aktywna = false;

    promocje.push_back(nowaPromocja);

}

void kasaFiskalna::aktywujPromocje(int id){

    for(size_t i = 0; i<promocje.size();i++){

        if(id==promocje[i].id){
            promocje[i].aktywna = true;
            break;
        }

    }


}

void kasaFiskalna::deaktywujPromocje(int id){

    for(size_t i = 0; i<promocje.size();i++){

        if(id==promocje[i].id){
            promocje[i].aktywna = false;
            break;
        }

    }


}

bool kasaFiskalna::czyPromocjaAktywna(int id){

    for(size_t i = 0; i<promocje.size();i++){

        if(id==promocje[i].id){
            return promocje[i].aktywna;
        }

    }

    return false;
}