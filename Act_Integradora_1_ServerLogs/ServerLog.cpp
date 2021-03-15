//
// Created by Carla Onate on 13/03/21.
//

#include "ServerLog.h"

ServerLog::ServerLog(std::string log){
    std::vector<std::string> parsedLog = this->parse(log, " ", 4);

    month = parsedLog[0];
    day = parsedLog[1];
    time = parsedLog[2];
    ip = parsedLog [3];
    if(parsedLog.size()-1 == 4){
        errorMsg = parsedLog[4];
    }

    std::vector<std::string> parsedTime = this->parse(time, ":", 2);

    hours = parsedTime[0];
    minutes = parsedTime[1];
    seconds = parsedTime[2];

    this->setNumberMonth(month);
}


std::vector<std::string> ServerLog::parse(std::string text, std::string splitKey, int limit = 0){
    std::vector<std::string> parseResult;

    int splitCounter = 0;
    int start = 0;
    int end = text.find(splitKey);    //Index of space found
    while (end != -1 && splitCounter < limit) {         //Condition false when find() returns -1 because no space was found.
        parseResult.push_back(text.substr(start, end-start));
        start = end + splitKey.size();
        end = text.find(splitKey, start);
        splitCounter++;         //To separate everything before text msg.
    }
    parseResult.push_back(text.substr(start, text.size()-1));
    return parseResult;
}


bool ServerLog::operator<(const std::vector<std::string>& other) {
    bool smaller = false;

    int thisDay = std::stoi(this->day);
    int thisHours = std::stoi(this->hours);
    int thisMinutes = std::stoi(this->minutes);
    int thisSeconds = std::stoi(this->seconds);

//  other = {firstMonth, firstMonthNumber, firstDay, firstHour, secondMonth, secondMonthNumber, secondDay, secondHour, "first"};
    int otherDay = other[8] == "first" ? std::stoi(other[2]) : std::stoi(other[6]);
    int otherMonthNumber = other[8] == "first" ? std::stoi(other[1]) : std::stoi(other[5]);
    int otherHours = other[8] == "first" ? std::stoi(other[3]) : std::stoi(other[7]);
    int otherMinutes = other[6] == "first" ? 00 : 60;
    int otherSeconds = other[6] == "first" ? 00 : 60;


    if(this->monthNumber == otherMonthNumber){
        if(thisDay == otherDay){
            if(thisHours == otherHours){
                if(thisMinutes == otherMinutes){
                    if(thisSeconds == otherSeconds){
                        smaller = false;
                    } else smaller = thisSeconds < otherSeconds;
                } else smaller = thisMinutes < otherMinutes;
            } else smaller = thisHours < otherHours;
        } else smaller = thisDay < otherDay;
    } else smaller = this->monthNumber < otherMonthNumber;

    return smaller;
}


bool ServerLog::operator>(const std::vector<std::string>& other) {
    bool smaller = false;

    int thisDay = std::stoi(this->day);
    int thisHours = std::stoi(this->hours);
    int thisMinutes = std::stoi(this->minutes);
    int thisSeconds = std::stoi(this->seconds);
//  other = {firstMonth, firstMonthNumber, firstDay, firstHour, secondMonth, secondMonthNumber, secondDay, secondHour, "first"};
    int otherDay = other[8] == "first" ? std::stoi(other[2]) : std::stoi(other[6]);
    int otherMonthNumber = other[8] == "first" ? std::stoi(other[1]) : std::stoi(other[5]);
    int otherHours = other[8] == "first" ? std::stoi(other[3]) : std::stoi(other[7]);
    int otherMinutes = other[8] == "first" ? 0 : 60;
    int otherSeconds = other[8] == "first" ? 0 : 60;


    if(this->monthNumber == otherMonthNumber){
        if(thisDay == otherDay){
            if(thisHours == otherHours){
                if(thisMinutes == otherMinutes){
                    if(thisSeconds == otherSeconds){
                        smaller = false;
                    } else smaller = thisSeconds > otherSeconds;
                } else smaller = thisMinutes > otherMinutes;
            } else smaller = thisHours > otherHours;
        } else smaller = thisDay > otherDay;
    } else smaller = this->monthNumber > otherMonthNumber;

    return smaller;

}


//Operator overload to compare in ordering
bool ServerLog::operator<=(const ServerLog& other) {
    bool smaller = false;

    int thisDay = std::stoi(this->day);
    int thisHours = std::stoi(this->hours);
    int thisMinutes = std::stoi(this->minutes);
    int thisSeconds = std::stoi(this->seconds);

    int otherDay = std::stoi(other.day);
    int otherHours = std::stoi(other.hours);
    int otherMinutes = std::stoi(other.minutes);
    int otherSeconds = std::stoi(other.seconds);

    if(this->monthNumber == other.monthNumber){
        if(thisDay == otherDay){
            if(thisHours == otherHours){
                if(thisMinutes == otherMinutes){
                    if(thisSeconds == otherSeconds){
                        smaller = true;
                    } else smaller = thisSeconds <= otherSeconds;
                } else smaller = thisMinutes <= otherMinutes;
            } else smaller = thisHours <= otherHours;
        } else smaller = thisDay <= otherDay;
    } else smaller = this->monthNumber <= other.monthNumber;

    return smaller;
}


//Gettesr
std::string ServerLog::getDay() {
    return day;
}

std::string ServerLog::getHours() {
    return hours;
}

std::string ServerLog::getMonth(){
    return month;
}


//Print log
void ServerLog::printLog() {
    std::cout << " { " << month << " " << day << " " << time << " " << ip << " " << errorMsg << " } \n";
}

std::string ServerLog::stringLog(){
    return month + " " + day + " " + time + " " + ip + " " + errorMsg;
}


//Setters
void ServerLog::setNumberMonth(const std::string& monthInput) {
    std::string monthNumbers [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i = 0; i < 12; i++){
        if(monthNumbers[i] == monthInput) monthNumber = i+1;
    }
}

