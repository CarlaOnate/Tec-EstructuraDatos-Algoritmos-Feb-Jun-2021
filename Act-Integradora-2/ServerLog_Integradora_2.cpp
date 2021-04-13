//
// Created by Carla Onate on 12/04/21.
//

#include "ServerLog_Integradora_2.h"

//Funcion que interpreta el string de la bitacora para sacar la fecha, el ip y el mensaje de error.
ServerLog::ServerLog(std::string logInput){
    time_t date;
    tm* date_ptr;
    log = logInput;

    //Regresa vector con string separado entre mes dia tiempo ip y mensaje
    std::vector<std::string> parsedLog = this->parse(logInput, " ", 4);

    std::string month = parsedLog[0];
    std::string day = parsedLog[1];
    std::string logTime = parsedLog[2];
    ip = parsedLog [3];
    if(parsedLog.size()-1 == 4){
        errorMsg = parsedLog[4];
    }

    //Regresa el parse solo de el timepo ahora con hora minuto segundo
    std::vector<std::string> parsedTime = this->parse(logTime, ":", 2);

    std::string hours = parsedTime[0];
    std::string minutes = parsedTime[1];
    std::string seconds = parsedTime[2];


    //Se crea la variable tipo fecha con el string de la bitacora
    time(&date);
    date_ptr = localtime(&date);
    date_ptr->tm_mon = this->setNumberMonth(month);
    date_ptr->tm_mday = stoi(day);
    date_ptr->tm_hour = stoi(hours);
    date_ptr->tm_min = stoi(minutes);
    date_ptr->tm_sec = stoi(seconds);
    epoch = mktime(date_ptr);
    data_obj = *date_ptr;

}


//Función para parsear linea de texto asi como tiempo de la linea de texto - regresa vector de strings
std::vector<std::string> ServerLog::parse(std::string text, std::string splitKey, int limit = 0){
    //Inputs: Recibe string a separar, la llave con que separar, y el limite donde detener la separacion
    std::vector<std::string> parseResult;

    int splitCounter = 0;
    int start = 0;
    int end = text.find(splitKey);    //Index of space found
    while (end != -1 && splitCounter < limit) {         //Condition false when find() returns -1 because no space was found.
        parseResult.push_back(text.substr(start, end-start));
        start = end + splitKey.size();
        end = text.find(splitKey, start);
        splitCounter++;         //To separate everything before text msg and stop separating msg.
    }
    parseResult.push_back(text.substr(start, text.size()-1));
    return parseResult;
}


//Funcion para poder saber el numero del mes y generar un objeto tipo tm o tm_t
int ServerLog::setNumberMonth(std::string& monthInput) {
    int monthNumber = 0;
    std::string monthNumbers [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i = 0; i < 12; i++){
        if(monthNumbers[i] == monthInput) monthNumber = i;
    }
    return monthNumber;
}




