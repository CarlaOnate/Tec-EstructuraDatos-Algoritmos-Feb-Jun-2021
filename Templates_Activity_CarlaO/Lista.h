//
// Created by Carla Onate on 08/02/21.
//

#ifndef MAIN_CLION_SCHOOLNOTES_LISTA_H
#define MAIN_CLION_SCHOOLNOTES_LISTA_H

#include <vector>
#include "iostream"
using namespace std;

const int MAX = 100;

template<class T>
class Lista {
private:
    vector<T> listaDatos;
    int size;
public:
    Lista<T>();
    bool insert(T); //Todo: Coloca valor al final del vector
    bool erase(); //Todo: Despliega utlimo elemento de la lista y lo borra, sino pone "NO HAY ELEMENTOS"
    T getData(int); //Todo: Recibe index y regresa dato en esa posicion, validacion de input.
    int getSize(); //Todo: Regresa size del vector
    void print(); //Todo: Imprime lista de datos, uno por uno - formato en notion

};


#endif //MAIN_CLION_SCHOOLNOTES_LISTA_H
