//
// Created by Or on 23/06/17.
//

#include "../Enigma.h"
#include "mtmtest.h"
#include "string"
#include "../Exceptions.h"

using mtm::escaperoom::Enigma;

void Etest1();
void Etest2();
void Etest3();

int EnigmaTest() {
    RUN_TEST(Etest1);
    RUN_TEST(Etest2);
    RUN_TEST(Etest3);
}

//test Enigma's constructors.
void Etest1(){
    set<string> elements1;
    elements1.insert("a tool");

    set<string> elements2;
    elements2.insert("a thing");

    Enigma enigma1("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 1 , elements1);
    ASSERT_EQUALS(mtm::escaperoom::MEDIUM_ENIGMA, enigma1.getDifficulty());
    ASSERT_EQUALS(enigma1.getName(), (string)"enigma1");


    ASSERT_THROWS(mtm::escaperoom::EnigmaIllegalSizeParamException ,
                  Enigma("enigma5", mtm::escaperoom::MEDIUM_ENIGMA, 2 , elements2));

    Enigma enigma2("", mtm::escaperoom::HARD_ENIGMA);
    ASSERT_EQUALS(enigma2.getName(), (string)"");
    Enigma copy1 = enigma1;
    ASSERT_EQUALS(copy1.getName(), (string)"enigma1");
    ASSERT_EQUALS(mtm::escaperoom::MEDIUM_ENIGMA, copy1.getDifficulty());
    Enigma copy2(enigma2);
    ASSERT_EQUALS(enigma2.getName(), (string)"");
}

//test Enigma's comparisions.
void Etest2(){
    set<string> elements1;
    elements1.insert("a tool");

    set<string> elements2;
    elements2.insert("pen");

    set<string> elements3;
    elements3.insert("paper");
    elements3.insert("phone");

    Enigma enigma1("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 1 , elements1);
    Enigma enigma2("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 1 , elements2);
    Enigma enigma3("enigma3", mtm::escaperoom::MEDIUM_ENIGMA, 2 , elements3);
    Enigma enigma4("enigma4", mtm::escaperoom::EASY_ENIGMA, 1 , elements1);
    ASSERT_TRUE(enigma1 == enigma2);
    ASSERT_FALSE(enigma1 != enigma2);
    ASSERT_FALSE(enigma1 == enigma3);
    ASSERT_TRUE(enigma4 < enigma1);
    ASSERT_FALSE(enigma1 < enigma2);
    ASSERT_TRUE(enigma1.areEqualyComplex(enigma2));
    ASSERT_FALSE(enigma1.areEqualyComplex(enigma3));
    ASSERT_FALSE(enigma1.areEqualyComplex(enigma4));
}


//test Enigma's get methods.
void Etest3(){
    set<string> elements1;
    elements1.insert("a tool");

    Enigma enigma1("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 1 , elements1);
    ASSERT_EQUALS("enigma1", enigma1.getName());
    ASSERT_EQUALS(mtm::escaperoom::MEDIUM_ENIGMA, enigma1.getDifficulty());
    enigma1.addElement("additional tool");
    enigma1.removeElement("additional tool");
    ASSERT_THROWS(mtm::escaperoom::EnigmaElementNotFoundException , enigma1.removeElement("blabla"));
}