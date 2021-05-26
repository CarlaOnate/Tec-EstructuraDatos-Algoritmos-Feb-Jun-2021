//
// Created by Carla Onate on 12/05/21.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>


class Graph {
private:
    int vertices;
    int archs;

    std::vector<int> *adjList; //Need to give memory location of the std::vector<int> obj to point at

    bool **matrix;

    bool *visited = new bool[vertices];


public:
    Graph(int, int);

    void loadGraphMat();
    void loadGraphList();

    void printMatrix();
    void printList();

    void breathFirst(int);
    void depthFirstList(int);
    void depthFirstMatrix(int);

};

#endif //GRAPH_GRAPH_H
