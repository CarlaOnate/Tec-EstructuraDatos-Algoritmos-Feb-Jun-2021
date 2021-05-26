//
// Created by Carla Onate on 22/05/21.
//

#ifndef ACT_INTEGRADORA_4_HEAP_H
#define ACT_INTEGRADORA_4_HEAP_H

#include <iostream>
#include "GraphNode.h"

//MAX HEAP
class Heap{
private:
    GraphNode* arrPtr[13370];
    int max;
    int size;
public:
    //push, pop, top, empty, size
    Heap();
    void push(GraphNode*);
    void heapSort(GraphNode* [], int);
    void sort();

    void reorderHeap(GraphNode* [], int, int);
    void printHeap();
    void printHighestVal();
    void swap(GraphNode*, GraphNode*);
    int getParent(int);
};

#endif //ACT_INTEGRADORA_4_HEAP_H
