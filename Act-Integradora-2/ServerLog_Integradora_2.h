//
// Created by Carla Onate on 12/04/21.
//

#ifndef ACT_INTEGRADORA_2_SERVERLOG_H
#define ACT_INTEGRADORA_2_SERVERLOG_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

/*
 * En est clase se interpreta la linea de codigo de la bitacora y se guardan valores tipo tm, tm*, tm_m
 * para poder comparar un nodo con otro usando el timepo epoch, otro el objeto
 * para poder accesar diferentes partes de la fecha que son de diferntes tipos.
 */

class ServerLog{
public:
    std::string log = "";
    std::string ip = "";
    std::string errorMsg = "";
    time_t epoch;
    tm data_obj;

    ServerLog(std::string);
    std::vector<std::string> parse(std::string, std::string, int);
    int setNumberMonth(std::string& monthInput);
};

#endif //ACT_INTEGRADORA_2_SERVERLOG_H
