#include <iostream>
#include "DoubleLinkedList.h"

//Todo: Missing menu

int main() {
    DoubleLinkedList<int> list(5);
    list.generateRandom();
    list.printDoubleLinkedList();
    list.duplicate();
    list.printDoubleLinkedList();
    list.removeDuplicates();
    list.printDoubleLinkedList();

}
