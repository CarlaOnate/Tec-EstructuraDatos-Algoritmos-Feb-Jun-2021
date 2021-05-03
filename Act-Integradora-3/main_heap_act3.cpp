#include <iostream>
#include "HeapAct.h"

int main() {
    Heap heap = Heap();
    heap.sortIp();
    heap.sortAttempts();
    heap.show5HigherAttempts();
    return 0;
}
