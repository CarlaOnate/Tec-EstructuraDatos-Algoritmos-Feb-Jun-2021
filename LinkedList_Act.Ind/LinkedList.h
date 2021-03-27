//
// Created by Carla Onate on 24/03/21.
//

#ifndef LINKEDLIST_CLASSACT_LINKEDLIST_H
#define LINKEDLIST_CLASSACT_LINKEDLIST_H
#include "Node.h"
#include <vector>

//.h
template <class T>
class LinkedList{
private:
    //Review: Since Node is a template class as well Node* causes error, need to specficy type Node<T>*
    Node<T>* head;
    Node<T>* tail;
    int n = 0;

public:
    LinkedList(int);
    void generateRandom(int);
    void createLinkedList(int);
    void addFirst(T value);
    void addLast(T value);
    int findData(T value);
    bool deleteData(T value);
    bool deleteAt(T value);
    T getData(int);
    Node<T>* updateData(T, T);
    Node<T>* updateAt(int, T);
    Node<T>* operator[](const int&);
    LinkedList<T>* operator=(const LinkedList<T>&);
    void display();
};


//.cpp

template<class T> LinkedList<T>::LinkedList(int nInput){
    head = nullptr;
    tail = nullptr;
    n = nInput;
}

template<class T> void LinkedList<T>::createLinkedList(int type){
    int valueInt;
    char valueChar;
    for(int i = 0; i < n; i++){
        std::cout << "Ingresa dato " << i+1 <<  ":\n";
        if(type == 1){
            std::cin >> valueInt;
            this->addLast(valueInt);
        } else {
            std::cin >> valueChar;
            this->addLast(valueChar);
        }
    }
    this->display();
}


template<class T> void LinkedList<T>::generateRandom(int type){
    // 1 int, 2 char
    //Review: if function is called one after other the values are the same. - don't know why :(
    int randomInt;
    char randomChar;
    srand((unsigned) time(0));
    if(type == 1){
        for(int i = 0; i < n; i++){
            randomInt = (rand() % 100) + 1;
            this->addLast(randomInt);
        }
    } else {
        for(int i = 0; i < n; i++){
            randomChar = 'a' + rand()%26;;
            this->addLast(randomChar);
        }
    }
    this->display();
}


template <class T> void LinkedList<T>::addFirst(T value) {
    //create new Node with new value and add next to be the prevHead
    Node<T>* newValue = new Node(value);
    newValue->next = head;
    head = newValue;
}


template <class T> void LinkedList<T>::addLast(T value) {
    //Todo: Si tengo tail esto no se sipmlifica mas??
    Node<T>* newValue = new Node(value);
    Node<T>* current = head;
    int counter = 0;
    if(head == nullptr) {
        head = newValue;
    } else {
      while (current->next != nullptr){
          current = current->next;
          counter++;
      }
      current->next = newValue;
      tail = newValue;
    }
}

template <class T> int LinkedList<T>::findData(T value) {
    // Must return position of value - added counter to do so
    Node<T>* current = head;
    int counter = 0;
    while(current != nullptr){
        if(current->data == value){
            return counter;
        } else {
            current = current->next;
        }
        counter++;
    }
    return -1; //Value not found
}


template <class T> bool LinkedList<T>::deleteData(T value) {
    Node<T> *current, *erase;
    current = head;
    if(current == nullptr) return false; //Empty list
    if(current->data == value){
        head = current->next;
        delete(current);
        n-=1;
        return true;
    }
    while(current->next != nullptr && (current->next)->data != value) {
        //We need to stop 1 Node before erase element to link last of erase with next of erase.
        // If we stop at erase there is no way to go back and link prev element
        current = current->next;
    }
    if(current->next != nullptr){
        return false; //value not found
    }
    erase = current->next;
    current->next = erase->next; //links current node with next node after erase
    delete(erase);
    n-=1;
    return true;
}


template <class T> bool LinkedList<T>::deleteAt(T position) {
    Node<T> *current, *erase;
    current = head;
    int counter = 0;
    if(position > n){
        return false;
    }
    while(counter+1 != position){
        current = current->next;
        counter++;
    }
    erase = current->next;
    current->next = erase->next;
    delete(erase);
    n-=1;
    return true;
}


template <class T> T LinkedList<T>::getData(int position) {
    Node<T> *current = head;
    int counter;
    if(position > n || position < 0 || head == nullptr){
        throw std::out_of_range("Posición no valida");
    }
    if(position == 0){
        return current->data;
    }
    while(counter < position && current->next != nullptr){
        current = current->next;
        counter++;
    }
    return current->data;

}



template <class T> Node<T>* LinkedList<T>::updateData(T searchVal, T newVal) {
    Node<T>* current = head;
    int counter = 0;
    while(current != nullptr){
        if(current->data == searchVal){
            current->data = newVal; //Update data
            return current;
        } else {
            current = current->next;
        }
        counter++;
    }
    throw std::out_of_range("Posición no valida");
}


template <class T> Node<T>* LinkedList<T>::updateAt(int position, T value) {
    Node<T> *current = head;
    int counter = 0;
    if(position > n || position < 0 || head == nullptr){
        throw std::out_of_range("Posición no valida");
    }
    if(position == 0){
        current->data = value;
        return current;
    }
    while(counter < position){
        current = current->next; //current will be el before position outside while
        counter++;
    }
    current->data = value;
    return current;

}

//Tested - works!
template <class T> Node<T>* LinkedList<T>::operator[](const int& position){
    Node<T> *current = head;
    int counter;
    if(position > n || position < 0 || head == nullptr){
        throw std::out_of_range("Posición no valida");
    }
    if(position == 0){
        return current;
    }
    while(counter < position){
        current = current->next;
        counter++;
    }
    return current->next;
}



template <class T> LinkedList<T>* LinkedList<T>::operator=(const LinkedList<T>& list){
    Node<T>* currentList;
    Node<T>* currentInput = list.head;
    int updateN = 0;
    if(currentInput == nullptr){ //list is empty return list empty -- Todo:??
           head = nullptr;
           return this;
    }
    head = currentInput;
    currentList = head;
    while(currentInput != nullptr){
        currentInput = currentInput->next;
        currentList = currentInput;
        updateN++;
    }
    n = updateN;
    return this;
}



template <class T> void LinkedList<T>::display() {
    int counter = 0;
    Node<T>* current = head;
    while (current->next != nullptr){
        std::cout << " " << current->data << " ";
        current = current->next;
        counter++;
    }
    std::cout << " " << current->data << " ";
    n = counter;
    std::cout << "  - size " << n << "\n";
}



#endif //LINKEDLIST_CLASSACT_LINKEDLIST_H
