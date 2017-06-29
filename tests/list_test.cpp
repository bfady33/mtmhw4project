//
// Created by Or on 26/06/17.
//

#include "../list.h"
#include "mtmtest.h"
#include <string>

using namespace mtm::ListExceptions;

void list_test1();
void list_test2();
void list_test3();
void list_test4();
void list_test5();

bool isNegative(int num);
bool isBigger(std::string str1, std::string str2);

int listTest() {
    RUN_TEST(list_test1);
    RUN_TEST(list_test2);
    RUN_TEST(list_test3);
    RUN_TEST(list_test4);
    RUN_TEST(list_test5);
}

void list_test1() { //test empty list insert-remove.
    List<int> list;
    ASSERT_THROWS(ListExceptions::ElementNotFound, *list.begin());
    ASSERT_EQUALS(list.end(), list.begin());
    ASSERT_THROWS(ListExceptions::ElementNotFound, list.remove(list.begin()));
    ASSERT_THROWS(ListExceptions::ElementNotFound, list.remove(list.end()));
}

void list_test2() { //test insert - remove methods.
    List<int> list;
    list.insert(int(7));
    ASSERT_EQUALS(7, *list.begin());
    ASSERT_NO_THROW(list.remove(list.begin()));
    list.insert(7);
    list.insert(3, list.begin());
    list.insert(-14);
    List<int>::Iterator iter = list.end();
    list.insert(0, --iter);
    iter = list.begin();
    list.remove(++iter);
    list.remove(list.begin());
    iter = list.begin();
    list.insert(6, ++iter);
    list.insert(-5);
    list.insert(7);
    list.remove(--list.end());
    ASSERT_EQUALS(4, list.getSize());
    iter = list.begin();
    ASSERT_THROWS(ListExceptions::ElementNotFound, list.remove(list.end()));
    ASSERT_EQUALS(0, *(iter++));
    ASSERT_EQUALS(6, *(iter++));
    ASSERT_EQUALS(-14, *(iter++));
    ASSERT_EQUALS(-5, *(iter++));
    ASSERT_THROWS(ListExceptions::ElementNotFound, *iter);
}

void list_test3() { //test ==, != operators.
    List<char> list1;
    List<char> list2;
    List<char> list3;
    List<char> list4;
    List<char> list5;
    List<char> list6;
    List<char> list7;

    List<char> list8;
    List<char> list9;

    list1.insert('a');
    list1.insert('b');
    list1.insert('c');
    list1.insert('d');

    list2.insert('a');
    list2.insert('b');
    list2.insert('c');
    list2.insert('d');

    list3.insert('A');
    list3.insert('b');
    list3.insert('c');
    list3.insert('d');

    list4.insert('a');
    list4.insert('B');
    list4.insert('c');
    list4.insert('d');

    list5.insert('a');
    list5.insert('b');
    list5.insert('c');
    list5.insert('D');

    list6.insert('a');
    list6.insert('b');
    list6.insert('c');

    list7.insert('a');
    list7.insert('b');
    list7.insert('c');
    list7.insert('d');
    list7.insert('e');

    ASSERT_EQUALS(list1, list2);
    ASSERT_NOT_EQUAL(list1, list3);
    ASSERT_NOT_EQUAL(list1, list4);
    ASSERT_NOT_EQUAL(list1, list5);
    ASSERT_NOT_EQUAL(list1, list6);
    ASSERT_EQUALS(list8, list9);
}

void list_test4() { //test find.
    List<int> list1;
    List<int> list2;
    List<int> list3;
    List<int> list4;
    List<int> list5;
    List<int> list6;

    list2.insert(20);
    list2.insert(7);

    list3.insert(-1);
    list3.insert(5);

    list4.insert(5);
    list4.insert(-7);

    list5.insert(-20);

    list6.insert(5);
    list6.insert(-17);
    list6.insert(7);
    list6.insert(-5);

    ASSERT_EQUALS(list1.end(), list1.find(*isNegative));
    ASSERT_EQUALS(list2.end(), list2.find(*isNegative));
    ASSERT_EQUALS(-1, *list3.find(*isNegative));
    ASSERT_EQUALS(-7, *list4.find(*isNegative));
    ASSERT_EQUALS(-20, *list5.find(*isNegative));
    ASSERT_EQUALS(-17, *list6.find(*isNegative));
}

void list_test5() {
    List<std::string> list;

    list.insert("cccc");
    list.insert("aaaa");
    list.insert("bbbb");
    list.insert("abbb");
    list.insert("abcd");
    list.insert("abbb");

    list.sort(*isBigger);

    List<std::string>::Iterator iter = list.begin();
    ASSERT_EQUALS("aaaa", *(iter++));
    ASSERT_EQUALS("abbb", *(iter++));
    ASSERT_EQUALS("abbb", *(iter++));
    ASSERT_EQUALS("abcd", *(iter++));
    ASSERT_EQUALS("bbbb", *(iter++));
    ASSERT_EQUALS("cccc", *(iter++));
}

bool isNegative(int num) {
    return num < 0;
}

bool isBigger(std::string str1, std::string str2) {
    return str1.compare(str2) < 0;
}