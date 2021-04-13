//
// Created by Carla Onate on 09/04/21.
//

#include "Node_Integradora_2.h"

//Funcion para inicializar nodo que crea el objeto serverLog que se guardará en data
Node::Node(std::string log) {
    ServerLog* serverLog = new ServerLog(log);
    next = nullptr;
    prev = nullptr;
    data = serverLog;
}

