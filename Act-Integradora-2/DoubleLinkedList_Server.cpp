//
// Created by Carla Onate on 09/04/21.
//


#include "DoubleLinkedList_Server.h"

//Lee archivo y crea Nodos con log del archivo, manda a llamar funciones para ordenar lista recien creada.
//Review: Node data contains another class called ServerLog with log info for further use
DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    int counter = 0;
    std::string line;
    std::ifstream serverFile ("../bitacora.txt"); //Compiler folder is not project folder - its cmake-biuld-debug. To find file need to tell it to look in the prev directory.
    if (serverFile.is_open()){
        while (getline (serverFile,line)){
            //Add linet to the last of the list
            this->addLast(line);
            counter++;
        }
        serverFile.close();
        size = counter;
    } else std::cout << "Unable to open file";

    //Order
    this->orderLogs();
}


//Funcion que agrega Nodos al final de la lista - manda llamar en constructor
void DoubleLinkedList::addLast(std::string value) {
    Node* newValue = new Node(value); //El nodo tiene como data una clase -> ServerLog que tiene los datos del log
    if(head == nullptr && tail == nullptr){
        //If list is empty
        head = newValue;
        head->prev = nullptr;
        tail = newValue;
    } else {
        //Otherwise
        newValue->prev = tail;
        newValue->next = nullptr;
        tail->next = newValue;
        tail = newValue;
    }
}


//Función para encontrar el indice de un Nodo en la lista - manda llamar en quickSort
long DoubleLinkedList::findData(Node* value) {
    // Must return position of value - added counter to do so
    Node* current = head;
    int counter = 0;
    while(current != nullptr){
    //     Compara valores tipo time_t que es el timepo desde epoch numericamente
    //     Current->data = Node* -> epoch = Valor epoch dentro de ServerLog a su vez dentro de data de Node.
    //     current(Node*) -> data(ServerLog*) -> value(tm_t)
        if(current->data->epoch == value->data->epoch){
            return counter;
        } else {
            current = current->next;
        }
        counter++;

    }
    return -1; //Value not found
}


//Funcion para odrdenar lista y crear la bitacora con la nueva lista ordenada - manda llamar desde constructor
void DoubleLinkedList::orderLogs() {
    this->quickSort();
    this->createBitacora();
}


//Funciones para cambiar valores de Nodos - Node*->data = ServerLog* - Cambia las data que son objetos tipo ServerLog
void DoubleLinkedList::swap(ServerLog* a, ServerLog* b){
     ServerLog t = *a; *a = *b; *b = t;
}


//Funciones para encontrar el pivote
Node* DoubleLinkedList::partition(Node* low, Node* high){
    //Original code: https://www.geeksforgeeks.org/quicksort-for-linked-list/

//         high(Node*) -> data(ServerLog*) -> epoch(tm_t)
    int x = high->data->epoch;

//           low(Node*) -> prev(Node*)
    Node* i = low->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node* j = low; j != high; j = j->next){
    //     j(Node*) -> data(ServerLog*) -> epoch(tm_t)
        if (j->data->epoch <= x){
            i = (i == nullptr) ? low : i->next;
            //   i(Node*)->data(ServerLog*)  |   j(Node*)->data(ServerLog*)
            swap(i->data, j->data);
        }
    }
    i = (i == nullptr) ? low : i->next; // Similar to i++
    //   i(Node*)->data(ServerLog*)  |   high(Node*)->data(ServerLog*)
    swap(i->data, high->data);
    return i;
}


//Funcion para ordenar la lista usando el algoritmo quick sort - lista iterativa con stack - manda llamar en orderLogs
void DoubleLinkedList::quickSort(){
    //Original code: https://www.geeksforgeeks.org/iterative-quick-sort/

    Node* low = head;
    Node* high = tail;

    Node* stack[size/2];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    //low and high are Node*
    stack[++top] = low;
    stack[++top] = high;


    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position in sorted array
        //low and high are Nodes*
        Node* p = partition(low, high);

        //to find index of elements
        long lowInd = findData(low);
        long highInd = findData(high);
        long pInd = findData(p);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (pInd - 1 > lowInd) {
            stack[++top] = low;
            stack[++top] = p->prev;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (pInd + 1 < highInd) {
            stack[++top] = p->next;
            stack[++top] = high;
        }
    }

}


