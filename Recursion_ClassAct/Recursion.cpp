//
// Created by Carla Onate on 11/02/21.
//

//#include "Recursion.h"

//Todo: SumaIterativa

int sumaIterativa(n){
    sum = 0;
    for(int i = 1; i < n; i++){
        sum = sum + i;
    }
    return sum;
}

//Todo: SumaRecursiva

int sumaRecursiva(n){
    if(n == 0){
        return 0;
    } else {
        return n + sumaRecursiva(n-1);
    }
}

//Todo: SumaDirecta - suma = (n+1)/2

int sumaDirecta(n){
    if(n == 0){
        return 0;
    } else {
        return sumaDirecta((n+1)/(2));
    }
}


//Todo: factorial

int factorial(n){
    if(n == 0){
        return 1;
    } else {
        return n * factorial(n-1);
    }

}

