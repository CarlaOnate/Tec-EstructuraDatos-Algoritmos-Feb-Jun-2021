//
// Created by Carla Onate on 05/04/21.
//

#ifndef DOUBLELINKEDLIST_NODE_H
#define DOUBLELINKEDLIST_NODE_H

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node();
    Node(T);

};


template<class T> Node<T>::Node() {
    next = nullptr;
    prev = nullptr;
}


template<class T> Node<T>::Node(T dataInput) {
    data = dataInput;
    next = nullptr;
}


#endif //DOUBLELINKEDLIST_NODE_H
