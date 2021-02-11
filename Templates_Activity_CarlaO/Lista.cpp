//
// Created by Carla Onate on 08/02/21.
//

#include "Lista.h"

//bool insert(T); //Todo: Coloca valor al final del vector
//bool erase(); //Todo: Despliega utlimo elemento de la lista y lo borra, sino pone "NO HAY ELEMENTOS"
//T getData(int); //Todo: Recibe index y regresa dato en esa posicion, validacion de input.
//int getSize(); //Todo: Regresa size del vector
//void print(); //Todo: Imprime lista de datos, uno por uno - formato en notion

//Todo: Hnalde exceptions - don't remember how

template<class T> Lista<T>::Lista(){
    size = 0;
}

template<class T> int Lista<T>::getSize() {
    return listaDatos.size();
}

template<class T> bool Lista<T>::insert(T value) {
    listaDatos.push_back(value);
    return true;
}

template<class T> bool Lista<T>::erase() {
    cout << listaDatos[this->getSize()-1] << endl;
    listaDatos.pop_back();
    return true;
}

template<class T> T Lista<T>::getData(int index) {
    int size = this->getSize();
    if(index > 0 && index < size){
        return listaDatos[int]
    }
}

template<class T> void Lista<T>::print() {
    int index = 0;
    for(T data : listaDatos){
        cout << '[' << index << ']' << '-' << data << endl;
        index++;
    }
}


////
//// Created by Carla Onate on 10/02/21.
////
//
//#include "Lista.h"
//
////bool insert(T); //Todo: Coloca valor al final del vector
////bool erase(); //Todo: Despliega utlimo elemento de la lista y lo borra, sino pone "NO HAY ELEMENTOS"
////T getData(int); //Todo: Recibe index y regresa dato en esa posicion, validacion de input.
////int getSize(); //Todo: Regresa size del vector
////void print(); //Todo: Imprime lista de datos, uno por uno - formato en notion
//
//
//template<class T> Lista<T>::Lista(){
//    cout << "Lista called" << endl;
//    size = 0;
//}
//
//template<class T> int Lista<T>::getSize() {
//    return listaDatos.size();
//}
//
//template<class T> bool Lista<T>::insert(T value) {
//    //Todo: Missing exception
//    listaDatos.push_back(value);
//    return true;
//}
//
//template<class T> bool Lista<T>::erase() {
//    cout << listaDatos[this->getSize()-1] << endl;
//    if(this->getSize() > 0){
//        //Todo: Missing exception
//        listaDatos.pop_back();
//        return true;
//    } else {
//        cout << "List is empty, nothing to delete" << endl;
//        return false;
//    }
//}
//
//template<class T> T Lista<T>::getData(int index) {
//    int size = this->getSize();
//    if(index > 0 && index < size){
//        return listaDatos[index];
//    } else {
//        cout << "Index not valid" << endl;
//    }
//}
//
//template<class T> void Lista<T>::print() {
//    if(this->getSize() == 0) {
//        cout << "List is empty, nothing to print" << endl;
//    } else {
//        int index = 0;
//        for(T data : listaDatos){
//            cout << '[' << index << ']' << '-' << data << endl;
//            index++;
//        }
//    }
//}