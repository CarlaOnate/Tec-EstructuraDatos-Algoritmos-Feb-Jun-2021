//
// Created by Carla Onate on 14/03/21.
//

#include "Server.h"

Server::Server() {
    std::string line;
    std::ifstream serverFile ("../bitacora_servidor.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.
    if (serverFile.is_open()){
        while (getline (serverFile,line)){
            logs.push_back(new ServerLog(line)); //Push objets type ServerLog to the vector
        }
        serverFile.close();
    } else std::cout << "Unable to open file";

    //Order
    this->orderLogs();
}


void Server::orderLogs() {
    //Quick sort ordering
    this->quickSort(logs, 0, long(logs.size()-1));
}


void Server::printLogs() {
    std::cout << "Logs { ";
    for(ServerLog* el : logs){
        el->printLog();
    }
    std::cout << " } \n";}


long Server::partition(std::vector<ServerLog*>& array, long low, long high) {
    ServerLog pivot = *array[high];    // *array[high] derefences the pointer to be able to compare objets otherwise we are comparing obj identities. https://stackoverflow.com/questions/12764329/overloaded-operator-in-c-is-not-called
    long i = (low - 1);  // Index of smaller element

    for(long j = low; j <= high- 1; j++){
        if(*array[j] <= pivot){
            i++;    // increment index of smaller element
            ServerLog* temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    ServerLog* temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return (i + 1);
}


void Server::quickSort(std::vector<ServerLog*> & array, long low, long high) {
    if (low < high){
        long pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


void Server::searchLog(){
    std::string monthNumbers [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    std::string firstMonth, secondMonth, firstMonthNumber, secondMonthNumber, firstDay, secondDay, firstHour, secondHour;

    std::cout << "Ingrese primer mes: (Jun, Jul, Aug, Sep, Oct) \n";
    std::cin >> firstMonth;
    std::cout << "Ingrese primer día: (05) \n";
    std::cin >> firstDay;
    std::cout << "Ingrese primera hora: (05) \n";
    std::cin >> firstHour;
    std::cout << "Ingrese segundo mes: (Jun, Jul, Aug, Sep, Oct)\n";
    std::cin >> secondMonth;
    std::cout << "Ingrese segundo dia: (09)\n";
    std::cin >> secondDay;
    std::cout << "Ingrese segunda hora: (09) \n";
    std::cin >> secondHour;

    for(int i = 0; i < 12; i++){
        if(monthNumbers[i] == firstMonth) firstMonthNumber = std::to_string(i + 1);
        if(monthNumbers[i] == secondMonth) secondMonthNumber = std::to_string(i + 1);
    }


    search = {firstMonth, firstMonthNumber, firstDay, firstHour, secondMonth, secondMonthNumber, secondDay, secondHour, "first"};
    long firstIndexLog = this->binarySearch(logs, 0, logs.size()-1, search, true);
    long secondIndexLog = this->binarySearch(logs, 0, logs.size()-1, search, false);
    if(firstIndexLog < 0 || secondIndexLog < 0){
        std::cout << "No se encontró el valor, intenta de nuevo.\n";
    } else {
        std::cout << "After binary - firstIndex: " << firstIndexLog << "  SecondInd:  " << secondIndexLog << "\n";
        this->printSearch(firstIndexLog, secondIndexLog);
    }

}


void Server::printSearch(long firstInd, long secondInd) {
    std::vector<ServerLog*> result(secondInd - firstInd + 1);
    std::vector<std::string> stringResult(secondInd - firstInd + 1);

    auto start = logs.begin() + firstInd;
    auto end = logs.begin() + secondInd + 1;

    std::copy(start, end, result.begin());

    std::cout << "Result:  ";
    for(long i = 0; i < (secondInd - firstInd + 1); i++){
        stringResult[i] = result[i]->stringLog();
        std::cout << stringResult[i] << "\n";
    }

    this->searchFile(stringResult);

}


void Server::searchFile(std::vector<std::string> searchResult){ //No paso por referencia porque cambio se guardan en un txt, no quiero cambiar original
    std::ofstream resultFile("search_result.txt");
    if(!resultFile) std::cout << "Algo no jaló \n";
    if(resultFile.is_open()){
        std::cout << "file is open \n";
        for(std::string el : searchResult){
            resultFile << el + "\n";
        }
        resultFile.close();
    }

}


bool Server::compareLogs(ServerLog* el, std::vector<std::string>& search, bool first){
    //el is the one being compared, prev to know if its first day of month, next to know last day of month - search is value being searched for
    bool same = false;
    std::string elMonth = el->getMonth();
    std::string elDay = el->getDay();
    std::string elHours = el->getHours();
//  search = {firstMonth, firstMonthNumber, firstDay, firstHour, secondMonth, secondMonthNumber, secondDay, secondHour, "first"};

    if(first) {
        std::string searchMonth = search[0];
        std::string searchDay = search[2];
        std::string searchHour = search[3];
        same = elMonth == searchMonth && elDay == searchDay && elHours == searchHour; //to find first occurrence of that day
    } else {
        std::string searchMonth = search[4];
        std::string searchDay = search[6];
        std::string searchHour = search[7];
        same = elMonth == searchMonth && elDay == searchDay && elHours == searchHour; //to find the las occurrence of that day
    }

    return same;

}



long Server::binarySearch(std::vector<ServerLog*> arr, long left, long right, std::vector<std::string>& value, bool first) {
    //Todo: First date index is incorrect
    if (left <= right) {
        first ? value[8] = "first" : value[8] = "last";

        long mid = (left + right)/2;
        if (this->compareLogs(arr[mid], value, first)){
            return mid;
        }
        if (*arr[mid] > value){
            return binarySearch(arr, left, mid-1, value, first);
        }
        if (*arr[mid] < value){
            return binarySearch(arr, mid+1, right, value, first);
        }
    }
    return -1;
}

