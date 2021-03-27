#include <iostream>
#include "LinkedList.h"

template <class T>
void menu(LinkedList<T>& list, int type){
    int menuOption = 0;
    int valueInput = 0;
    int updateVal = 0;
    char valueInputChar;
    char updateValChar;

    std::cout << "Menu \n";
    std::cout << "\t 1- Agregar Elemento \n";
    std::cout << "\t 2- Borrar Elemento \n";
    std::cout << "\t 3- Actualizar Elemento \n";
    std::cout << "\t 4- Leer Elemento \n";
    std::cout << "\t 5- Buscar Elemento \n";
    std::cin >> menuOption;

    if(menuOption == 1){
        std::cout << "Inserte valor:    ";
        type == 1 ? std::cin >> valueInput : std::cin >> valueInputChar;
        std::cout << "addFirst - 1     |    addLast: 2:     ";
        std::cin >> menuOption;

        menuOption == 1 ? list.addFirst(valueInput) : list.addLast(valueInput);
        list.display();
    } else if (menuOption == 2){
        std::cout << "Borrar por valor - 1     |    Borrar por posición: 2:     ";
        std::cin >> menuOption;
        menuOption == 1 ? std::cout << "Inserte valor:    " : std::cout << "Inserte posición:    ";
        if(type == 1){
            std::cin >> valueInput;
            menuOption == 1 ? list.deleteData(valueInput) : list.deleteAt(valueInput);
        } else {
            std::cin >> valueInputChar;
            menuOption == 1 ? list.deleteData(valueInputChar) : list.deleteAt(valueInputChar);
        }
        list.display();
    } else if (menuOption == 3){
        std::cout << "Actualizar por valor - 1     |    Actualizar por posición: 2:     ";
        std::cin >> menuOption;
        menuOption == 1 ? std::cout << "Inserte valor a actualizr:    " : std::cout << "Inserte posición a actualizar:    "; //Insert value to search for and then update
        if(menuOption == 1){
            type == 1 ? std::cin >> valueInput : std::cin >> valueInputChar;
        } else if (menuOption == 2){
            std::cin >> valueInput;
        }
        std::cout << "Inserte valor para actualizar:    "; //Insert value to update found value
        if(type == 1){
            std::cin >> updateVal;
            menuOption == 1 ? list.updateData(valueInput, updateVal) : list.updateAt(valueInput, updateVal);
        } else {
            std::cin >> updateValChar;
            menuOption == 1 ? list.updateData(valueInput, updateValChar) : list.updateAt(valueInput, updateValChar);
        }
        list.display();
    } else if (menuOption == 4){
        std::cout << "Leer usando [] - 1     |    Leer con función: 2:     ";
        std::cin >> menuOption;
        std::cout << "Inserte posición:    ";
        type == 1 ? std::cin >> valueInput : std::cin >> valueInputChar;
        menuOption == 1 ? std::cout << "Elemento " << valueInput << ": " << list[valueInput]->data : std::cout << "Elemento " << valueInput << ": " << list.getData(valueInput);
    } else if (menuOption == 5){
        std::cout << "Inserte valor a buscar:    ";
        type == 1 ? std::cin >> valueInput : std::cin >> valueInputChar;

        std::cout << "Posicion elemento " << valueInput << ": ";
        type == 1 ? std::cout << list.findData(valueInput) : std::cout << list.findData(valueInputChar);

        list.display();
    }

}


