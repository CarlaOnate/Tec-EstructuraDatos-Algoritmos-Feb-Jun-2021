//
// Created by Carla Onate on 22/05/21.
//

#include "Heap.h"

Heap::Heap() {
    size = 0;
    max = 13370;
}


void Heap::swap(GraphNode* a, GraphNode* b){
    GraphNode temp = *a;
    *a = *b;
    *b = temp;
}


void Heap::push(GraphNode* value) {
    //Parent index: (i-1)/2
    //Left child: (2*i + 1)
    //Right child: (2*i + 2)

    if(size == max){
        std::cout << "\nOverflow\n";
        return;
    }

    size++;
    int index = size - 1;
    arrPtr[index] = value;


    //Review: Reordenamiento hacia arriba - va desde hoja hasta padre
    while(index != 0 && arrPtr[getParent(index)]->vecinos < arrPtr[index]->vecinos){
        swap(arrPtr[getParent(index)], arrPtr[index]);
        index = getParent(index);
    }

}


int Heap::getParent(int index){
    return (index-1)/2;
}



void Heap::reorderHeap(GraphNode* arr[], int heapSize, int ind) {

    int largest = ind; // indnitialize largest as root
    int l = 2 * ind + 1; // left = 2*i + 1
    int r = 2 * ind + 2; // right = 2*i + 2


    // If left child is larger than root
    if (l < heapSize && arr[l]->vecinos > arr[largest]->vecinos){
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < heapSize && arr[r]->vecinos > arr[largest]->vecinos){
        largest = r;
    }

    // If largest is not root
    if (largest != ind) {
        swap(arr[ind], arr[largest]);

        // Recursively heapify the affected sub-tree
        reorderHeap(arr, heapSize, largest);
    }

}



void Heap::printHeap(){
    std::cout << "Heap: {";
    for(int i = 0; i < size; i++){
        std::cout << " " << arrPtr[i]->ipOrigen << " -> " << arrPtr[i]->vecinos << "\n ";
    }
    std::cout << " }\n";
}


void Heap::sort() {
    heapSort(arrPtr, size);
}


void Heap::heapSort(GraphNode* arr[], int heapSize) {
    // Build heap (rearrange array)
    for (int i = heapSize / 2 - 1; i >= 0; i--){
        reorderHeap(arr, heapSize, i);
    }

    // One by one extract an element from heap
    for (int i = heapSize - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        reorderHeap(arr, i, 0);
    }
}


void Heap::printHighestVal(){
    int highest = arrPtr[size-1]->vecinos;
    std::cout << "Ips con mas adyacencias => \n";
    for(int i = size-5; i < size; i++){
        std::cout << "\t Ip " << arrPtr[i]->ipOrigen << ": " << arrPtr[i]->vecinos << " \n";
    }
}

