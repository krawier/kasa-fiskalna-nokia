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
    double aktywnaZnizkaProcentowa = 0.0;

public:
    void dodajTowar(Towar t);
    void usunZKoszyka(int id);
    void wyczysc();
    double getBalans();
    std::vector<Towar> getTowary();

    double getAktywnaZnizka();

    void ustawZnizke(double procent);
};