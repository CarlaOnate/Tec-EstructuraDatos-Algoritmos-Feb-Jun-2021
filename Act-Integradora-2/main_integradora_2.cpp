#include <iostream>
#include "DoubleLinkedList_Server.h"

/*
 * En este archivo se manda a llamar el constructor de DoubleLinkedList que es el que llama las funciones pertinentes para generar la lista.
 * La funciones de serarch log es la que se corre despues de ordenar los datos de la lista para pedir input al usuario y hacer la busqueda
 * asi como generar los dos archivos de texto.
 */

int main() {

    DoubleLinkedList server = DoubleLinkedList();
    server.searchLog();
    return 0;
}
