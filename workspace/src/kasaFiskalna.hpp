#pragma once
#include <string>
#include <vector>
#include "koszyk.hpp"


struct Promocja {
    int id;
    std::string nazwa;
    bool aktywna;
    std::vector<Towar> objeteProdukty;

};

class kasaFiskalna{
    
private:
    std::vector<Towar> rejestr;
    Koszyk aktywnyRachunek;
    std::vector<Promocja> promocje; 
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
    void zamknijRachunek();


    void dodajPromocje(int id, std::string nazwa);
    void aktywujPromocje(int id);
    void deaktywujPromocje(int id);
    bool czyPromocjaAktywna(int id);

    bool czyTowarWPromocji(int saleID, int prodID);
    void dodajTowarDoPromocji(int saleID, int prodID);
    void usunTowarZPromocji(int saleID, int prodID);


};