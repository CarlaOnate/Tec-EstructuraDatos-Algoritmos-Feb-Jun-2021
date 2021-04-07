//
// Created by Carla Onate on 13/03/21.
//

#ifndef MAIN_CLION_SCHOOLNOTES_SORT_H
#define MAIN_CLION_SCHOOLNOTES_SORT_H

#endif //MAIN_CLION_SCHOOLNOTES_SORT_H


#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <string>
#include <chrono>



template<class T>
class Sort {
private:
    std::vector<T> array;
    int n = 10;
    int swaps = 0;
    int comparisons = 0;
    int totalTimeSort;

    int menuOption;
    int orderOption;
    int searchOption;
    int totalTimeSearch;

    int searchIndex = -1;
    T searchValue;

public:
    Sort(int, int, int, int);
    void swapSort(std::vector<T>&);
    void printArr(std::string);
    void order();
    void search();

    void selectionSort(std::vector<T>&);
    void bubbleSort(std::vector<T>&);
    void insertionSort(std::vector<T>&);

    void mergeSort(std::vector<T>&, int, int);
    void merge(std::vector<T>&, int, int, int);

    int partition(std::vector<T>&, int, int);
    void quickSort(std::vector<T>&, int, int);

    void sequentialSearch(std::vector<T>&);
    int binarySearch(std::vector<T>&, T);

};



template<class T> Sort<T>::Sort(int menuOptionInput,  int orderOptionInput, int searchOptionInput, int size) {
    menuOption = menuOptionInput;
    orderOption = orderOptionInput;
    searchOption = searchOptionInput;
    n = size;

    if(menuOption == 1){  //int
        std::cout << "int" << "\n";
        srand((unsigned) time(0));
        int randomNumber;
        for (int index = 0; index < n; index++) {
            randomNumber = (rand() % 100) + 1;
            array.push_back(randomNumber);
        }

    } else if(menuOption == 2){ //float
        std::cout << "float" << "\n";
        srand((unsigned int)time(NULL));
        float randomNumber;
        for (int index = 0; index < n; index++) {
            randomNumber = ((float)rand()/(float)(RAND_MAX)) * 30.0; //Random float from 0 to 30
            array.push_back(randomNumber);
        }

    } else if (menuOption == 3){ //char
        std::cout << "char" << "\n";
        srand((unsigned) time(0));
        //https://en.cppreference.com/w/cpp/language/ascii
        char randomChar;
        for (int index = 0; index < n; index++) {
            randomChar = 65 + rand() % (( 90 + 1 ) - 65); //min value 65, max value 90
            array.push_back(randomChar);
        }
    }

    //print array before ordering
    this->printArr("Before ");
    //Call fucntion to order depending user input
    this->order();
    if(searchOption != 0){
        this->search();
    }

}


template<class T> void Sort<T>::order(){
    //Ordering
    if(orderOption != 0){
        if (orderOption == 1){
            this->swapSort(array);
        } else if (orderOption == 2){
            this->selectionSort(array);
        } else if (orderOption == 3){
            this->bubbleSort(array);
        } else if (orderOption == 4){
            this->insertionSort(array);
        } else if (orderOption == 5){
            this->mergeSort(array, 0, int(array.size()-1));
        } else {
            this->quickSort(array, 0, int(array.size()-1));
        }
    }
}


template<class T> void Sort<T>::search(){
    //Search
    if(searchOption != 0){
        std::string selectedType = menuOption == 1 ? "int" : menuOption == 2 ? "float" : menuOption == 3 ? "char" : "string";
        std::cout << " Ingresa el valor a buscar tipo " << selectedType << "\n";
        std::cin >> searchValue;
        if (searchOption == 1){
            this->sequentialSearch(array);
        } else if (searchOption == 2){
            binarySearch(array, searchValue);
        }
    }
}