//Funcion para pedir input al usuario, generar una fecha con esos inputs, llamar binary search y llamar funcion para generar resutlados
//Se manda llamar desde main
void DoubleLinkedList::searchLog(){

    std::string monthNumbers [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    std::string firstMonth, secondMonth, firstDay, secondDay, firstHour, secondHour;
    int firstMonthNumber, secondMonthNumber;

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

    //Find out the number month to use in date ( 0 - 11 )
    for(int i = 0; i < 12; i++){
        if(monthNumbers[i] == firstMonth) firstMonthNumber = i;
        if(monthNumbers[i] == secondMonth) secondMonthNumber = i;
    }

    //If number less than ten add 0 to number string
    firstMonthNumber < 10 ? firstMonth = "0"+std::to_string(firstMonthNumber) : firstMonth = std::to_string(firstMonthNumber);
    secondMonthNumber < 10 ? secondMonth = "0"+std::to_string(secondMonthNumber) : secondMonth = std::to_string(secondMonthNumber);

    //Turns input data into dates type tm
    tm date1 = this->dateInput(firstMonth, firstDay, firstHour);
    tm date2 = this->dateInput(secondMonth, secondDay, secondHour);

    //Gets Node values of the first range and the second range of the user input
    firstSearchVal = this->binarySearch(head, date1);
    secondSearchVal = this->binarySearch(head, date2);

    //This calls function to print the search result and create text file
    this->printSearch(firstSearchVal, secondSearchVal);

}


//Funcion para generar datos tipo tm del input del usuario - manda llamar en searchLogs
tm DoubleLinkedList::dateInput(std::string month, std::string day, std::string hour){
    time_t date1;
    tm date;

    //Se usó el valor 121 porque ese es el valor que tienen los nodos de la lista - creo que se crea default usando el localtime
    std::string year = "121";
    std::string tempDateTime = year + day + month + hour + "00" + "00";

    //Aqui genera un const char con la fecha y el sscanf lo interpreta y guarda los datos en la variable tipo tm date
    const char* dateTime = tempDateTime.c_str();
    sscanf(dateTime,"%3d%2d%2d%2d%2d%2d",&date.tm_year,&date.tm_mday,&date.tm_mon,&date.tm_hour,&date.tm_min,&date.tm_sec);
    return date;
}


//Funcion para encontrar la mitad de una sección de una lista - manda llamar en binarySearch
Node* DoubleLinkedList::middle(Node* front, Node* back){
    //The list is not empty
    if (front == nullptr){
        return nullptr;
    }

     Node* slow = front; //This one goes one by one
     Node* fast = front -> next; //This one is 2 ahead of slow - when reaches last then slow is in middle

    while (fast != back){
        fast = fast -> next;
        if (fast != back){
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    return slow;
}


//Funcion para la búsqueda de los valores que ingresa el usuario - manda llamar en searchLogs
Node* DoubleLinkedList::binarySearch(Node* headInput, tm value) {
     Node* start = headInput;
     Node* last = tail;

    while (last == nullptr || last != start){
        // Find middle
        Node* mid = middle(start, last);

        // If middle is empty
        if (mid == nullptr){
            return nullptr;
        }


        //midPrt(tm) = mid(Node*)->data(SearchLog*)->data_obj(tm)
        //data_obj es el objeto tipo tm que tiene los valores especificos de la fecha como mes, dia, hora, etc. Se usa para comparar si el nodo es "igual".
        tm midPtr = mid->data->data_obj;
        // mid->data is time_t same as value from search -
        if ((midPtr.tm_mon == value.tm_mon) && (midPtr.tm_mday == value.tm_mday) && (midPtr.tm_hour == value.tm_hour) && (midPtr.tm_min >= value.tm_min-2 || midPtr.tm_min <= value.tm_min+2)){
            return mid;
            //mktime(&value) returns the epoch value of that tm object
        } else if (mid->data->epoch <= mktime(&value)){
            start = mid -> next;
        } else {
            last = mid;
        }
    }

    // value not found
    return nullptr;
}


//Funcion para imprimir el resultado de la búsqueda - se llama dentro de searchLogs
void DoubleLinkedList::printSearch(Node* firstNode, Node* secondNode) {
    std::vector<std::string> stringResult;

    if (firstNode == nullptr || secondNode == nullptr){
        std::cout << "Nothing to display " << std::endl;
    } else {
        Node* current = head;
        Node* last = tail;

        //Busca el primer Nodo de la busqueda del usario
        while (current->next != firstNode) {
            current = current->next;
        }

        //Cuando acaba primer while estamos dentro del rango de resultados de la busqueda del usuario
        //Guarda valores de la búsqueda del usuario y los imprime en consola
        while(current != secondNode && current->next != nullptr){
            std::cout << current->data->log << "\n";
            stringResult.push_back(current->data->log);
            current = current->next;
        }

        //Agregamos el utlimo valor del nodo que no se agrega dentro del while pasado
        stringResult.push_back(current->data->log);
    }
    std::cout << std::endl;

    //Llamamos funcion para hacer el archivo
    searchResult = stringResult;
    this->searchFile();
}


//Funcion para crear archivo con valores de busqueda - se llama en printSearch
void DoubleLinkedList::searchFile(){
    //searchResult es un valor de la clase que se guarda en pritnSearch y contiene un vector de strings con las respuestas de la busqueda
    std::ofstream resultFile("search_result.txt");
    if(!resultFile) std::cout << "Algo no sirve \n";
    if(resultFile.is_open()){
        for(std::string el : searchResult){
            resultFile << el + "\n";
        }
        resultFile.close();
    }

}


//Funciones para crear la bitacora con los datos ordenados - se llama en orderLogs
void DoubleLinkedList::createBitacora() {
    std::ofstream bitacora("final_bitacora.txt");
    if(!bitacora) std::cout << "Algo no sirve \n";
    if(bitacora.is_open()){
        if (head == nullptr || tail == nullptr){
            std::cout << "Nothing to display " << std::endl;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                bitacora << current->data->log + "\n";
                current = current->next;
            }
        }
        bitacora.close();
    }
}