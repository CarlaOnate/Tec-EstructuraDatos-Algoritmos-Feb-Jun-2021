//
// Created by Carla Onate on 01/03/21.
//

//Pago to see algorithms visually how they work: https://visualgo.net/en/sorting

#include <iostream>
#include <chrono>
using namespace std;

void swapSort(int values[], int n, int *compara, int *swap) {
    int i, j, temp;
    *compara = 0;
    *swap = 0;
    for (i=0; i < n-1; i++){
        for (j=i+1; j < n; j++){
            (*compara)++;
            if (values[i] > values[j]) {
                (*swap)++;
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

int main(void) {
    int i, size, key, flag;
    int comparaciones, swaps;

    // Inicio conteo de tiempo de ejecución
    auto startTime = std::chrono::high_resolution_clock::now();
    cin >> size;
    cout << "Size: " << size << endl;
    cin >> flag;
    cout << "Print flag: " << flag << endl;
    // Declaración del arreglo
    int * myArray = new int[size];
    // Lectura de los elementos del arreglo
    for(i = 0; i < size; i++) {
        cin >> myArray[i];
    }
    if (flag) {
        cout << "Los elementos del arreglo son: " << endl;
        for(i = 0; i < size; i++) {
            cout << myArray[i] << " ";
        }
        cout << endl;
    }
    // Ordenamiento del arreglo
    swapSort(myArray, size, &comparaciones, &swaps);
    if (flag) {
        cout << "Los elementos del arreglo ordenado son: " << endl;
        for(i = 0; i < size; i++) {
            cout << myArray[i] << " ";
        }
        cout << endl;
    }
    // Termina conteo de tiempo de ejecución
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios: " << swaps << endl;
    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << endl;
    return 0;
}
