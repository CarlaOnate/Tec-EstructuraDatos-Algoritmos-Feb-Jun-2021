//
// Created by Carla Onate on 12/05/21.
//

#include "Graph.h"

Graph::Graph(int verticeInput, int archInput) {
//    Initialize matrix to 0s
    vertices = verticeInput;
    archs = archInput;
    matrix = new bool*[vertices];
    for (int i = 0; i < vertices; i++) {
        matrix[i] = new bool[vertices];
        for (int j = 0; j < vertices; j++)
            matrix[i][j] = false;
    }

    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
}


void Graph::loadGraphMat() {
    std::string string1;
    std::string string2;

    std::string line;
    std::ifstream serverFile ("../star-1.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.

    if (serverFile.is_open()){
        while (getline (serverFile,line)){
            std::string line2 = line;
            string1 = line2[1];
            string2 = line2[4];
            int index1 = std::stoi(string1);
            int index2 = std::stoi(string2);
            //Add values in matrix as true
            matrix[index1][index2] = true;
            matrix[index2][index1] = true;
        }
        serverFile.close();
    } else std::cout << "Unable to open file";

    breathFirst(0);

    std::cout << "\n Depth First \n";
    //Set visited list el to false - default values
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    depthFirstMatrix(0);

    printMatrix();

}


void Graph::loadGraphList() {
    std::string row;
    std::string col;

    std::string line;
    std::ifstream serverFile ("../star-1.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.

    if (serverFile.is_open()){
        adjList = new std::vector<int>[vertices];
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

    breathFirst(1);

    std::cout << "\n Depth First \n";
    //Set visited list el to false - default values
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }
    depthFirstList(0);

    printList();
}


void Graph::printMatrix() {
    std::cout << "\n";
    for (int i = 0; i < vertices; i++) {
        std::cout << i << " : ";
        for (int j = 0; j < vertices; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}


void Graph::printList(){
    std::cout << "\n";
    for (int i = 0; i < vertices; i++){
        std::cout << "vertex " << i << ": ";
        for (int j : adjList[i]){
            std::cout << " " << j << " ";
        }
        std::cout << "\n";
    }
}


void Graph::breathFirst(int type){
    // Mark all the vertices as not visited
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }

    // Create a queue for BFS
    std::list<int> queue;
    int s = 0;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    std::cout << "\n BreathFirst \n";

    while(!queue.empty()) {
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        if(type == 0) {
            for (int i = 0; i < vertices; i++) {
                //Matrix has true and false values, 1 and 0s.
                if (matrix[s][i] == 1 && (!visited[i])){
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        } else {
            for (int i = 0; i <= adjList[s].size(); i++){
                if (!visited[i]){
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }
    }
}


void Graph::depthFirstList(int s){

    // Create a stack for DFS
    std::stack<int> stack;

    // Push the current source node.
    stack.push(s);

    while (!stack.empty()){
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s]){
            std::cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i){
            if (!visited[*i]){
                stack.push(*i);
            }
        }
    }
}


void Graph::depthFirstMatrix(int s){
    std::stack<int> stack;

    stack.push(s);

    while (!stack.empty()) {
        s = stack.top();
        stack.pop();

        if (!visited[s]) {
            std::cout << s << " ";
            visited[s] = true;
        }

        visited[s] = true;
        for (int j = s; j <= vertices; j++) {
            if (!visited[j] && matrix[s][j] == 1) {
                stack.push(j);
            }
        }
    }
}