//
// Created by Carla Onate on 16/04/21.
//

#ifndef BST_ACT_NODE_H
#define BST_ACT_NODE_H

template <class T>
class Node{
public:
    T data;
    Node<T>* right;
    Node<T>* left;

    Node();
    Node(T);

};

#endif //BST_ACT_NODE_H


template <class T> Node<T>::Node(){
    right = nullptr;
    left = nullptr;
}

template <class T> Node<T>::Node(T input) {
    right = nullptr;
    left = nullptr;
    data = input;
}
