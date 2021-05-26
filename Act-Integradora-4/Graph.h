//
// Created by Carla Onate on 18/05/21.
//

//    https://hackingcpp.com/cpp/std/associative_containers.html

#ifndef ACT_INTEGRADORA_4_GRAPH_H
#define ACT_INTEGRADORA_4_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include "GraphNode.h"
#include <fstream>
#include <map>
#include <list>
#include "Heap.h"

class Graph {
private:
    int vertices = 0;
    std::vector<GraphNode>* adjList;
    std::map<std::string, int> mapObj;

    //Heap obj aquí
    Heap heap;

public:
    Graph(); //Read bitacora - create graph
    std::vector<std::string> parse(std::string, std::string); //Parse bitacora to find links
    void addEdge(int, const GraphNode&);
    void getMostAdjacentIp();

    void printList();

};

#endif //ACT_INTEGRADORA_4_GRAPH_H
