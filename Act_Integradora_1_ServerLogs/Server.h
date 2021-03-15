//
// Created by Carla Onate on 14/03/21.
//

#ifndef ACT_INTEGRADORA_1_SERVER_H
#define ACT_INTEGRADORA_1_SERVER_H

#include "../../../../../../CLionProjects/Act_Integradora_1/ServerLog.h"
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
    void printLogs();

    long partition(std::vector<ServerLog*>&, long, long);
    void quickSort(std::vector<ServerLog*>&, long, long);

    void searchLog();
    void printSearch(long, long);
    void searchFile(std::vector<std::string>);
    bool compareLogs(ServerLog*, std::vector<std::string>&, bool);
    long binarySearch(std::vector<ServerLog*>, long, long, std::vector<std::string>&, bool);

};

#endif //ACT_INTEGRADORA_1_SERVER_H
