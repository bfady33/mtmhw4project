//
// Created by Or on 25/06/17.
//

#ifndef HW4PROJECT_NODE_H
#define HW4PROJECT_NODE_H

template <class T>
class Node {

    T data;
    Node<T>* next;

public:

    Node(T data);
    ~Node() = default;
    T& getData();
    Node<T>* getNext();
    void setData(T data);
    void setNext(Node<T>* node);

};

template <class T>
Node<T>::Node(T data) :
    data(data) ,next(nullptr){
}

template <class T>
T& Node<T>::getData() {
    return data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node* node) {
    this->next = node;
}

#endif //HW4PROJECT_NODE_H
