//
// Created by Carla Onate on 05/04/21.
//

#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_H

#include "Node.h"

template <class T>
class DoubleLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size = 0;

public:
    DoubleLinkedList(int);
    //Teachers replit example
    void printDoubleLinkedList();
    int getSize();

    //Class Act methods
    void generateRandom();
    void addFirst(T);
    void addLast(T);
    bool deleteData(T);
    bool deleteAt(int);
    T getData(int);
    Node<T>* updateData(T, T);
    Node<T>* updateAt(int, T);
    int findData(T);
    Node<T>* operator[](const int&);
    DoubleLinkedList<T>* operator=(const DoubleLinkedList<T>&);


    //Act Individual requirements
    //Todo: Check return types in canvas
    DoubleLinkedList<T>* clear(); //usar free();
    DoubleLinkedList<T>* sort();
    void mergeSort(Node<T>**);
    Node<T>* sortedMerge(Node<T>*, Node<T>*);
    void frontBackSplit(Node<T>*, Node<T>**, Node<T>**);
    void linkBackwards();
    void duplicate();
    void removeDuplicates();

};


template<class T> DoubleLinkedList<T>::DoubleLinkedList(int sizeInput){
    head = nullptr;
    tail = nullptr;
    size = sizeInput;
}


template<class T> int DoubleLinkedList<T>::getSize(){
    return size;
}

template<class T> void DoubleLinkedList<T>::printDoubleLinkedList() {
    if (head == NULL)
        std::cout << "Double Linked List is empty, nothing to display " << std::endl;
    else {
        Node<T> *ptr = head;
        Node<T> *last = tail;
        std::cout << std::endl;
        std::cout << "Elements in Double Linked List in forward direction are: " << std::endl;
        while (ptr != NULL) {
            std::cout << ptr->data << " ";
            last = ptr;
            ptr = ptr->next;
        }
        std::cout << std::endl;

        std::cout << "Elements in Double Linked List in backward direction are: " << std::endl;
        while (last != NULL) {
            std::cout << last->data << " ";
            last = last->prev;
        }
        std::cout << std::endl;
    }
}



template<class T> void DoubleLinkedList<T>::generateRandom(){ //Creates integer list by default
    int randomInt;
    srand((unsigned) time(0));
    for(int i = 0; i < size; i++){
        randomInt = (rand() % 100) + 1;
        this->addLast(randomInt);
    }
}


template<class T> void DoubleLinkedList<T>::addFirst(T value) {
    //create new Node with new value and add next to be the prevHead
    Node<T>* newValue = new Node(value);
    newValue->next = head;
    head = newValue;
}


template<class T> void DoubleLinkedList<T>::addLast(T value) {
    Node<T>* newValue = new Node(value); //Node has default next value of null
    if(head == nullptr && tail == nullptr){
        head = newValue;
        tail = newValue;
    } else {
        newValue->prev = tail;
        newValue->next = nullptr;
        tail->next = newValue;
        tail = newValue;
    }
}

template <class T> bool DoubleLinkedList<T>::deleteData(T value) {
    Node<T> *current, *erase;
    current = head;
    if(current == nullptr) return false; //Empty list
    while(current->data != value) {
        current = current->next;
    }
    if(current->next == nullptr){
        return false; //Value not found
    } else if (current == head){
        //Value is head then next el is now head and prev of new head must be nullptr
        erase = head;
        head = erase->next;
        head->prev = nullptr;
        delete(erase);
    } else if (current == tail){
        //Value is tail then prev el is now tail and next of new tail must be nullptr
        erase = tail;
        tail = erase->prev;
        tail->next = nullptr;
        delete(erase);
    }
    current->prev->next = current->next; //next of previous el must be next of erase element
    current->next->prev = current->prev; //prev of next el must be the prev of erase element
    delete(current);
    size-=1;
    return true;
}


template <class T> bool DoubleLinkedList<T>::deleteAt(int position) {
    Node<T> *current, *erase;
    current = head;
    int counter = 0;
    if(position > size){
        //Invalid position
        return false;
    }
    while(counter != position){ //Stops when current is el to erase.
        current = current->next;
        counter++;
    }
    current->prev->next = current->next; //next of previous el must be next of erase element
    current->next->prev = current->prev; //prev of next el must be the prev of erase element
    delete(current);
    size-=1;
    return true;
}



