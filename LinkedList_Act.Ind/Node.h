//
// Created by Carla Onate on 24/03/21.
//

#ifndef LINKEDLIST_CLASSACT_NODE_H
#define LINKEDLIST_CLASSACT_NODE_H


template <class T>
class Node{
public:
    T data;
    Node* next;
    Node(T);
    void setData(T);
    void display();
};


template<class T> Node<T>::Node(T dataInput) {
    data = dataInput;
    next = nullptr;
}

template<class T> void Node<T>::setData(T dataInput) {
    data = dataInput;
}



template<class T> void Node<T>::display() {
    std::cout << "next: " << next << "\n";
}



#endif //LINKEDLIST_CLASSACT_NODE_H
