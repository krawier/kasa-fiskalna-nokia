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

TEST(KasaFiskalnaTest, ShouldKeepBalanceOfRegistryProducts) {
    kasaFiskalna kasa; 

    kasa.dodajTowarDoRejestru(1, "Chleb", 5.50);
    kasa.dodajTowarDoRejestru(2, "Masło", 0.90);
    kasa.dodajTowarDoRejestru(3, "Ser", 8.60);


    EXPECT_EQ(kasa.getBalans(), 15);
}