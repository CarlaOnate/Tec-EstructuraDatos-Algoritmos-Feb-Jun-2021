//
// Created by Carla Onate on 13/03/21.
//

#ifndef ACT_INTEGRADORA_1_SERVERLOG_H
#define ACT_INTEGRADORA_1_SERVERLOG_H

#endif //ACT_INTEGRADORA_1_SERVERLOG_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class ServerLog{
private:
    //Log info - pdf de canvas
    std::string month;
    int monthNumber;
    std::string day;
    std::string time;
    std::string hours;
    std::string minutes;
    std::string seconds;
    std::string ip;
    std::string errorMsg;

public:
    ServerLog(std::string);
    std::vector<std::string> parse(std::string, std::string, int);
    std::string getDay();
    std::string getHours();
    std::string getMonth();
    void printLog();
    std::string stringLog();
    void setNumberMonth(const std::string&);
    bool operator > (const std::vector<std::string>&);
    bool operator < (const std::vector<std::string>&);
    bool operator<=(const ServerLog&);

};