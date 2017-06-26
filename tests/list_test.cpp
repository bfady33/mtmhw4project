//
// Created by Or on 26/06/17.
//

#include "../list.h"
#include "../mtmtest.h"


void test1();

int ListTest() {
    RUN_TEST(test1);
}

void test1() { //test empty list.
    List<int> list;
    ASSERT_THROWS(ListExceptions::ElementNotFound, *list.begin());
    ASSERT_EQUALS(list.end(), list.begin());
    ASSERT_THROWS(ListExceptions::ElementNotFound(), list.remove(list.begin()));
    ASSERT_THROWS(ListExceptions::ElementNotFound(), list.remove(list.end()));

}