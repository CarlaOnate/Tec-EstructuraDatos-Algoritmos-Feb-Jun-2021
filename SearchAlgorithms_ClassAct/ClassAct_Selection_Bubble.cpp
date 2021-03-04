//
// Created by Carla Onate on 01/03/21.
//
#include <iostream>
#include <vector>
using namespace std;

//Todo: Poner aqui el selection sort y bubble sort correctos que haga aparte.


void swapSort(int values[], int n, int compara, int swap) {
    int i, j, temp;
    compara = 0;
    swap = 0;
    for (i=0; i < n-1; i++){
        for (j=i+1; j < n; j++){
            compara++;
            if (values[i] > values[j]) {
                swap++;
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}


vector<int> selectionSort(vector<int> array){
    //Find min value on array and place it on the first index of sorted array
    for(int i = 0; i < array.size()-1; i++){
        int minIdx = i;
        for(int j = i+1; j < array.size(); j++){
            //Add value to sorted array
            if(array[j] < array[minIdx]){
                minIdx = j;
            }
        }
//        swap arr[i], array[minIdx];
        int temp;
        temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;
    }
    return array;

}


vector<int> bubbleSort(vector<int> array){
    bool swaps;
    for(int i = 0; i < array.size(); i++){
        for(int j = i; j < array.size()-i-1; j++){
            if(array[j] > array[j+1]){
                cout << "Before " << array[j] << " > " << array[j+1] << endl;
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                swaps = true;
            }
        }
        if(!swaps){
            break;
        }
    }
}