template<class T> void Sort<T>::printArr(std::string type) {
    std::cout << type << " array : {";
    for(T el: array){
        std::cout << " " << el << " ";
    }
    std::cout << " }" << "\n";

    if(type == "After"){
        std::cout << "Comparisons dvone: " << comparisons << "\n";
        if(orderOption < 5){
            std::cout << "Swaps done: " << swaps << "\n";
        }
        std::cout << "Time Sort in nanoseconds: " << totalTimeSort << "\n";
        if(searchOption != 0){
            if(searchIndex > -1){
                std::cout << "searched value index: " << searchIndex << "\n";
            } else {
                std::cout << "No se encontró ese valor" << "\n";
            }
            std::cout << "Time Search in nanoseconds: " << totalTimeSearch << "\n";
        }
    }
}


//Order algorithms

template<class T> void Sort<T>::swapSort(std::vector<T>& array) {
    auto startTime = std::chrono::high_resolution_clock::now();

    int i, j, temp;
    for (i=0; i < n-1; i++){
        for (j=i+1; j < n; j++){
            comparisons++;
            if (array[i] > array[j]) {
                swaps++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    totalTimeSort = duration.count();
}


template<class T> void Sort<T>::selectionSort(std::vector<T>& array) {
    auto startTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < array.size()-1; i++){
        int minIdx = i;
        for(int j = i+1; j < array.size(); j++){
            //Add value to sorted array
            comparisons++;
            if(array[j] < array[minIdx]){
                minIdx = j;
            }
        }
//        swap arr[i], array[minIdx];
        T temp;
        temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;
        swaps++;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    totalTimeSort = duration.count();
}


template<class T> void Sort<T>::bubbleSort(std::vector<T>& array) {
    auto startTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < array.size(); i++){
        int swap = 0;
        for(int j = 0; j < array.size()-i-1; j++){
            comparisons++;
            if(array[j] > array[j+1]){
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swaps++;
                swap = 1;
            }
        }
        if(!swap){
            break;
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    totalTimeSort = duration.count();
}


template<class T> void Sort<T>::insertionSort(std::vector<T>& array){
    auto startTime = std::chrono::high_resolution_clock::now();

    //Agarras valor de array y comparas con anterior a ver si es menor o mayor, si es menor sigues pasandolo a la izq hasta que la condicion sea falsa.
    for(int i = 1; i < array.size(); i++){
        int index = i;
        while(array[index] < array[index-1] && index > 0){
            comparisons++;
            //Swap i with left element (i-1)
            T temp = array[index-1];
            array[index-1] = array[index];
            array[index] = temp;
            swaps++;
            index--;
        }
    }


    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    totalTimeSort = duration.count();
}

template<class T> void Sort<T>::mergeSort(std::vector<T>& array, int l, int r){
us
    if(l >= r){
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(array, l, m);
    mergeSort(array, m+1, r);
    merge(array, l, m, r);

}

template<class T> void Sort<T>::merge(std::vector<T>& array, int l, int m, int r){
    int n1 = m - l + 1; //index of first sub array
    int n2 = r - m; //index of second sub array

    std::vector<T> L (n1, 0);
    std::vector<T> R (n2, 0); //Create arrays for right and left

    for (int i = 0; i < n1; ++i){
        L[i] = array[l + i];
    }
    for (int j = 0; j < n2; ++j){
        R[j] = array[m + 1 + j];
    }


    int i = 0, j = 0, k = l;   //Create index for each array, first sub, second sub and merged array

    while(i < n1 && j < n2){
        comparisons++;
        if(L[i] <= R[j]){ //Si el valor en array izq es menor se pone primero en merged array
            array[k] = L[i];
            i++;                //Se compara ahora el siguiente valor del array izq con el mismo valor del array derecho
        } else {
            array[k] = R[j];    //Sino el valor de right es menor y se pone primero en array
            j++;                // luego se compara siguiente valor de right con mismo valor de left
        }
        k++;                    //Depues de comprar se suma al index del array mergeado para poder agregar otro valor.
    }

    while (i < n1) {            //If there are no more elements to compare, copy remaining elements of Left array to merged array
        comparisons++;
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {            //Then copy elements of second array if any.
        comparisons++;
        array[k] = R[j];
        j++;
        k++;
    }
}


template<class T> int Sort<T>::partition(std::vector<T>& array, int low, int high) {
    int pivot = array[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for(int j = low; j <= high- 1; j++){
        comparisons++;
        if(array[j] <= pivot){
            i++;    // increment index of smaller element
            T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    T temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return (i + 1);
}


template<class T> void Sort<T>::quickSort(std::vector<T>& array, int low, int high){

    if (low < high){
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }

}


//Search algorithms

template<class T> void Sort<T>::sequentialSearch (std::vector<T>& array){
    auto startTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < array.size()-1; i++){
        if(array[i] == searchValue){
            searchIndex = i;
            i = searchIndex;
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    totalTimeSearch = duration.count();
}


template<class T> int Sort<T>::binarySearch(std::vector<T>& array, T key){
    auto startTime = std::chrono::high_resolution_clock::now();

    int ind = 0;
    int right = (array.size()-1);
    while(ind <= right){
        comparisons++;
        int mid = (ind+right)/2;
        if (key == array[mid]){
            return mid;
        }
        else if (key < array[mid]){
            right = mid-1;
        } else {
            ind=mid+1;
        }
    }
    return -1;

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    totalTimeSearch = duration.count();

//Review: Recursive binary function crashed when value was not on array --

//    int mid = floor((initial + final)/2);
//    if(key == array[mid]){
//        searchIndex = mid;
//        auto endTime = std::chrono::high_resolution_clock::now();
//        auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
//        totalTimeSearch = duration.count();
//        return mid;
//    } else if(key < array[mid]){
//        //Searching the lower half of the string
//        binarySearch(array, initial, mid-1, key);
//    } else if(key > array[mid]){
//        //Searching upper half of algorithm
//        binarySearch(array, mid+1, final, key);
//    } else {
//        auto endTime = std::chrono::high_resolution_clock::now();
//        auto duration = duration_cast<std::chrono::nanoseconds>(endTime - startTime);
//        totalTimeSearch = duration.count();
//        return -1;
//    }


}








//    std::cout << "El tipo de la clase es: " << typeid(T).name() << "\n";
//    const char* type = typeid(T).name();
//    std::string intName ("i");
//    std::string charName ("c");
//    std::string floatName ("f");
//    std::string stringName ("NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE");

//    if(typeid(T) == typeid(int)){
//if(menuOption == 1){
//std::cout << "int" <<  "\n";
////    //https://www.bitdegree.org/learn/random-number-generator-cpp#generating-numbers-within-different-ranges
//
//srand((unsigned) time(0));
//int randomNumber;
//for (int index = 0; index < n; index++) {
//randomNumber = (rand() % 100) + 1;
//array.push_back(randomNumber);
//}
//}
//    else if (typeid(T) == typeid(float)){
//        std::cout << "float" << "\n";
//
//        srand((unsigned int)time(NULL));
//        float randomNumber;
//        for (int index = 0; index < n; index++) {
//            randomNumber = ((float)rand()/(float)(RAND_MAX)) * 30.0; //Random float from 0 to 30
//            array.push_back(randomNumber);
//        }
//
//    } else if (typeid(T) == typeid(char)) {
//        std::cout << "char" << "\n";
//
//        srand((unsigned) time(0));
//        //https://en.cppreference.com/w/cpp/language/ascii
//        char randomChar;
//        for (int index = 0; index < n; index++) {
//            randomChar = 65 + rand() % (( 90 + 1 ) - 65); //min value 65, max value 90
////            std::cout << "randomChar " << 65 + rand() % (( 90 + 1 ) - 65) << "\n";
//            array.push_back(randomChar);
//        }
//    }
//    else if (typeid(T) == typeid(std::string)){
//        std::cout << "String" << " \n";
//        std::string randomString;
//        for(int i = 0; i < n; i++){
//            std::cout << "Ingrese el string: " ;
//            std::cin >> randomString;
//            std::cout << "\n Random: " << randomString;
//            array.push_back(randomString);
//        }
//
//    }
//    else {
//        std::cout << "Tipo invalido, solo se acepta int, float, char o string" << "\n";
//    }

