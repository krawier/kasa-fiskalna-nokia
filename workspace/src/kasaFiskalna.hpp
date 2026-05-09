#pragma once
#include <string>
#include <vector>
#include "koszyk.hpp"



class kasaFiskalna{
    
private:
    std::vector<Towar> rejestr;
    Koszyk aktywnyRachunek;
public:

    kasaFiskalna();
    ~kasaFiskalna();

    void dodajTowarDoRejestru(int id, const std::string& nazwa, double cena);
    void usunTowarZRejestru(int id);
    int getRozmiarRejestru();
    void dodajDoKoszyka(int id, int ilosc);
    void usunTowarZKoszyka(int id);
    std::vector<Towar> getRejestr();
    double getBalans();
    std::vector<Towar> getTowaryZKoszyka();



};