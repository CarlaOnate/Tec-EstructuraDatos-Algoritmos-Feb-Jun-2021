//
// Created by Carla Onate on 18/05/21.
//

#ifndef GRAPH_ALGORITHMS_GRAPH_H
#define GRAPH_ALGORITHMS_GRAPH_H

#include <list>
#include <stack>
#include <fstream>
#include <iostream>

class Graph {
private:
    int vertices;
    std::list<int>* adjList;

public:
    Graph(int);
    void makeList();
    void topologicalSort();

    void DFS(int, bool [], std::stack<int>&);

};

#endif //GRAPH_ALGORITHMS_GRAPH_H
