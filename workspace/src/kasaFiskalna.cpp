#include <iostream>
#include "kasaFiskalna.hpp"
#include <string>
#include <vector>
#include <map>


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

double kasaFiskalna::getBalans() {
    std::vector<Towar> towary = aktywnyRachunek.getTowary();
    std::map<int, int> iloscSztukWKoszyku;
    double sumaBezZnizek = 0.0;

    for (size_t i = 0; i < towary.size(); i++) {
        iloscSztukWKoszyku[towary[i].id]++;
        sumaBezZnizek += towary[i].cena;
    }

    double wartoscDarmowychSztuk = 0.0;
    
    for (size_t i = 0; i < promocje.size(); i++) {
        if (promocje[i].aktywna) {
            for (size_t j = 0; j < promocje[i].objeteProdukty.size(); j++) {
                Towar produktWPromocji = promocje[i].objeteProdukty[j];
                
                int sztukiWKieszeni = iloscSztukWKoszyku[produktWPromocji.id];
                
                if (sztukiWKieszeni >= 3) {
                    int darmoweSztuki = sztukiWKieszeni / 3;
                    wartoscDarmowychSztuk += darmoweSztuki * produktWPromocji.cena;
                }
            }
        }
    }

    double sumaPoPromocjach = sumaBezZnizek - wartoscDarmowychSztuk;

    return sumaPoPromocjach * (1.0 - aktywnyRachunek.getAktywnaZnizka());
}

int kasaFiskalna::getRozmiarRejestru() {
    return rejestr.size();
}

std::vector<Towar> kasaFiskalna::getRejestr(){
    return rejestr;
}

void kasaFiskalna::dodajDoKoszyka(int id, int ilosc) {

    if (id == idKartyVIP) {
        aktywnyRachunek.ustawZnizke(znizkaVIP);
        return; 
    }

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

void kasaFiskalna::dodajTowarDoPromocji(int saleID, int prodID){
    Towar szukanyTowar;
    for(size_t j=0; j<rejestr.size();j++ ){
        if(prodID==rejestr[j].id){
            szukanyTowar = rejestr[j];
            break;
        }            
    }

    for(size_t i = 0; i<promocje.size(); i++){

        if(saleID==promocje[i].id){
            promocje[i].objeteProdukty.push_back(szukanyTowar);
            break;
        }
    }

}

void kasaFiskalna::usunTowarZPromocji(int saleID, int prodID) {
    
    for(size_t i = 0; i < promocje.size(); i++) {
        
        if(promocje[i].id == saleID) {
            
            for(size_t j = 0; j < promocje[i].objeteProdukty.size(); j++) {
                
                if(promocje[i].objeteProdukty[j].id == prodID) {
                    
                    promocje[i].objeteProdukty.erase(promocje[i].objeteProdukty.begin() + j);
                    
                    break; 
                }
            }
            break; 
        }
    }
}

bool kasaFiskalna::czyTowarWPromocji(int saleID, int prodID){

    for(size_t i = 0; i < promocje.size(); i++) {
        
        if(promocje[i].id == saleID) {
            
            for(size_t j = 0; j < promocje[i].objeteProdukty.size(); j++) {
                
                if(promocje[i].objeteProdukty[j].id == prodID) {
                    
                   return true;
                }
            }
            return false; 
        }
    }
    return false;
}

std::vector<Promocja> kasaFiskalna::getPromocje(){
    return promocje;
}

void kasaFiskalna::ustawKarteStalegoKlienta(int id, double znizka) {
    idKartyVIP = id;
    znizkaVIP = znizka;
}