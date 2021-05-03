//
// Created by Carla Onate on 30/04/21.
//

#ifndef ACT_INTEGRADORA_3_LOG_H
#define ACT_INTEGRADORA_3_LOG_H

#include <string>
#include <vector>
#include <iostream>

class Log {
private:
    std::vector<std::string> ipStrings;
    std::vector<std::string> logs;
    std::string log;


public:
    int attempts = 0;
    std::string ip;

    Log();
    Log(std::string);
    Log(std::string, int);
    std::vector<std::string> parse(std::string, std::string);

    //Getters
    std::string getIp();
    int getAttempts();
    std::string getLog();
    std::vector<std::string> getLogs();

    //Setters
    void setLogs(std::vector<std::string>);
    std::vector<std::string> getIpStrings();
    void setAttempts(int);
    void setIp(std::string);

};

std::vector<std::string> parse(std::string, std::string);

bool operator> (Log*&, const std::string&);


#endif //ACT_INTEGRADORA_3_LOG_H
