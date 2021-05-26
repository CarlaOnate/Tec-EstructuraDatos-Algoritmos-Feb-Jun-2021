//
// Created by Carla Onate on 18/05/21.
//

#include "Graph.h"

Graph::Graph(int verticeInput) {
    vertices = verticeInput;
    makeList();
    topologicalSort();
}


void Graph::makeList() {
    std::string row;
    std::string col;

    std::string line;
    std::ifstream serverFile ("../star-1.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.

    if (serverFile.is_open()){
        adjList = new std::list<int>[vertices];
        while (getline (serverFile,line)){
            std::string line2 = line;

            row = line2[1];
            col = line2[4];

            int index1 = std::stoi(row);
            int index2 = std::stoi(col);

            adjList[index1].push_back(index2);
            adjList[index2].push_back(index1);

        }
        serverFile.close();
    } else std::cout << "Unable to open file";

}


void Graph::DFS(int vertice, bool visited[], std::stack<int>& Stack){
    // Mark the current node as visited.
    visited[vertice] = true;

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for (i = adjList[vertice].begin(); i != adjList[vertice].end(); ++i){
        if (!visited[*i]){
            DFS(*i, visited, Stack);
        }
    }

    // Push current vertex to stack which stores result
    Stack.push(vertice);
}


void Graph::topologicalSort(){
    std::stack<int> Stack;

    // Mark all the vertices as not visited
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++){
        visited[i] = false;
    }

    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < vertices; i++){
        if (!visited[i]){
            DFS(i, visited, Stack);
        }
    }

    // Print contents of stack
    while (!Stack.empty()) {
        std::cout << " - " << Stack.top();
        Stack.pop();
    }
}

//
//void Graph::DFS(int s) {
//
//    // Mark all the vertices as not visited
//    bool* visited = new bool[vertices];
//    for (int i = 0; i < vertices; i++){
//        visited[i] = false;
//    }
//
//    // Create a stack for DFS
//    std::stack<int> stack;
//
//    // Push the current source node.
//    stack.push(s);
//
//    while (!stack.empty()){
//        // Pop a vertex from stack and print it
//        s = stack.top();
//        stack.pop();
//
//        // Stack may contain same vertex twice. So
//        // we need to print the popped item only
//        // if it is not visited.
//        if (!visited[s]){
//            std::cout << s << " ";
//            visited[s] = true;
//        }
//
//        // Get all adjacent vertices of the popped vertex s
//        // If a adjacent has not been visited, then push it
//        // to the stack.
//        for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i){
//            if (!visited[*i]){
//                stack.push(*i);
//            }
//        }
//    }
//}























