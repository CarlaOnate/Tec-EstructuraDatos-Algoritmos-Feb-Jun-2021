//
// Created by Carla Onate on 22/05/21.
//

#ifndef ACT_INTEGRADORA_4_GRAPHNODE_H
#define ACT_INTEGRADORA_4_GRAPHNODE_H

#include <string>
#include <vector>

class GraphNode{

public:
    std::string mes;
    std::string día;
    std::string hora;
    std::string msg;
    std::string ipOrigen;
    std::string ipDestino;
    int vecinos = 0;
    GraphNode();
    GraphNode(std::string, std::string, std::string, std::string, std::string, std::string);
};

#endif //ACT_INTEGRADORA_4_GRAPHNODE_H
