//
// Created by Carla Onate on 08/02/21.
//

#ifndef MAIN_CLION_SCHOOLNOTES_LISTA_H
#define MAIN_CLION_SCHOOLNOTES_LISTA_H

#include <vector>
#include "iostream"
using namespace std;

const int MAX = 100;

template<class T> //Review: Declaring template var to use in class
class Lista {
private:
    vector<T> listaDatos;
    int size;
public:
    Lista();
    bool insert(T);
    bool erase();
    T getData(int);
    int getSize();
    void print();

};


#endif //MAIN_CLION_SCHOOLNOTES_LISTA_H
