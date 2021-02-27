//
// Created by Carla Onate on 27/02/21.
//

#include <iostream>
using namespace std;
#include <vector>
#include "string"


char sequentialSearchString (string line){
    int counter = 0;
    char letter;
    for(int i = 0; i < line.size()-1; i+=2){
        if(line[i] != line[i+1]){
            cout << "Secuencial: " << line[i] << " " << counter << endl;
            letter = line[i];
            i = line.size();
        }
        counter++;
    }
    return letter;
}


int binarySearchString (string line, int initial, int final, char key, int counter){
    int mid = floor((initial + final)/2);
    mid = mid % 2 != 0 ? mid + 1 : mid;
    if(key == line[mid]){  //The key value is passed from sequential search.
        cout << "Binario: "<< line[mid] << " " << counter << endl;
        return mid;
    } else if(key < line[mid]){
        //Searching the lower half of the string
        binarySearchString(line, initial, mid-1, key, counter+=1);
    } else if(key > line[mid]){
        //Searching upper half of algorithm
        binarySearchString(line, mid+1, final, key, counter+=1);
    } else {
        return -1;
    }
}


int search_main_act() {
    vector<string> vectorStrings;
    string lineInput;
    char key;
    int n, index;


    cout << "Ingrese n " << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        string storing;
        cout << "Ingresa el string" << endl;
        cin >> lineInput;
        vectorStrings.push_back(lineInput);
    }

    for(string line: vectorStrings){
        key = sequentialSearchString(line);
        binarySearchString(line, 0, int(line.size()-1), key, 0);
    }


    return 0;
}

