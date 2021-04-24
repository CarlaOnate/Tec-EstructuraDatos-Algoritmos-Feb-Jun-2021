//
// Created by Carla Onate on 24/04/21.
//
// Base code
//https://www.geeksforgeeks.org/binary-heap/

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <iostream>

class Heap{
private:
    int* arrPtr;
    int max;
    int size;


public:
    //push, pop, top, empty, size
    Heap(int);
    void push(int);
    void pop();
    int top();
    bool empty();
    int heapSize();

    void reorderHeap(int);
    void printHeap();
    void swap(int*, int*);
    int getParent(int);

};


#endif //HEAP_HEAP_H
