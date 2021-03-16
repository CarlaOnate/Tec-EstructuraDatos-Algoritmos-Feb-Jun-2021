//
// Created by Carla Onate  A01653555  - 14/03/21.
// Esta clase Server lo que hace es manejar ordenamiento de logs,
// parseo de los mismos, busqueda en los logs, impresion de logs
// y crea archivo con resultado de busqueda.

#ifndef ACT_INTEGRADORA_1_SERVER_H
#define ACT_INTEGRADORA_1_SERVER_H

#include "ServerLog.h"
#include <fstream>
#include <string>
#include <vector>

class Server{
private:
    std::vector<ServerLog*> logs;
    std::vector<std::string> search;

public:
    Server();
    void orderLogs();

    long partition(std::vector<ServerLog*>&, long, long);
    void quickSort(std::vector<ServerLog*>&, long, long);

    void searchLog();
    void printSearch(long, long);
    void searchFile(std::vector<std::string>);
    bool compareLogs(ServerLog*, std::vector<std::string>&, bool);
    long binarySearch(std::vector<ServerLog*>, long, long, std::vector<std::string>&, bool);

};

#endif //ACT_INTEGRADORA_1_SERVER_H
