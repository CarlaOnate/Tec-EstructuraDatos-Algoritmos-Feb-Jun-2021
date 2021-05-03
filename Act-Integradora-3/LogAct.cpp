//
// Created by Carla Onate on 30/04/21.
//

#include "LogAct.h"


Log::Log() {
    ip = "";
    log = "";
}


Log::Log(std::string logInput) {
    std::vector<std::string> parsedLog = parse(logInput, " ");
    log = logInput;
    std::vector<std::string> parsedIp = parse(parsedLog[3], ":");
    ip = parsedIp[0];
    ipStrings = parse(parsedIp[0], ".");
}

Log::Log(std::string ipInput, int attemptsInput) {
    ip = ipInput;
    attempts = attemptsInput;

    std::vector<std::string> parsedIp = parse(ipInput, ":");
    ipStrings = parse(parsedIp[0], ".");
}


std::vector<std::string> Log::parse(std::string text, std::string splitKey) {
    //Inputs: Recibe string a separar, la llave con que separar, y el limite donde detener la separacion
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


//Review: NON MEMBER FUNCTIONS - parse, operator >
//Parse for non member function operator >
std::vector<std::string> parse(std::string text, std::string splitKey) {
    //Inputs: Recibe string a separar, la llave con que separar, y el limite donde detener la separacion
    std::vector<std::string> parseResult;

    int start = 0;
    int end = text.find(splitKey);    //Index of space found
    while (end != -1) {         //Condition false when find() returns -1 because no space was found.
        parseResult.push_back(text.substr(start, end-start));
        start = end + splitKey.size();
        end = text.find(splitKey, start);
    }
    parseResult.push_back(text.substr(start, text.size()));
    return parseResult;
}

bool operator>(Log*& obj, const std::string& logInput) {
    std::vector<std::string> inputIpStrings;
    inputIpStrings = parse(logInput, ".");
    int ip1 = stoi(obj->getIpStrings()[0]);
    int ip2 = stoi(obj->getIpStrings()[1]);
    int ip3 = stoi(obj->getIpStrings()[2]);
    int ip4 = stoi(obj->getIpStrings()[3]);

    int inputIp1 = stoi(inputIpStrings[0]);
    int inputIp2 = stoi(inputIpStrings[1]);
    int inputIp3 = stoi(inputIpStrings[2]);
    int inputIp4 = stoi(inputIpStrings[3]);

    bool test = (ip1 > inputIp1) || (ip1 == inputIp1 && ip2 > inputIp2) || (ip1 == inputIp1 && ip2 == inputIp2 && ip3 > inputIp3) || (ip1 == inputIp1 && ip2 == inputIp2 && ip3 == inputIp3 && ip4 > inputIp4);
    return test;
}
//Review: END OF NON MEMBER FUNCTIONS


//Getters
std::string Log::getIp() {
    return ip;
}

int Log::getAttempts() {
    return attempts;
}

std::vector<std::string> Log::getIpStrings(){
    return ipStrings;
}

std::string Log::getLog() {
    return log;
}

std::vector<std::string> Log::getLogs() {
    return logs;
}



//Setters
void Log::setLogs(std::vector<std::string> input){
    logs = input;
}


void Log::setAttempts(int input){
    attempts = input;
}

void Log::setIp(std::string inputIp) {
    ip = inputIp;
}



