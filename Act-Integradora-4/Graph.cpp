//
// Created by Carla Onate on 18/05/21.
//

#include "../../../../../../CLionProjects/TC1031-A01653555/Act-Integradora-4/Graph.h"


Graph::Graph() {
    //Leer archivo y crear adjecency list of objects
    /*
     * 1.- Leer bitacora
     * 2.- Crear lista con intpu de formato bitacora
     * 3.- Parsear linea
     * 4.- Crear objeto con datos despues del parse - mes, dia, hora, ipOrigen, ipDestino y msg.
     * 5.- Agregar adjList
     *
     * 1.- Crear Heap
     */
    int lineCounter = 0;
    std::string row;
    std::string col;

    int numVertices;

    std::string line;
    std::ifstream serverFile ("../bitacoraGrafos.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.

    if (serverFile.is_open()){
        while (getline (serverFile,line)){
            if(lineCounter == 0){
                std::vector<std::string> stringLine = parse(line, " ");
                numVertices = std::stoi(stringLine[0]);
                vertices = numVertices;
                adjList = new std::vector<GraphNode>[numVertices];
            } else if (lineCounter <= numVertices){    //lineCounter starts at 1 here
                mapObj.insert({line, lineCounter-1}); //Key is IP and Value is double - stores key-val of each ip and the corresponding index in the adjlist
            } else {
                std::vector<std::string> parsedLog = parse(line, " ");
                //Parsing basic info from line
                std::string month = parsedLog[0];
                std::string day = parsedLog[1];
                std::string time = parsedLog[2];

                std::string fullIp1 = parsedLog[3];
                std::vector<std::string> parsedIp1 = parse(fullIp1, ":");

                std::string fullIp2 = parsedLog[4];
                std::vector<std::string> parsedIp2 = parse(fullIp2, ":");

                std::string ip_1 = parsedIp1[0];
                std::string ip_2 = parsedIp2[0];


                //Parsing msg from line
                std::vector<std::string> parsedMsg = parse(line, parsedLog[4]);
                std::string logMsg = parsedMsg[1];

                //Create Obj with data
                GraphNode newNode1(month, day, time, ip_1, ip_2, logMsg); //origin ip is ip_1

                int index1 = mapObj.find(ip_1)->second; //Second values is index where that ip is going to be stored

                addEdge(index1, newNode1);

            }
            lineCounter++;
        }
        serverFile.close();
    } else std::cout << "Unable to open file";

//    BFS(0);
}


std::vector<std::string> Graph::parse(std::string text, std::string splitKey) {
    std::vector<std::string> parseResult;

    int splitCounter = 0;
    int start = 0;
    int end = text.find(splitKey);    //Index of space found
    while (end != -1) {         //Condition false when find() returns -1 because no space was found.
        parseResult.push_back(text.substr(start, end-start));
        start = end + splitKey.size();
        end = text.find(splitKey, start);
        splitCounter++;         //To separate everything before text msg and stop separating msg.
    }
    parseResult.push_back(text.substr(start, text.size()-1));
    return parseResult;
}


void Graph::addEdge(int ind, const GraphNode& obj) {
    adjList[ind].push_back(obj);
}


void Graph::getMostAdjacentIp() {
    /*
     * 1.- Llenar el Heap con objetos y num de vecinos
     * 2.- Llamar sort del heap
     * 3.- Imprimir primeros 5 valores del Heap
     */

    //Adding values to heap
    for(int i = 0; i < vertices; i++){
        auto* newNode = new GraphNode();
        if(adjList[i].empty()){
            for (auto& it : mapObj) {
                if (it.second == i) { //Find ip of that index to store in object
                    newNode->ipOrigen = it.first;
                }
            }
        } else {
            newNode->ipOrigen = adjList[i][0].ipOrigen;
        }
        newNode->vecinos = adjList[i].size();

        heap.push(newNode);
    }
    heap.sort();
//    heap.printHeap();
    heap.printHighestVal();

}



void Graph::printList(){
    std::cout << "\n";
    std::string ip;
    for (int i = 0; i < vertices; i++){
        for (auto& it : mapObj) {
            if (it.second == i) { //Find ip of that index to store in object
                ip = it.first;
            }
        }
        std::cout << "vertex " << ip << ": ";
        for (const GraphNode& j : adjList[i]){
            std::cout << " " << j.ipDestino << " ";
        }
        std::cout << "\n";
    }

}