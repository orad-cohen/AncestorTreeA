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
    CHECK(T.find("mothe") == "error");
    CHECK(T.find("motherr") == "error");
    CHECK(T.find("mothera") == "error");
    CHECK(T.find("mothere") == "error");
    CHECK(T.find("other") == "error");
    CHECK(T.find("fatherr") == "error");
    CHECK(T.find("Fatherr") == "error");
    CHECK(T.find("Father") == "error");
    CHECK(T.find("fAther") == "error");
    CHECK(T.find("fATher") == "error");
    CHECK(T.find("fATHer") == "error");
    CHECK(T.find("fATHEr") == "error");
    CHECK(T.find("moth") == "error");
    CHECK(T.find("mot") == "error");
    CHECK(T.find("mo") == "error");
    CHECK(T.find("m") == "v");
    CHECK(T.find("MOTHE") == "error");
    CHECK(T.find("MOTHER") == "error");
    CHECK(T.find("MOTHERR") == "error");
    CHECK(T.find("MOTHEr") == "error");
    CHECK(T.find("MOTHErr") == "error");
    CHECK(T.find("MOTHer") == "error");
    CHECK(T.find("MOTher") == "errorl");
    CHECK(T.find("MOther") == "errorl");
    CHECK(T.find("Mother") == "errorl");
    CHECK(T.find("mOTHER") == "errorl");
    CHECK(T.find("moTHER") == "errorl");
    CHECK(T.find("motHER") == "errorl");
    CHECK(T.find("mothER") == "errorl");
    CHECK(T.find("motheR") == "errorl");
    CHECK(T.find("motheeR") == "errorel");
    CHECK(T.find("MOTH") == "error");
    CHECK(T.find("MOT") == "error");
    CHECK(T.find("MO") == "error");
    CHECK(T.find("M") == "error");
    CHECK(T.find("A") == "errorl");
    CHECK(T.find("greatgreat-grandfather") == "errorl"); //52
    CHECK(T.find("great-great-grandfatherr") == "errorl");
    CHECK(T.find("great-great-grandfatherR") == "errorl");
    CHECK(T.find("great-great-grandfatherr") == "errorl");
    CHECK(T.find("Great-great-grandfather") == "errorl");
    CHECK(T.find("great-Great-grandfather") == "errorl");
    CHECK(T.find("gReat-great-grandfather") == "errorl");
    CHECK(T.find("grEat-great-grandfather") == "errorl");
    CHECK(T.find("greAt-great-grandfather") == "errorl");
    CHECK(T.find("greaT-great-grandfather") == "errorl");
    CHECK(T.find("great-gReat-grandfather") == "errorl");
    CHECK(T.find("great-grEat-grandfather") == "errorl");
    CHECK(T.find("great-greAt-grandfather") == "errorl");
    CHECK(T.find("great-greaT-grandfather") == "errorl");
    CHECK(T.find("great-great-Grandfather") == "errorl");
    CHECK(T.find("great-great-gRandfather") == "errorl");
    CHECK(T.find("great-great-grAndfather") == "errorl");
    CHECK(T.find("great-great-graNdfather") == "errorl");
    CHECK(T.find("great-great-granDfather") == "errorl");
    CHECK(T.find("great-great-grandFather") == "errorl");
    CHECK(T.find("great-great-grandfAther") == "errorl");
    CHECK(T.find("great-great-grandfaTher") == "errorl");
    CHECK(T.find("great-great-grandfatHer") == "errorl");
    CHECK(T.find("great-great-grandfathEr") == "errorl");
    CHECK(T.find("great-great-grandfatheR") == "errorl");
    CHECK(T.find("great-grandfaTher") == "errorl");
    CHECK(T.find("Great-grandfather") == "errorl");
    CHECK(T.find("gReat-grandfather") == "errorl");
    CHECK(T.find("grEat-grandfather") == "errorl");
    CHECK(T.find("greAt-grandfather") == "errorl");
    CHECK(T.find("greaT-grandfather") == "errorl");
    CHECK(T.find("great-Grandfather") == "errorl");
    CHECK(T.find("great-gRandfather") == "errorl");
    CHECK(T.find("great-grAndfather") == "errorl");
    CHECK(T.find("great-graNdfather") == "errorl");
    CHECK(T.find("great-granDfather") == "errorl");
    CHECK(T.find("great-grandFather") == "errorl");
    CHECK(T.find("great-grandfAther") == "errorl");
    CHECK(T.find("great-grandfaTher") == "errorl");
    CHECK(T.find("great-grandfatHer") == "errorl");
    CHECK(T.find("great-grandfathEr") == "errorl");
    CHECK(T.find("great-grandfatheR") == "errorl");
    CHECK(T.find("great-grandfatherr") == "errorl");
    CHECK(T.find("greatgrandfather") == "errorl");
    CHECK(T.find("grandfatherr") == "errorl");
    CHECK(T.find("grandfatheR") == "errorl");
    CHECK(T.find("grandfathEr") == "errorl");
    CHECK(T.find("grandfatHer") == "errorl");
    CHECK(T.find("grandfaTher") == "errorl");
    CHECK(T.find("grandfAther") == "errorl");
    CHECK(T.find("grandFather") == "errorl");
    CHECK(T.find("granDfather") == "errorl");
    CHECK(T.find("graNdfather") == "errorl");
    CHECK(T.find("grAndfather") == "errorl");
    CHECK(T.find("graNdfather") == "errorl");
    CHECK(T.find("grAndfather") == "errorl");
    CHECK(T.find("gRandfather") == "errorl");
    CHECK(T.find("Grandfather") == "errorl");
    CHECK(T.find("GGrandfather") == "errorl");
    CHECK(T.find("grand-father") == "errorl");
    CHECK(T.find("greatfather") == "errorl");
    CHECK(T.find("great-father") == "errorl");
    CHECK(T.find("great-grand") == "errorl");
    CHECK(T.find("great-great") == "errorl");
    CHECK(T.find("grandmotherr") == "errorl");
}
