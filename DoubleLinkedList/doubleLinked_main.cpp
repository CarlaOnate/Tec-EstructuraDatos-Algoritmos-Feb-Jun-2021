//
// Created by Carla Onate on 07/04/21.
//

#include <iostream>
#include "DoubleLinkedList.h"

//Todo: Add pau menu

int main() {
    DoubleLinkedList<int> list(5);
    list.generateRandom();
    list.printDoubleLinkedList();
//    list.sort();
//    list.printDoubleLinkedList();
    list.clear();
    list.printDoubleLinkedList();

}
