#include <gtest/gtest.h>
#include "kasaFiskalna.hpp"

TEST(KasaFiskalnaTest, ShouldAddProductToRegistry) {
    // arrange - tworzymy instancję naszej kasy
    kasaFiskalna kasa; 

    // act  - próbujemy dodać towar. Zgodnie z wymaganiami podajemy id, nazwę i cenę.
    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);

    // assert  - sprawdzamy, czy w rejestrze znajduje się teraz 1 towar
    EXPECT_EQ(kasa.getRozmiarRejestru(), 1);
}

TEST(KasaFiskalnaTest, ShouldDeleteProductFromRegistry) {
    kasaFiskalna kasa; 

    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);
    kasa.usunTowarZRejestru(1);
    EXPECT_EQ(kasa.getRozmiarRejestru(), 0);
}
TEST(KasaFiskalnaTest, ShouldDeleteProductFromRegistryMultiple) {
    kasaFiskalna kasa; 

    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);
    kasa.dodajTowarDoRejestru(2, "Chleb", 5.50);
    kasa.dodajTowarDoRejestru(3, "Chleb", 5.50);
    kasa.usunTowarZRejestru(1);
    kasa.usunTowarZRejestru(2);
    EXPECT_EQ(kasa.getRozmiarRejestru(), 1);
}

TEST(KasaFiskalnaTest, ShouldKeepBalanceOfActiveBasketProducts) {
    kasaFiskalna kasa; 

    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);
    kasa.dodajTowarDoRejestru(2, "Masło", 0.90);
    kasa.dodajTowarDoRejestru(3, "Ser", 8.60);

    kasa.dodajDoKoszyka(1, 2);
    kasa.dodajDoKoszyka(2,1);
    kasa.dodajDoKoszyka(3,1);


    EXPECT_EQ(kasa.getBalans(), 20.50);
}

TEST(KasaFiskalnaTest, ShouldRemoveItmeseInActiveBasketProducts) {
    kasaFiskalna kasa; 

    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);
    kasa.dodajTowarDoRejestru(2, "Masło", 0.90);
    kasa.dodajTowarDoRejestru(3, "Ser", 8.60);

    kasa.dodajDoKoszyka(1, 2);
    kasa.dodajDoKoszyka(2,1);
    kasa.dodajDoKoszyka(3,1);

    kasa.usunTowarZKoszyka(1);

    EXPECT_EQ(kasa.getBalans(), 15.00);
}

TEST(KasaFiskalnaTest, ShouldReturnListOfProductsInBasket) {
    kasaFiskalna kasa; 
    
    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);
    kasa.dodajTowarDoRejestru(2, "Masło", 6.00);

    kasa.dodajDoKoszyka(1, 1); 
    kasa.dodajDoKoszyka(2, 2); 

    std::vector<Towar> lista = kasa.getTowaryZKoszyka();

    EXPECT_EQ(lista.size(), 3);
    EXPECT_EQ(lista[0].nazwa, "Chleb");
    EXPECT_EQ(lista[2].nazwa, "Masło");
}

TEST(KasaFiskalnaTest, ShouldStartNewReceiptAfterClosingCurrentOne) {
    kasaFiskalna kasa;
    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);
    kasa.dodajDoKoszyka(1, 2); 

    ASSERT_EQ(kasa.getBalans(), 11.00);

    kasa.zamknijRachunek();

    EXPECT_EQ(kasa.getBalans(), 0.0);
    EXPECT_EQ(kasa.getTowaryZKoszyka().size(), 0);
}