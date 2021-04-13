//
// Created by Carla Onate on 09/04/21.
//

#ifndef ACT_INTEGRADORA_2_DOUBLELINKEDLIST_H
#define ACT_INTEGRADORA_2_DOUBLELINKEDLIST_H

#include "Node_Integradora_2.h"
#include <fstream>
#include <string>
#include <vector>


/*
 * Esta clase tiene la mayoría de las funciones que se piden en la actividad
 * Constructor - Lee el archivo de Texto y genera los Nodos que agrega a la lista usando addLast
 *
 * AddLast - Agrega al final de la lista un Nodo y acutaliza el valor de tail
 *
 * OrderLogs - Esta funcion llama al quick sort para hacer el ordenamieto - dentro de usa: swap, partition.
 * Acabando el quickSort llama a createBitacora para hacer la nueva bitacora ordenada.
 *
 * SearchLogs - Es la funciones que se llama desde main y pide al usuario inputs, esta llama la funcion dateInput para
 * crear fechas del input del usuario, luego esta fecha se le da al binary search para buscar el valor inicial y final del rango de búsqueda.
 *
 * Binary Search - Esta funcinon es la búsqueda binaria para listas doblemente ligadas, esta hace el uso de middle para encontrar el valor medio y hacer comparaciones.
 *
 * PrintSearch - Esta funcion lo que hace es imprimir el rango de datos de la bitacora que pidio el usuario. Esta llama a searchFile para crear el archivo con los resultados de la busqueda.
 *
 */


class DoubleLinkedList{
private:
    Node* head;

    Node* tail;
    int size = 0;
    Node* firstSearchVal;  //Used in user input section
    Node* secondSearchVal; //Used in user input section
    std::vector<std::string> searchResult; //Used in search result section

public:
    //Functions to generate list
    DoubleLinkedList();
    void addLast(std::string value);

    //Functions used to oder list and create new text file with ordered data
    void orderLogs();
    void quickSort();
    void swap(ServerLog*, ServerLog*);
    Node* partition(Node*, Node*);
    long findData(Node*);
    void createBitacora();

    //Functions to handle user input and turn to dates
    void searchLog();
    tm dateInput(std::string, std::string, std::string);

    //Functions to find user inputs in the list
    Node* binarySearch(Node* head, tm value);
    Node* middle(Node*, Node*);

    //Functions to print search result and make text file
    void printSearch(Node*, Node*);
    void searchFile();


};

#endif //ACT_INTEGRADORA_2_DOUBLELINKEDLIST_H
