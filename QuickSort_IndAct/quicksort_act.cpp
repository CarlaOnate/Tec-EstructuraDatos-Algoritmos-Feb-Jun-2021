//
// Created by Carla Onate on 13/03/21.
//

#include <iostream>
//#include <chrono>
#include <string>

#include "Sort.h"
using namespace std;

int main() {
    int menuOption = 1;
    int orderOption = 0;
    int searchOption = 0;
    int size;

    cout << "Menu: \n 1: array de integers \n 2: array de floats \n 3: array de chars \n";
    cin >> menuOption;
    cout << "Tamaño del arreglo: \n";
    cin >> size;
    cout << "Ordenamiento: \n 1: Swap \n 2: Selection \n 3: Bubble \n 4: Insertion \n 5: Merge \n 6: Quick \n";
    cin >> orderOption;
    cout << "Busqueda: \n 1: Secuencial \n 2: Binary \n 0:Ninguno \n";
    cin >> searchOption;


    if(menuOption == 1){
        Sort<int> obj(menuOption, orderOption, searchOption, size);
        obj.printArr("After");
    } else if(menuOption == 2) {
        Sort<float> obj(menuOption, orderOption, searchOption, size);
        obj.printArr("After");
    } else if (menuOption == 3){
        Sort<char> obj(menuOption, orderOption, searchOption, size);
        obj.printArr("After");
    }

// Manera del profe
//    auto endTime = std::chrono::high_resolution_clock::now();
//    auto totalTime = endTime - startTime;
//    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << endl;

    return 0;
}
