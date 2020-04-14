#include "doctest.h"
#include "FamilyTree.hpp"


#include <string>
using namespace std;

TEST_CASE("Relations")
{
    family::Tree T ("Moshe"); // Moshe is the "root" of the tree (the youngest person).
	T.addFather("Moshe", "Yaakov")   // Tells the tree that the father of Moshe is Yaakov.
	 .addMother("Moshe", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
    CHECK(T.relation("Yaakov") == "father");
    CHECK(T.relation("Yaako") == "unrelated");
    CHECK(T.relation("Yaak") == "unrelated");
    CHECK(T.relation("Yaa") == "unrelated");
    CHECK(T.relation("Ya") == "unrelated");
    CHECK(T.relation("Y") == "unrelated");
    CHECK(T.relation("Yakov") == "unrelated");
    CHECK(T.relation("YAAKOV") == "unrelated");
    CHECK(T.relation("Rachel") == "mother");
    CHECK(T.relation("Rivka") == "grandmother");
    CHECK(T.relation("Avraham") == "great-grandfather");
    CHECK(T.relation("Terah") == "great-great-grandfather");
    CHECK(T.relation("abc") == "unrelated");
    CHECK(T.relation("Moshe") == "me");
    CHECK(T.relation("M") == "unrelated");
    CHECK(T.relation("Mo") == "unrelated");
    CHECK(T.relation("Mos") == "unrelated");
    CHECK(T.relation("Mosh") == "unrelated");
    CHECK(T.relation("MOSHE") == "unrelated");
    CHECK(T.relation("MOSHe") == "unrelated");
    CHECK(T.relation("MOSH3") == "unrelated");
    CHECK(T.relation("M0SHE") == "unrelated");
    CHECK(T.relation("MOShE") == "unrelated");
    CHECK(T.relation("MOsHE") == "unrelated");
    CHECK(T.relation("mOSHE") == "unrelated");
    CHECK(T.relation("moSHE") == "unrelated");
    CHECK(T.relation("mosHE") == "unrelated");
    CHECK(T.relation("moshE") == "unrelated");
    CHECK(T.relation("moshee") == "unrelated");
    CHECK(T.find("mother") == "Rachel");
    CHECK(T.find("father") == "Yaakov");
    CHECK(T.find("grandmother") == "Rivka");
    CHECK(T.find("great-grandfather") == "Avraham");
    CHECK(T.find("great-great-grandfather") == "Terah");
     T.remove("Avraham"); //Removes everyone in the tree from Avraham(included) and forward(his parents and so on).
    CHECK(T.relation("Terah") == "unrelated"); //Because we removed his son(Avraham).
     
     //The checks above throw exceptions.
    CHECK_THROWS(T.find("mothe") == "Rachel");
    CHECK_THROWS(T.find("motherr") == "Rachel");
    CHECK_THROWS(T.find("mothera") == "Rachel");
    CHECK_THROWS(T.find("mothere") == "Rachel");
    CHECK_THROWS(T.find("other") == "Rachel");
    CHECK_THROWS(T.find("fatherr") == "Rachel");
    CHECK_THROWS(T.find("Fatherr") == "Rachel");
    CHECK_THROWS(T.find("Father") == "Rachel");
    CHECK_THROWS(T.find("fAther") == "Rachel");
    CHECK_THROWS(T.find("fATher") == "Rachel");
    CHECK_THROWS(T.find("fATHer") == "Rachel");
    CHECK_THROWS(T.find("fATHEr") == "Rachel");
    CHECK_THROWS(T.find("moth") == "Rachel");
    CHECK_THROWS(T.find("mot") == "Rachel");
    CHECK_THROWS(T.find("mo") == "Rachel");
    CHECK_THROWS(T.find("m") == "v");
    CHECK_THROWS(T.find("MOTHE") == "Rachel");
    CHECK_THROWS(T.find("MOTHER") == "Rachel");
    CHECK_THROWS(T.find("MOTHERR") == "Rachel");
    CHECK_THROWS(T.find("MOTHEr") == "Rachel");
    CHECK_THROWS(T.find("MOTHErr") == "Rachel");
    CHECK_THROWS(T.find("MOTHer") == "Rachel");
    CHECK_THROWS(T.find("MOTher") == "Rachell");
    CHECK_THROWS(T.find("MOther") == "Rachell");
    CHECK_THROWS(T.find("Mother") == "Rachell");
    CHECK_THROWS(T.find("mOTHER") == "Rachell");
    CHECK_THROWS(T.find("moTHER") == "Rachell");
    CHECK_THROWS(T.find("motHER") == "Rachell");
    CHECK_THROWS(T.find("mothER") == "Rachell");
    CHECK_THROWS(T.find("motheR") == "Rachell");
    CHECK_THROWS(T.find("motheeR") == "Rachelel");
    CHECK_THROWS(T.find("MOTH") == "Rachel");
    CHECK_THROWS(T.find("MOT") == "Rachel");
    CHECK_THROWS(T.find("MO") == "Rachel");
    CHECK_THROWS(T.find("M") == "Rachel");
    CHECK_THROWS(T.find("A") == "Rachell");
    CHECK_THROWS(T.find("greatgreat-grandfather") == "Rachell"); //52
    CHECK_THROWS(T.find("great-great-grandfatherr") == "Rachell");
    CHECK_THROWS(T.find("great-great-grandfatherR") == "Rachell");
    CHECK_THROWS(T.find("great-great-grandfatherr") == "Avraham");
    CHECK_THROWS(T.find("Great-great-grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-Great-grandfather") == "Avraham");
    CHECK_THROWS(T.find("gReat-great-grandfather") == "Avraham");
    CHECK_THROWS(T.find("grEat-great-grandfather") == "Avraham");
    CHECK_THROWS(T.find("greAt-great-grandfather") == "Avraham");
    CHECK_THROWS(T.find("greaT-great-grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-gReat-grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-grEat-grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-greAt-grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-greaT-grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-great-Grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-great-gRandfather") == "Avraham");
    CHECK_THROWS(T.find("great-great-grAndfather") == "Avraham");
    CHECK_THROWS(T.find("great-great-graNdfather") == "Avraham");
    CHECK_THROWS(T.find("great-great-granDfather") == "Avraham");
    CHECK_THROWS(T.find("great-great-grandFather") == "Avraham");
    CHECK_THROWS(T.find("great-great-grandfAther") == "Avraham");
    CHECK_THROWS(T.find("great-great-grandfaTher") == "Avraham");
    CHECK_THROWS(T.find("great-great-grandfatHer") == "Avraham");
    CHECK_THROWS(T.find("great-great-grandfathEr") == "Avraham");
    CHECK_THROWS(T.find("great-great-grandfatheR") == "Avraham");
    CHECK_THROWS(T.find("great-grandfaTher") == "Avraham");
    CHECK_THROWS(T.find("Great-grandfather") == "Avraham");
    CHECK_THROWS(T.find("gReat-grandfather") == "Avraham");
    CHECK_THROWS(T.find("grEat-grandfather") == "Avraham");
    CHECK_THROWS(T.find("greAt-grandfather") == "Avraham");
    CHECK_THROWS(T.find("greaT-grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-Grandfather") == "Avraham");
    CHECK_THROWS(T.find("great-gRandfather") == "Avraham");
    CHECK_THROWS(T.find("great-grAndfather") == "Avraham");
    CHECK_THROWS(T.find("great-graNdfather") == "Avraham");
    CHECK_THROWS(T.find("great-granDfather") == "Avraham");
    CHECK_THROWS(T.find("great-grandFather") == "Avraham");
    CHECK_THROWS(T.find("great-grandfAther") == "Avraham");
    CHECK_THROWS(T.find("great-grandfaTher") == "Avraham");
    CHECK_THROWS(T.find("great-grandfatHer") == "Avraham");
    CHECK_THROWS(T.find("great-grandfathEr") == "Avraham");
    CHECK_THROWS(T.find("great-grandfatheR") == "Avraham");
    CHECK_THROWS(T.find("great-grandfatherr") == "errorl");
    CHECK_THROWS(T.find("greatgrandfather") == "errorl");
    CHECK_THROWS(T.find("grandfatherr") == "errorl");
    CHECK_THROWS(T.find("grandfatheR") == "errorl");
    CHECK_THROWS(T.find("grandfathEr") == "errorl");
    CHECK_THROWS(T.find("grandfatHer") == "errorl");
    CHECK_THROWS(T.find("grandfaTher") == "errorl");
    CHECK_THROWS(T.find("grandfAther") == "errorl");
    CHECK_THROWS(T.find("grandFather") == "errorl");
    CHECK_THROWS(T.find("granDfather") == "errorl");
    CHECK_THROWS(T.find("graNdfather") == "errorl");
    CHECK_THROWS(T.find("grAndfather") == "errorl");
    CHECK_THROWS(T.find("graNdfather") == "errorl");
    CHECK_THROWS(T.find("grAndfather") == "errorl");
    CHECK_THROWS(T.find("gRandfather") == "errorl");
    CHECK_THROWS(T.find("Grandfather") == "errorl");
    CHECK_THROWS(T.find("GGrandfather") == "errorl");
    CHECK_THROWS(T.find("grand-father") == "errorl");
    CHECK_THROWS(T.find("greatfather") == "errorl");
    CHECK_THROWS(T.find("great-father") == "errorl");
    CHECK_THROWS(T.find("great-grand") == "errorl");
    CHECK_THROWS(T.find("great-great") == "errorl");
    CHECK_THROWS(T.find("grandmotherr") == "errorl");
}
