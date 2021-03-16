//
// Created by Carla Onate on 14/03/21.
//

#include "Server.h"

//Constructor: Lee archivo txt y guarda los que son tipo ServerLog - manda llamar función para ordenar el vector logs
Server::Server() {
    std::string line;
    std::ifstream serverFile ("../bitacora_servidor.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.
    if (serverFile.is_open()){
        while (getline (serverFile,line)){
            logs.push_back(new ServerLog(line));
        }
        serverFile.close();
    } else std::cout << "Unable to open file";

    //Order
    this->orderLogs();
}

//Llama funcion para ordenar con metodo quicksort.
void Server::orderLogs() {
    this->quickSort(logs, 0, long(logs.size()-1));
}

//Parte de algortimo de ordenamiento quick sort - busca valores antes y despues del pivot - regresa valor del pivot
long Server::partition(std::vector<ServerLog*>& array, long low, long high) {
    //Inputs: array dividida de quicksort, index left del array y index right del array

    ServerLog pivot = *array[high];    // *array[high] derefences the pointer to be able to compare objets otherwise we are comparing obj identities. https://stackoverflow.com/questions/12764329/overloaded-operator-in-c-is-not-called
    long ind = (low - 1);

    for(long j = low; j <= high- 1; j++){
        if(*array[j] <= pivot){
            ind++;
            ServerLog* temp = array[ind];
            array[ind] = array[j];
            array[j] = temp;
        }
    }
    ServerLog* temp = array[ind+1];
    array[ind+1] = array[high];
    array[high] = temp;
    return (ind + 1);
}

//Funcion recursiva para ordenamiento, llama funcion superior partition
void Server::quickSort(std::vector<ServerLog*> & array, long low, long high) {
    //Inputs: sub array , index  left de array, index right del array
    if (low < high){
        long pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

//Da instrucciones al usuario para meter valores de búsqueda y consigue index de valores y manda a imprimir resutlado de búsqueda
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
        this->printSearch(firstIndexLog, secondIndexLog);
    }

}

//Crea un subvector de string con el rango de busqueda, crea vector tipo string de uno de tipo ServerLog imprime resultado de búsqueda y llama función para generar txt con resultados
void Server::printSearch(long firstInd, long secondInd) {
    //Inputs: Index de primer valor de busqueda e index segundo valor de bisqueda
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

//Crea archivo txt con resutaldos
void Server::searchFile(std::vector<std::string> searchResult){
    //Inputs: El vector con puras lineas de texto para ser guardado en txt
    std::ofstream resultFile("search_result.txt");
    if(!resultFile) std::cout << "Algo no jaló \n";
    if(resultFile.is_open()){
        for(std::string el : searchResult){
            resultFile << el + "\n";
        }
        resultFile.close();
    }

}

//Funcion sirve para comprar el valor de búsqueda con el elemento medio en binary search - regresa bool
bool Server::compareLogs(ServerLog* el, std::vector<std::string>& search, bool first){
    //Regres true si valor busqueda 1 o 2 son iguales al mid que encontró binarySearch
    //el is the one being compared, search is a vector with all the search info, bool first is to know which date from search to compare
    bool same = false;
    std::string elMonth = el->getMonth();
    std::string elDay = el->getDay();
    std::string elHours = el->getHours();

//  search vector contains following values at the following index
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

//Función recursiva para búesqueda binaria - regresa index del valor encontrado
long Server::binarySearch(std::vector<ServerLog*> arr, long left, long right, std::vector<std::string>& value, bool first) {
    //Recibe el array a comparar, index izq, index derecho, el array de valores de búsqueda y un bool para saber si se esta buscando el primer valor de búsqueda o el segundo
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

