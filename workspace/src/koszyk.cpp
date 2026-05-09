#include <iostream>
#include "koszyk.hpp"

void Koszyk::dodajTowar(Towar t){
    listaZakupow.push_back(t);
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