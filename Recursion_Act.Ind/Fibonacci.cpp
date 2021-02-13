//
// Created by Carla Onate on 12/02/21.
//
#include "Fibonacci.h"


void Fibonacci::fibonacciIterativo(int number) {
    vector<int> fibList;

    for(int i = 0; i <= number; i++){
        if(i < 2) {
            fibList.push_back(1);
            cout << fibList[i] << endl;
        } else {
            cout << fibList[i-2]+fibList[i-1] << endl;
            fibList.push_back(fibList[i-2]+fibList[i-1]);
        }
    }
}

int Fibonacci::fibonacciRecursivo(int number) {
    if(number == 1 || number == 2){
        return 1;
    } else {
        return fibonacciRecursivo(number-1) + fibonacciRecursivo(number-2);
    }
}
