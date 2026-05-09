#pragma once
#include <string>
#include <vector>

struct Towar {
    int id;
    std::string nazwa;
    double cena;
};

class Koszyk {
private:
    std::vector<Towar> listaZakupow;
public:
    void dodajTowar(Towar t);
    void usunZKoszyka(int id);
    void wyczysc();
    double getBalans();
};