#pragma once
#include <string>
#include <vector>


struct Towar {

	int id;
	std::string nazwa;
	double cena;
};

class kasaFiskalna{
    
private:
    std::vector<Towar> rejestr;
public:

    kasaFiskalna();
    ~kasaFiskalna();

    void dodajTowarDoRejestru(int id, const std::string& nazwa, double cena);
    void usunTowarZRejestru(int id);
    int getRozmiarRejestru();



};