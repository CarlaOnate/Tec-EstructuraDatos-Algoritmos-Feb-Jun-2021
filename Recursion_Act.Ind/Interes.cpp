//
// Created by Carla Onate on 13/02/21.
//

#include "Interes.h"

double Interes::interesIterativo(int months, double qty) {
    double total = 0;
    for(int i = 1; i <= months; i++){
        if(i < 2){
            total = qty + qty*.1875;
        } else {
            total = total + total*.1875;
        }
    }
    return total;
}


double Interes::interesRecursivo(int months, double qty) {
    if(months < 2){
        return qty + qty*.1875;
    } else {
        return interesRecursivo(months-1, (qty+qty*.1875));
    }
}

