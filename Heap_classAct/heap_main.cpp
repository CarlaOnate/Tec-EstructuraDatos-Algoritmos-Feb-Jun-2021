//Carla Oñate Gardella - A01653555

#include "heap.h"

int main() {
    Heap arrHeap = Heap(10);

    arrHeap.push(10);
    arrHeap.push(15);
    arrHeap.push(24);
    arrHeap.push(76);
    arrHeap.push(4);
    arrHeap.push(5);

    arrHeap.pop();

    std::cout << "Top: " << arrHeap.top() << "\n";

    if(arrHeap.empty()){
        std::cout << "List is empty\n";
    } else {
        std::cout << "List is not empty\n";
    }

    std::cout << "Size of heap array: " << arrHeap.heapSize() << "\n";

}
