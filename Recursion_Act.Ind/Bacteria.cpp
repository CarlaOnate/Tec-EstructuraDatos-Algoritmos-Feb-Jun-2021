//
// Created by Carla Onate on 13/02/21.
//

#include "Bacteria.h"

double Bacteria::bateriaIterativa(int days) {
    double total = 0;
    for(int i = 0; i <= days; i++){
        if(i < 1){
            total = 1;
        } else {
            //Todo: Cada día +378% -234% = 1.44
            total = total + ((i-1)*1.44);
        }
    }
    return round(total); //round return double type
}

double Bacteria::bacteriaRecursiva(int days) {
    if(days < 1){
        return 1;
    } else {
        return round((days-1)*1.44 + bacteriaRecursiva(days-1));
    }
}

