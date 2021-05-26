//
// Created by Carla Onate on 22/05/21.
//

#include "GraphNode.h"

GraphNode::GraphNode() {
    mes = "";
    día = "";
    hora = "";
    msg = "";
    ipOrigen = "";
    ipDestino = "";
}


GraphNode::GraphNode(std::string m, std::string d, std::string h, std::string ip1, std::string ip2, std::string msgInput) {
     mes = m;
     día = d;
     hora = h;
     msg = msgInput;
     ipOrigen = ip1;
     ipDestino = ip2;
}


