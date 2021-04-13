//
// Created by Carla Onate on 09/04/21.
//

#ifndef ACT_INTEGRADORA_2_NODE_H
#define ACT_INTEGRADORA_2_NODE_H


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "ServerLog_Integradora_2.h"

//Esta clase tiene los valores de next y prev para lista doblemente ligada y el valor data es de tipo ServerLog
//El tipo ServerLog es el que tiene la info de cada log de la bitacora. Se hizo así para que fucnionara el swap en el quicksort.

class Node{
public:
    Node* next;
    Node* prev;
    //Review: Profe aqui deje el puntero porque sino mi IDE me marcaba error, decía que el valor tenía que inicializarlo a fuerzas porque no tenia un constructor default
    ServerLog* data;

    Node();
    Node(std::string);

};

#endif //ACT_INTEGRADORA_2_NODE_H
