//
// Created by Fady on 6/25/2017.
//

/*
 * TODO:    List's Copy-Constructor.
 * TODO:    List's = operator.
 * TODO:    List::sort.
 * TODO:    List::find.
 * TODO:    List_test.cpp
 */

#ifndef HW4PROJECT_LIST_H
#define HW4PROJECT_LIST_H

#include "Node.h"
#include "Exceptions.h"
#include "assert.h"

using namespace mtm;

/*~~~~~~~~~~~~~~~~~List Declaration~~~~~~~~~~~~~~~~~*/

template <class T>
class List {

    Node<T>* first;

public:

    List();
    List(const List&);
    ~List();
    //void sort(const Compare& compare);
    int getSize() const;
    bool operator==(const List<T>& list) const;
    bool operator!=(const List<T>& list) const;

    class Iterator;
    Iterator begin() const;
    Iterator end() const;
    void insert(const T& data, Iterator iterator = end());
    void remove(Iterator iterator);
    //Iterator find(const Predicate& predicate) const;

};

/*~~~~~~~~~~~~~~~~~List's Iterator Declaration~~~~~~~~~~~~~~~~~*/

template <class T>
class List<T>::Iterator {

    const List<T>* list;
    Node<T>* node;

    Iterator(const List<T>* list, Node<T>* node);
    friend class List<T>;

    //return an iterator that points at the node of the list which its 'next' field is this's node.
    //should not get the first node of the list.
    Iterator previous() const;

public:

    Iterator(const Iterator& iterator) = default;
    Iterator& operator=(const Iterator&) = default;

    const T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator==(const Iterator& iterator) const;
    bool operator!=(const Iterator& iterator) const;

};

/*~~~~~~~~~~~~~~~~~List's Iterator Implementation~~~~~~~~~~~~~~~~~*/

template <class T>
List<T>::Iterator::Iterator(const List<T>* list, Node<T>* node) :
        list(list), node(node) {
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::previous() const {
    //going over each of this's list's nodes.
    for(Iterator i = this->list->begin(); i != this->list->end(); i++) {
        if(i.node->getNext() == this->node) {
            return i;
        }
    }

    //should not get here.
    assert(false);
}

template <class T>
const T& List<T>::Iterator::operator*() const {
    if(this->node == nullptr) {
        throw ListExceptions::ElementNotFound();
    }
    return this->node->getData();
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    if(node != nullptr) {
        node = node->getNext();
    }
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    (*this)++;
    return temp;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    if(this->list->first != this->node) {
        *this = this->previous();
    }
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    (*this)--;
    return temp;
}

template <class T>
bool List<T>::Iterator::operator==(const Iterator& iterator) const {
    return (this->list == iterator.list) && (this->node == iterator.node);
}

template <class T>
bool List<T>::Iterator::operator!=(const Iterator& iterator) const {
    return !((*this) == iterator);
}

/*~~~~~~~~~~~~~~~~~List Implementation~~~~~~~~~~~~~~~~~*/

template <class T>
List<T>::List() :
    first(nullptr) {
}

template <class T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(this, first);
}

template <class T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(this, nullptr);
}

template <class T>
void List<T>::insert(const T &data, List<T>::Iterator iterator) {
    if(iterator.list != this) {
        throw ListExceptions::ElementNotFound();
    }

    Node<T>* to_insert = new Node<T>(data);
    //to insert as the first node:
    if(iterator == this->begin()) {
        to_insert->setNext(this->first);
        this->first = to_insert;
    }
    else { //in order to insert in any other position:
        Node<T> *temp = iterator.node;
        (--iterator).node->setNext(to_insert);
        to_insert->setNext(temp);
    }
    return;
}

template <class T>
void List<T>::remove(Iterator iterator) {
    if(iterator.list != this) {
        throw ListExceptions::ElementNotFound();
    }
    if(iterator == this->end()) {
        throw ListExceptions::ElementNotFound();
    }
    //to remove the first node:
    if(iterator == this->begin()) {
        this->first = iterator.node->getNext();
        delete iterator.node;
    }
    else { //in order to remove any other node:
        Node<T> *temp = iterator.node;
        (--iterator).node->setNext(temp->getNext());
        delete temp;
    }
}

template <class T>
int List<T>::getSize() const {
    int count = 0;
    //going over each node in the list and counting it.
    for(Iterator i = this->begin(); i != this->end(); i++) {
        count++;
    }
    return count;
}

template <class T>
bool List<T>::operator==(const List<T> &other) const {
    Iterator other_iter = other.begin();
    //going over each node in both list.
    for(Iterator this_iter = this->begin(); this_iter != this->end(); this_iter++, other_iter++) {

        //checking that current node is not the last one of the given list.
        if(other_iter == other.end()) {
            return false;
        }

        //checking if the data in the nodes equal.
        if(*this_iter != *other_iter) {
            return false;
        }
    }

    //check the the given list reached its end too.
    if(other_iter != other.end()) {
        return false;
    }
    return true;
}

template <class T>
bool List<T>::operator!=(const List<T> &list) const {
    return !((*this) == list);
}

template <class T>
List<T>::~List() {
    //deleting every node in this except for first.
    for(Iterator i = this->end(); i != this->begin(); i--) {
        delete (--i).node->getNext();
    }
    //in the case of an empty list, doesn't delete anything.
    if(this->first != nullptr) {
        delete this->first;
    }
}

#endif //HW4PROJECT_LIST_H
