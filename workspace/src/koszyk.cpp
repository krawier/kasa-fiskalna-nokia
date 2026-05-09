#include <iostream>
#include "koszyk.hpp"

void Koszyk::dodajTowar(Towar t){
    listaZakupow.push_back(t);
}

void Koszyk::usunZKoszyka(int id){
    for(size_t i = 0; i < listaZakupow.size(); i++){
        if(listaZakupow[i].id == id){
            listaZakupow.erase(listaZakupow.begin() + i);
            break;
        }
    }
}

void Koszyk::wyczysc(){
    listaZakupow.clear();
}

double Koszyk::getBalans(){
    double suma = 0;
    for(size_t i = 0; i < listaZakupow.size(); i++){
        suma += listaZakupow[i].cena;
    }
    return suma;
}

std::vector<Towar> Koszyk::getTowary(){
    return listaZakupow;
}