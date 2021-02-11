//
// Created by Carla Onate on 11/02/21.
//

//#include "Recursion.h"
#include <iostream>
using namespace std;

//Todo: SumaIterativa - iterativo

int sumaIterativa(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        sum = sum + i;
    }
    return sum;
}

//Todo: SumaRecursiva - recursivo

int sumaRecursiva(int n){
    if(n == 0){
        return 0;
    } else {
        return n + sumaRecursiva(n-1);
    }
}

//Todo: SumaDirecta = n(n-1)/2 - formulazo

int sumaDirecta(int n){
    if(n == 0){
        return 0;
    } else {
        return (n * (n-1))/2;
    }
}


//Todo: factorial - recursivo

int factorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

