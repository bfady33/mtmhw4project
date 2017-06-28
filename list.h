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
public:

    List();
    //List(const List&);
    ~List();
    //List operator=(const List& list);
    int getSize() const;
    bool operator==(const List<T>& list) const;
    bool operator!=(const List<T>& list) const;

    class Iterator;

    Iterator begin() const;
    Iterator end() const;

    void insert(const T& data, Iterator iterator);
    void insert(const T& data);
    void remove(Iterator iterator);

    template <class Predicate>
    List<T>::Iterator find(const Predicate& predicate) const;

    template <class Compare>
    void sort(const Compare& compare);

private:

    Node<T>* first;

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

    void swap(Iterator &it);
    //swap the data held by the iterators.
    //friend void swap(List<T>::Iterator &i, List<T>::Iterator &j);

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
void List<T>::insert(const T &data, Iterator iterator) {
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
void List<T>::insert(const T& data){
    this->insert(data , this->end());
}

template <class T>
void List<T>::remove(Iterator iterator) {
    if(iterator.list != this) {
        ListExceptions::ElementNotFound exc;
        throw exc;
    }
    if(iterator == this->end()) {
        ListExceptions::ElementNotFound exc;
        throw exc;
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
    for(Iterator i = this->begin(); i != this->end(); ) {
        delete (i++).node;
    }
}

template <class T>
template <class Predicate>
typename List<T>::Iterator List<T>::find(const Predicate& predicate) const {
    for(List<T>::Iterator i = this->begin(); i != this->end(); i++) {
        if(predicate(*i)) {
            return i;
        }
    }
    return this->end();
}

template <class T>
template <class Compare>
void List<T>::sort(const Compare& compare) {
    //a simple bubble sort:
    for(List<T>::Iterator i = this->end(); i != begin(); i--) {
        for(List<T>::Iterator j = this->begin(); j != i.previous(); j++) {
            if(!compare(*j, j.node->getNext()->setData())) {
                i.swap(j);
            }
        }
    }
}



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


//swap the data held by the iterators.
//template <class L>
//void swap(List<L>::Iterator &i, List<L>::Iterator &j){
 //   assert(i.list == j.list);
  //  L temp = *i;
//    i.node->setData(*j);
//    j.node->setData(temp);
//}

template <class T>
void List<T>::Iterator::swap(Iterator &it){
    assert(this->list == it.list);
    T temp = *(*this);
    this->node->setData(*it);
    it.node->setData(temp);
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
    Iterator returnval = *this;
    if(node != nullptr) {
        node = node->getNext();
    }
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator--(){
    if(this->list->first != this->node) {
        *this = this->previous();
    }
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --(*this);
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



#endif //HW4PROJECT_LIST_H
