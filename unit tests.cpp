#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funkcijos_list.cpp" 
#include <list> 
#include <vector>

TEST_CASE("Tikrinama studento klase")
{
    studentas St;

    SECTION("Gaunamas egzamino balas")
    {
        St.setEgz(9);
        REQUIRE(St.getEgz() == 9);
    }

    SECTION("Gaunamas namu darbu kiekis")
    {
        vector<int> pazymiai{8, 8, 8, 8, 8};
        St.setNd(pazymiai);
        REQUIRE(St.getNd().size() == 5);
    }

    SECTION("Gaunamas studento vardas ir pavarde")
    {
        St.setVard("Katya");
        St.setPavard("Orlova");
        REQUIRE(St.getVard() == "Katya");
        REQUIRE(St.getPavard() == "Orlova");
    }
}
