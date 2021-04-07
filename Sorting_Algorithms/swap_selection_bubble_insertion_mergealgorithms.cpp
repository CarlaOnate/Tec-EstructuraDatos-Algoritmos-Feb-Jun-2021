//
// Created by Carla Onate on 08/03/21.
//

#include <iostream>
#include <vector>
using namespace std;

/*Review: When a vector is passed to a funct a copy is created
 * so for the function to modify the array from main we hve to pass by reference.
 * To pass by reference we add
 *  void func(vector<int> &vec)
 * and we call it in main normally: func(vect);
 * When we pass an array to a function a pointer is passed, not a copy.
 */

//Review: also read that using namespace std; is a BAD PRACTICE because it can cause some weird bugs. Mostly with imported libraries.

//https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
//https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice/1453605#1453605

template <class T>
void swapSort(vector<T> &values, int n, int compara, int swap) { //Iterative
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


vector<int> selectionSort(vector<int> array){ //Iterative
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


vector<int> bubbleSort(vector<int> array){ //Iterative
    for(int i = 0; i < array.size(); i++){
        cout << i << "  " << array[i] << endl;
        int swaps = 0;
        for(int j = 0; j < array.size()-i-1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swaps = 1;
            }
        }
        if(!swaps){
            break;
        }
    }
    return array;
}


vector<int> insertionSort(vector<int> array){ //Iterative algorithm
    //Agarras valor de array y comparas con anterior a ver si es menor o mayor, si es menor sigues pasandolo a la izq hasta que la condicion sea falsa.
    for(int i = 1; i < array.size(); i++){
        int index = i;
        while(array[index] < array[index-1] && index >= 0){
            //Swap i with left element (i-1)
            int temp = array[index-1];
            array[index-1] = array[index];
            array[index] = temp;
            index--;
        }
    }
    return array;
}



//Merge sort uses recursive merge sort and function merge
//Review: Usually in C++ the & or * sign is placed right after the type

//void merge(vector<int>& array, int l, int m, int r){
////    cout << "inputs: " << l << "  |   " << m << "   |   " << r << endl;
//
//    int n1 = m -l + l; //index of first sub array
//    int n2 = r - m; //index of second sub array
//
//    //Todo: Not showing proper array values.
//    vector<int> L (n1, 0);
//    vector<int> R (n2, 0); //Create arrays for right and left
//
//    for (int i = 0; i < n1; ++i){
//        L[i] = array[l + i];
//    }
//    for (int j = 0; j < n2; ++j){
//        R[j] = array[m + 1 + j];
//    }
//
//
//    int i = 0, j = 0, k = 0;    //Create index for each array, first sub, second sub and merged array
//
//    while(i < n1 && j < n2){
//        if(L[i] <= R[j]){       //Si el valor en array izq es menor se pone primero en merged array
//            array[k] = L[i];
//            i++;                //Se compara ahora el siguiente valor del array izq con el mismo valor del array derecho
//        } else {
//            array[k] = R[j];    //Sino el valor de right es menor y se pone primero en array
//            j++;                // luego se compara siguiente valor de right con mismo valor de left
//        }
//        k++;                    //Depues de comprar se suma al index del array mergeado para poder agregar otro valor.
//    }
//
//    while (i < n1) {            //If there are no more elements to compare, copy remaining elements of Left array to merged array
//        array[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {            //Then copy elements of second array if any.
//        array[k] = R[j];
//        j++;
//        k++;
//    }
//
//}
//
//
//
//void mergeSort(vector<int>& array, int l, int r){ //Recursive algorithm
////    cout << "Merge Sort - inputs: " << l << "  |   " << r << endl;
//    if(l >= r){
//        return;
//    }
//    int m = l + (r - l) / 2;
//    mergeSort(array, l, m);
//    mergeSort(array, m+1, r);
//    merge(array, l, m, r);
//}



int main() {
    vector<int> array = {5,6,32,8,7,45,9,135,4,26,8};
    vector<char> arrChar = {'A','D','J','P','D','W','Y','C','R','E','M'};

    swapSort(arrChar, arrChar.size(), 0, 0);

    vector<int> sorted_1 = selectionSort(array);
    vector<int> sorted_2 = bubbleSort(array);
    vector <int> sorted_3 = insertionSort(array);

//    vector<int> arrayMergeVec = {5,6,32,8,7,45,9,135,4,26,8};
//    mergeSort(arrayMergeVec, 0, int(arrayMergeVec.size()-1));

    cout << "Swap: { ";
    for(char el : arrChar){
        cout << " " << el << " ";
    }
    cout << " }" << endl;

    cout << "Selection: { ";
    for(int el : sorted_1){
        cout << " " << el << " ";
    }
    cout << " }" << endl;


    cout << "Bubble: { ";
    for(int el : sorted_2){
        cout << " " << el << " ";
    }
    cout << " }" << endl;

    cout << "Insertion: { ";
    for(int el : sorted_3){
        cout << " " << el << " ";
    }
    cout << " }" << endl;

//    cout << "Merge: { ";
//    for(int el : arrayMergeVec){
//        cout << " " << el << " ";
//    }
//    cout << " }" << endl;



    return 0;
}
