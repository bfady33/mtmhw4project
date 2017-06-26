//
// Created by Or on 23/06/17.
//

#include "../Enigma.h"
#include "../mtmtest.h"
#include "string"
#include "../Exceptions.h"

using mtm::escaperoom::Enigma;

void test1();
void test2();
void test3();

int EnigmaTest(){
    RUN_TEST(test1);
    RUN_TEST(test2);
    RUN_TEST(test3);
}

//test Enigma's constructors.
void test1(){
    set<string> elements1;
    elements1.insert("a tool");

    set<string> elements2;
    elements1.insert("a thing");

    Enigma enigma1("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 1 , elements1);
    ASSERT_EQUALS(mtm::escaperoom::MEDIUM_ENIGMA, enigma1.getDifficulty());
    ASSERT_EQUALS(enigma1.getName(), (string)"enigma1");

    int flag = 0;
    try{
        Enigma enigma5("enigma5", mtm::escaperoom::MEDIUM_ENIGMA, 2 , elements2);
    }
    catch(const mtm::escaperoom::EnigmaIllegalSizeParamException &e){
        flag =1;
    }
    ASSERT_EQUALS(flag, 1);

    Enigma enigma2("", mtm::escaperoom::HARD_ENIGMA);
    ASSERT_EQUALS(enigma2.getName(), (string)"");
    flag =0;
    try{
        enigma2.removeElement("element");
    }
    catch (mtm::escaperoom::EnigmaNoElementsException){
        flag = 1;
    }
    ASSERT_EQUALS(flag, 1);

    Enigma copy1 = enigma1;
    ASSERT_EQUALS(copy1.getName(), (string)"enigma1");
    ASSERT_EQUALS(mtm::escaperoom::MEDIUM_ENIGMA, copy1.getDifficulty());
    Enigma copy2(enigma2);
    ASSERT_EQUALS(enigma2.getName(), (string)"");
}

//test Enigma's comparisions.
void test2(){
    set<string> elements1;
    elements1.insert("a tool");

    set<string> elements2;
    elements2.insert("pen");

    set<string> elements3;
    elements3.insert("paper");
    elements3.insert("phone");

    Enigma enigma1("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 3);
    Enigma enigma2("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 5);
    Enigma enigma3("enigma3", mtm::escaperoom::MEDIUM_ENIGMA, 3);
    Enigma enigma4("enigma4", mtm::escaperoom::EASY_ENIGMA, 3);
    ASSERT_TRUE(enigma1 == enigma2);
    ASSERT_FALSE(enigma1 != enigma2);
    ASSERT_FALSE(enigma1 == enigma3);
    ASSERT_TRUE(enigma4 < enigma1);
    ASSERT_FALSE(enigma1 < enigma2);
    ASSERT_TRUE(enigma1.areEqualyComplex(enigma3));
    ASSERT_FALSE(enigma1.areEqualyComplex(enigma2));
    ASSERT_FALSE(enigma1.areEqualyComplex(enigma4));
}


//test Enigma's get methods.
void test3(){
    Enigma enigma1("enigma1", mtm::escaperoom::MEDIUM_ENIGMA, 3);
    ASSERT_EQUALS("enigma1", enigma1.getName());
    ASSERT_EQUALS(mtm::escaperoom::MEDIUM_ENIGMA, enigma1.getDifficulty());
}