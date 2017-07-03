//
// Created by Fady on 6/23/2017.
//
#include <iostream>
#include "../EscapeRoomWrapper.h"
#include "mtmtest.h"

using mtm::escaperoom::EscapeRoomWrapper;

//test if the constructor are working properly
void createTest(){
    char name1[] = "room1";
    char name2[] = "room2";
    char name3[] = "room3";
    char name4[] = "room4";
    EscapeRoomWrapper e1(name1 , 50 , 8 , 4);
    EscapeRoomWrapper e2(name2 , 4);
    EscapeRoomWrapper e3(name3 , 20 , 1 , 2);
    EscapeRoomWrapper e4(name4 , 30);

    ASSERT_WITH_MESSAGE(e1.getName().compare(name1) == 0, "create test 1 failed");
    ASSERT_WITH_MESSAGE(e1.level() == 8, "create test 2 failed");
    ASSERT_WITH_MESSAGE(e2.getMaxParticipants() == 6, "create test 3 failed");
    ASSERT_WITH_MESSAGE(e2.level() == 4, "create test 4 failed");
    ASSERT_WITH_MESSAGE(e3.getMaxTime() == 20, "create test 5 failed");
    ASSERT_WITH_MESSAGE(e3.getRate() == 0, "create test 6 failed");
    ASSERT_WITH_MESSAGE(e4.getMaxTime() == 60, "create test 7 failed");
    return;
}

//func that tests the copy constructor
void copycnstTest(){
    char name1[] = "room1";
    char name2[] = "room2";
    EscapeRoomWrapper e1(name1 , 50 , 8 , 4);
    EscapeRoomWrapper e2(name2 , 4);
    EscapeRoomWrapper e3(e2);
    EscapeRoomWrapper e4(e1);

    ASSERT_WITH_MESSAGE(e4.getName().compare(name1) == 0, "copy test 1 failed");
    ASSERT_WITH_MESSAGE(e4.level() == 8, "copy test 2 failed");
    ASSERT_WITH_MESSAGE(e3.getMaxParticipants() == 6, "copy test 3 failed");
    ASSERT_WITH_MESSAGE(e3.level() == 4, "copy test 4 failed");
    ASSERT_WITH_MESSAGE(e3.getMaxTime() == 60, "copy test 5 failed");
    ASSERT_WITH_MESSAGE(e3.getRate() == 0, "copy test 6 failed");
    ASSERT_WITH_MESSAGE(e4.getMaxTime() == 50, "copy test 7 failed");
    return;
}

//func that tests the Get for each value in the room
void getValTest(){
    char name1[] = "room1";
    char name2[] = "room2";
    char name3[] = "room3";
    char name4[] = "room4";

    EscapeRoomWrapper e1(name1 , 50 , 8 , 4);
    EscapeRoomWrapper e2(name2 , 4);
    EscapeRoomWrapper e3(name3 , 20 , 1 , 2);
    EscapeRoomWrapper e4(name4 , 30);

    ASSERT_WITH_MESSAGE(e1.getName().compare(name1) == 0, "get test 1 failed");
    ASSERT_WITH_MESSAGE(e1.level() == 8, "get test 2 failed");
    ASSERT_WITH_MESSAGE(e2.getMaxParticipants() == 6, "get test 3 failed");
    ASSERT_WITH_MESSAGE(e2.level() == 4, "get test 4 failed");
    ASSERT_WITH_MESSAGE(e3.getMaxTime() == 20, "get test 5 failed");
    ASSERT_WITH_MESSAGE(e3.getRate() == 0, "get test 6 failed");
    ASSERT_WITH_MESSAGE(e4.getMaxTime() == 60, "get test 7 failed");
}

//func that tests if the rate function works properly
void rateTest(){
    char name1[] = "room1";
    char name2[] = "room2";
    char name3[] = "room3";
    char name4[] = "room4";
    EscapeRoomWrapper e1(name1 , 50 , 8 , 4);
    EscapeRoomWrapper e2(name2 , 4);
    EscapeRoomWrapper e3(name3 , 20 , 1 , 2);
    EscapeRoomWrapper e4(name4 , 30);

    ASSERT_WITH_MESSAGE(e1.getRate() == 0, "rate test 1 failed");
    ASSERT_WITH_MESSAGE(e2.getRate() == 0, "rate test 2 failed");
    e1.rate(5);
    e1.rate(3);
    e2.rate(3);

    ASSERT_WITH_MESSAGE(e2.getRate() == 3, "rate test 3 failed");
    ASSERT_WITH_MESSAGE(e1.getRate() == 4, "rate test 4 failed");
}

//func that tests if the operators work properly
void operatorstest(){
    char name1[] = "room1";
    char name2[] = "room2";
    char name3[] = "room3";
    char name4[] = "room4";
    EscapeRoomWrapper e1(name1 , 50 , 8 , 4);
    EscapeRoomWrapper e2(name2 , 4);
    EscapeRoomWrapper e3(name3 , 20 , 1 , 2);
    EscapeRoomWrapper e4(name4 , 3);

    ASSERT_WITH_MESSAGE(e1 == e1 , "operator test 1 failed");
    ASSERT_WITH_MESSAGE(e1 > e2, "operator test 2 failed");
    ASSERT_WITH_MESSAGE((e2 = e1) == e1, "operator test 3 failed");
    std::cout << "operator test 4 ... print operator test:";
    std::cout << e1 << std::endl;
    ASSERT_WITH_MESSAGE(e3 < e4, "operator test 5 failed");
}

int escapeRoomWrapperTest(){
    std::cout << "EscapeRoomWrapperTest: running create test :" << std::endl;
    createTest();
    std::cout << "EscapeRoomWrapperTest: finished create test successfully" << std::endl;
    std::cout << "EscapeRoomWrapperTest: running copy test :" << std::endl;
    copycnstTest();
    std::cout << "EscapeRoomWrapperTest: finished copy test successfully" << std::endl;
    std::cout << "EscapeRoomWrapperTest: running get test :" << std::endl;
    getValTest();
    std::cout << "EscapeRoomWrapperTest: finished get test successfully" << std::endl;
    std::cout << "EscapeRoomWrapperTest: running rate test :" << std::endl;
    rateTest();
    std::cout << "EscapeRoomWrapperTest: finished rate test successfully" << std::endl;
    std::cout << "EscapeRoomWrapperTest: running operators test :" << std::endl;
    operatorstest();
    std::cout << "EscapeRoomWrapperTest: finished operator test successfully" << std::endl;
    return 0;
}