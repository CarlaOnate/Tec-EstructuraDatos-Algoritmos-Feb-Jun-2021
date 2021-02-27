//
// Created by Carla Onate on 25/02/21.
//

#include <vector>
#include <iostream>
using namespace std;

int sequentialSearch (vector<int> array, int key) {
    int index = -1;
    for(int i = 0; i < array.size(); i++) {
        cout << "Index" << i << endl;
        if (array[i] == key) {
            index = i;
            i = array.size(); //Stop for when found integer
        }
    }
    return index;
}


int orderedSequentialSearch (vector<int> array, int key) {
    int index = -1;
    for(int i = 0; i < array.size(); i++) {
        cout << "Index" << i << endl;
        if (key <= array[i]) {
            if(key == array[i]){
                index = i;
            }
        }
    }
    return index;
}


int binarySearch (vector<int> array, int initialIndex, int finalIndex, int key){
    if(finalIndex >= 1) {
        //size = 10; initial=0; final=10; middle=initial+final-1/2  0+(10-1)/2:
        //size = 10; initial=0; final=size-1=9; middle=initial+final/2  0+9/2;
        int middle = int(initialIndex + finalIndex)/2;
        if(array[middle] == key){
            return middle;
        }
        if(key < array[middle])
            return binarySearch(array, initialIndex, middle-1, key);
        if(key > array[middle])
            return binarySearch(array, middle+1, finalIndex, key);
    }
    return -1;
}


int search_main() {
    vector<int> arr = {1,3,4,5,6,78,9,0,12,32,4,345,3,46,45,645,6};
    cout << sequentialSearch(arr, 111) << endl;

    vector<int> arr2 = {1,3,5,7,9,11,13,14,16,17,18,20,22,24,26,28};
    int lastInd = int(arr2.size()-1);
    cout << "value index" << binarySearch(arr2, 0, lastInd, 16) << endl;
    return 0;
}







//Teacher's code

/*
 * https://repl.it/login?goto=/join/auebcwvp-ertello
 */