int main() {
    bool random;
    int typeOption = 0;
    char randomInput;
    int size = 0;
    int valueInput = 0;

//    Data to create list
    std::cout << "Tamaño de la lista:    ";
    std::cin >> size;
    std::cout << "Tipo int - 1     |   Tipo char - 2:   ";
    std::cin >> typeOption;
    std::cout << "Crear lista aleatoria: Y  / N:       ";
    std::cin >> randomInput;
    random = randomInput == 'Y';

    if(typeOption == 1){
        LinkedList<int> listInt(size);
        random ? listInt.generateRandom(typeOption) : listInt.createLinkedList(typeOption);
        menu(listInt, typeOption);
    } else if (typeOption == 2){
        LinkedList<char> listChar(size);
        random ? listChar.generateRandom(typeOption) : listChar.createLinkedList(typeOption);
        menu(listChar, typeOption);
    }

//No pude hacer que funcionará la opción 6 en el menu, pero para que pudiera probarlo lo puse aca afuera :)
    std::cout << "\n \tOpcion 6: probar = operator \n";
    std::cout << "Ingrese tamaño nueva lista:    ";
    std::cin >> valueInput;


    if(typeOption == 1){
        LinkedList<int> listInt(5);
        std::cout << "List before: ";
        listInt.generateRandom(typeOption);

        LinkedList<int> list2(valueInput);
        std::cout << "List 2: ";
        list2.generateRandom(1);

        listInt = list2;

        std::cout << "List after: ";
        listInt.display();

    } else if (typeOption == 2){
        LinkedList<char> listChar(5);
        LinkedList<char> list2(valueInput);

        std::cout << "List before: ";
        listChar.generateRandom(typeOption);
        std::cout << "List 2: ";
        list2.generateRandom(typeOption);

        listChar = list2;

        std::cout << "List after: ";
        listChar.display();
    }





//Review: Test code of each function down here :))

//    std::cout << "Tipo int: 1 - Tipo char: 2" << "\n";
//    std::cin >> typeOption;
//
//    std::cout << "Generar LinkedList random: Y / N" << "\n";
//    std::cin >> randomInput;
//    random = randomInput == 'Y';
//
//    std::cout << "Tamaño lista: " << "\n";
//    std::cin >> size;
//
//    LinkedList<int> list(size);
//    LinkedList<int> list2(size+2);
//    list.generateRandom(typeOption);
//    list2.createLinkedList(typeOption);
//    //Todo: n value needs to be updated if there is any change but in add first and add list is removed because it causes infinite cycle
//
//    std::cout << "\n";
//    std::cout << "Add First and Last\n";
//    //Review: Tested and works!
//
//    list.addFirst(111);
//    list.addLast(222);
//    list.display();
//
//    std::cout << "\n";
//    std::cout << "Find Data \n";
//    //Review: Tested and works!
//
//    std::cout << "Find 222 in list: " << list.findData(222) << "\n";
//    std::cout << "Find 20 in list: " << list.findData(20) << "\n";
//    list.display();
//
//    std::cout << "\n";
//    std::cout << "Delete Data, Ate\n";
//    //Review: Tested and works!
//
//    if(list.deleteData(111)){
//        std::cout << "Delete 111 data: " << "\n";
//    } else {
//        std::cout << "Delete 111 no se pudo" << "\n";
//    }
//
//    if(list.deleteAt(3)){ //3 pos inside list size
//        std::cout << "Delete pos 3 data: " << "\n";
//    } else {
//        std::cout << "Delete pos 3 no se pudo" << "\n";
//    }
//
//    if(list.deleteAt(10)){ //10 pos outside list size
//        std::cout << "Delete pos 10 data: " << "\n";
//    } else {
//        std::cout << "Delete pos 10 no se pudo" << "\n";
//    }
//
//    list.display();
//
//    std::cout << "\n";
//    std::cout << "Get Data\n";
//    //Review: Tested and works!
//
//    std::cout << "Get data pos 3: " << list.getData(3) << "\n";
//    std::cout << "Get data pos 10: " << list.getData(10) << "\n";
//
//
//    std::cout << "\n";
//    std::cout << "Update Data, At\n";
//    //Review: Tested and works!
//
//    list.updateData(222, 456);
//    list.updateData(101, 123);
//    list.updateAt(1, 234);
//    list.updateAt(10, 345);
//    list.display();
//
//    std::cout << "\n";
//    std::cout << "Overload []\n";
//    //Review: Tested and works!
//
//    std::cout << "List el in pos 4: " << list[4]->data << "\n";
//    std::cout << "List el in pos 1: " << list[1]->data << "\n";
//    list[2]->setData(1111);
//    list.display();
//
//    std::cout << "\n";
//    std::cout << " Overload =\n";
//    //Review: Tested and works!
//
//    list = list2;
//
//    std::cout << "\n";
//    std::cout << "\n";
//
//    std::cout << "Final display: \n";
//    list.display();
//    list2.display();


}
