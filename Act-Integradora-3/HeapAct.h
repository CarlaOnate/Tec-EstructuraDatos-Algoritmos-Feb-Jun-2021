//
// Created by Carla Onate on 30/04/21.
//

#ifndef ACT_INTEGRADORA_3_HEAP_H
#define ACT_INTEGRADORA_3_HEAP_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "LogAct.h"

class Heap{
private:
    Log* filteredHeap[735];   //Heap with attempt as priority. Review: Se hizo un vector primero para ver el length que tendría este array
    int max = 16807;
    Log* heapArr[16807];  //Heap with ip as priority
    long size = 0;
    void heapSort(Log* arr[], int);
    void heapSortIp(Log* [], int);
    void heapify(Log* arr[], int, int);
    void heapifyIp(Log* [], int, int);
    void countAttempts();
    void swap(Log*, Log*);

public:
    Heap();
    void sortIp();
    void sortAttempts();
    void printHeap();
    void printHeapAttempts();
    void show5HigherAttempts();

};

#endif //ACT_INTEGRADORA_3_HEAP_H
