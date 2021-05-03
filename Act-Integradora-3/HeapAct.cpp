//
// Created by Carla Onate on 30/04/21.
//

#include "HeapAct.h"

Heap::Heap() {

    std::string line;
    std::ifstream serverFile ("../bitacoraHeap.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.

    if (serverFile.is_open()){
        while (getline (serverFile,line)){
            heapArr[size] = (new Log(line));
            size++;
        }
        serverFile.close();
    } else std::cout << "Unable to open file";

    //main calls sortIp
}


void Heap::countAttempts() {
    int filteredIndex = 0;
    int numAttempts = 1;
    int index = 0;
    std::vector<std::string> logsIp;

    while(index < size){
        while(index+1 < size && heapArr[index]->ip == heapArr[index+1]->ip){
            logsIp.push_back(heapArr[index]->getLog());
            numAttempts++;
            index++;
        }
        logsIp.push_back(heapArr[index]->getLog()); //Push last log to vector
        //Add data to Log in filtered Heap
        filteredHeap[filteredIndex] = new Log();
        filteredHeap[filteredIndex]->setAttempts(numAttempts);
        filteredHeap[filteredIndex]->setIp(heapArr[index-1]->ip);
        filteredHeap[filteredIndex]->setLogs(logsIp);

        numAttempts = 1;
        logsIp.clear(); //Clean vector with logs
        index++; //Add one to index to continue while otherwise condition is false again
        filteredIndex++;
    }

    //Main calls sort Attempts
}


void Heap::sortIp() {
    heapSortIp(heapArr, max);
    printHeap();
    countAttempts();
}


void Heap::sortAttempts() {
    heapSort(filteredHeap, sizeof(filteredHeap) / sizeof(filteredHeap[0]));
    printHeapAttempts();
}



void Heap::heapSort(Log* arr[], int heapSize) {
    // Build heap (rearrange array)
    for (int i = heapSize / 2 - 1; i >= 0; i--){
        heapify(arr, heapSize, i);
    }

    // One by one extract an element from heap
    for (int i = heapSize - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }

}



void Heap::heapSortIp(Log* arr[], int heapSize) {
    // Build heap (rearrange array)
    for (int i = heapSize / 2 - 1; i >= 0; i--){
        heapifyIp(arr, heapSize, i);
    }

    // One by one extract an element from heap
    for (int i = heapSize - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapifyIp(arr, i, 0);
    }

}


void Heap::heapify(Log* arr[], int heapSize, int ind) {
    int largest = ind; // indnitialize largest as root
    int l = 2 * ind + 1; // left = 2*i + 1
    int r = 2 * ind + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < heapSize && arr[l]->attempts > arr[largest]->attempts){
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < heapSize && arr[r]->attempts > arr[largest]->attempts){
        largest = r;
    }

    // If largest is not root
    if (largest != ind) {
        swap(arr[ind], arr[largest]);


        // Recursively heapify the affected sub-tree
        heapify(arr, heapSize, largest);
    }

}



void Heap::heapifyIp(Log* arr[], int heapSize, int ind) {
    int largest = ind; // indnitialize largest as root
    int l = 2 * ind + 1; // left = 2*i + 1
    int r = 2 * ind + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < heapSize && arr[l] > arr[largest]->ip){
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < heapSize && arr[r] > arr[largest]->ip){
        largest = r;
    }

    // If largest is not root
    if (largest != ind) {
        swap(arr[ind], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapifyIp(arr, heapSize, largest);
    }

}



void Heap::swap(Log* a, Log* b) {
    Log temp = *a;
    *a = *b;
    *b = temp;
}


void Heap::printHeap() {
    std::cout << "Heap" << "(" << size << ") : {\n";
    for(Log* el : heapArr){
        std::cout << " ip: " << el->ip << " \n";
    }
    std::cout << " } \n";
}


void Heap::printHeapAttempts() {
    std::cout << "Filtered Heap" << "(" << 735 << ") : {\n";
    for(Log* i : filteredHeap){
        std::cout << " ip: " << i->ip << "        attempts: " << i->attempts << " \n";
    }
    std::cout << " } \n";
}


void Heap::show5HigherAttempts(){
    std::cout << "Higher Attempts" << "(" << 5 << ") : {";
    for(int i = 734-5; i < 735; i++){
        std::cout << " ip: " << filteredHeap[i]->ip << "        attempts: " << filteredHeap[i]->attempts << " \n";
        for(std::string el : filteredHeap[i]->getLogs()){
            std::cout << "\t Logs for this ip: " << el << "  \n";
        }
    }
    std::cout << " } \n";
}


