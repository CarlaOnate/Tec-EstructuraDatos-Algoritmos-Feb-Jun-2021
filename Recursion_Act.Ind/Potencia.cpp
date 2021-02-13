//
// Created by Carla Onate on 13/02/21.
//

#include "Potencia.h"

double Potencia::potenciaIterativa(int x, int y) {
    //2^8, x seria 2; y es 8. y es el contador.
    double total = 0;
    for(int i = 0; i <= y; i++){
        if(i == 0){
            total = 1;
        }  else if (i == 1){
            total = x;
        } else {
            total = total * x;
        }
    }
    return total;
}

double Potencia::potenciaRecursiva(int x, int y) {
    if(y == 0){
        return 0;
    } else if(y == 1) {
        return x;
    } else {
        return x * potenciaRecursiva(x, y-1);
    }
}