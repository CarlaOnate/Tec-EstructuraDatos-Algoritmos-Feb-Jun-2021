//
// Created by Carla Onate on 24/04/21.
//

#include "heap.h"

Heap::Heap(int maxInput) {
    arrPtr = new int[maxInput];
    max = maxInput;
    size = 0;
}


void Heap::swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Heap::push(int value) {
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

    //If heap rule not followed swap el until it's fixed
    //If father el is less that new el
    //Review: Reordenamiento hacia arriba - va desde hoja hasta padre
    while(index != 0 && arrPtr[getParent(index)] < arrPtr[index]){
        swap(&arrPtr[getParent(index)], &arrPtr[index]);
        index = getParent(index);
    }
    printHeap();

}


int Heap::getParent(int index){
    return (index-1)/2;
}


void Heap::pop() {
    if(size <= 0){
        std::cout << "Heap is empty \n";
        return;
    }
    if(size == 1){
        size--;
        arrPtr = {};
        return;
    }

    arrPtr[0] = arrPtr[size-1];
    size--;
    //Reorder heap form top to bottom
    reorderHeap(0);

    printHeap();

}


void Heap::reorderHeap(int index) {
    //Parent index: (i-1)/2
    //Left child: (2*i + 1)
    //Right child: (2*i + 2)

    int parent = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    int changeIndex = index;

    if(leftChild < max && arrPtr[leftChild] > arrPtr[parent]){
        //Left child has greater priority, needs to change with parent
        changeIndex = leftChild;
    }
    if(rightChild < max && arrPtr[rightChild] > arrPtr[parent]){
        //Right child has greater priority, needs to change with parent
    }
    if(changeIndex != index){
        swap(&arrPtr[parent], &arrPtr[changeIndex]);
        reorderHeap(changeIndex);
    }

}


int Heap::top() {
    if(!empty()){
        return arrPtr[0];
    } else {
        std::cout << "Heap is empty, there is no top value\n";
    }
}


bool Heap::empty() {
    return size == 0;
}


int Heap::heapSize() {
    return size;
}


void Heap::printHeap(){
    std::cout << "Heap: {";
    for(int i = 0; i < size; i++){
        std::cout << " " << arrPtr[i] << " ";
    }
    std::cout << " }\n";
}