template <class T> T DoubleLinkedList<T>::getData(int position) {
    Node<T> *current = head;
    int counter;
    if(position > size|| position < 0 || head == nullptr){
        throw std::out_of_range("Posición no valida");
    }
    if(position == 0){
        return current->data;
    }
    while(counter < position && current->next != nullptr){
        //Stops when it reaches position - when counter < position the current becomes the next el so now current is the el in the position given.
        current = current->next;
        counter++;
    }
    return current->data;
}


template <class T> Node<T>* DoubleLinkedList<T>::updateData(T searchVal, T newVal) {
    //Todo: Check if needs changes but don't think so
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


template <class T> Node<T>* DoubleLinkedList<T>::updateAt(int position, T value) {
    Node<T> *current = head;
    int counter = 0;
    if(position > size || position < 0 || head == nullptr){
        throw std::out_of_range("Posición no valida");
    }
    while(counter < position){
        current = current->next; //current will be el before position outside while
        counter++;
    }
    current->data = value;
    return current;

}


template <class T> int DoubleLinkedList<T>::findData(T value) {
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



template <class T> Node<T>* DoubleLinkedList<T>::operator[](const int& position){
    Node<T> *current = head;
    int counter;
    if(position > size || position < 0 || head == nullptr){
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


template <class T> DoubleLinkedList<T>* DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& list){
/* Codigo final de Pau

    Node<T> *tempL;
    Node<T> *temp = list.m_head;
    int updateN = 0;
    if(temp == NULL){
           m_head = NULL;
           return this;
    }
    m_head = temp;
    tempL = m_head;
    while(temp != NULL){
        temp = temp->next;
        tempL = temp;
        updateN++;
    }
     m_num_nodes = updateN;
    return this;

 */

    Node<T>* currentList;
    Node<T>* currentInput = list.head;
    int updateSize = 0;
    if(currentInput == nullptr){ //list is empty return list empty
        head = nullptr;
        return this;
    }
    head = currentInput;
    currentList = head;
    while(currentInput != nullptr){
        currentInput = currentInput->next;
        currentList = currentInput;
        updateSize++;
    }
    size = updateSize;
    return this;
}

template <class T> DoubleLinkedList<T>* DoubleLinkedList<T>::clear() {
    Node<T>* current = head;
    Node<T>* next;
    while(current != nullptr){
        next = current->next;
        free(current);
        current = next;
    }
    free(current);
    head = nullptr;
    tail = nullptr;
    return this;
}


template <class T> DoubleLinkedList<T>* DoubleLinkedList<T>::sort() {
    this->mergeSort(&head);
    this->linkBackwards();
    return this;
}


template <class T> void DoubleLinkedList<T>::mergeSort(Node<T>** headRef){
    Node<T>* headMerge = *headRef;
    Node<T>* a;
    Node<T>* b;

    /* Base case -- length 0 or 1 */
    if ((headMerge == nullptr) || (headMerge->next == nullptr)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    frontBackSplit(headMerge, &a, &b);

    /* Recursively sort the sublists */
    mergeSort(&a);
    mergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = sortedMerge(a, b);
}


template <class T> Node<T>* DoubleLinkedList<T>::sortedMerge(Node<T>* a, Node<T>* b){
    Node<T>* result = nullptr;

    /* Base cases */
    if (a == nullptr)
        return (b);
    else if (b == nullptr)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return (result);
}


template <class T> void DoubleLinkedList<T>::frontBackSplit(Node<T>* source, Node<T>** frontRef, Node<T>** backRef){
    Node<T>* fast;
    Node<T>* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}


template <class T> void DoubleLinkedList<T>::linkBackwards() {
    Node<T>* current = head;
    while(current->next != nullptr){
        current->next->prev = current;
        current->next;
    }
}

//Todo: Add part from Pau - duplicate and deleteDuplicates.







#endif //DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
