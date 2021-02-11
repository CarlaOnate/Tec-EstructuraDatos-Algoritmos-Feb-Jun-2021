//
// Created by Carla Onate on 11/02/21.
//

#include "Lista.h"

template<class T> Lista<T>::Lista(){
    cout << "Lista called" << endl;
    size = 0;
}

template<class T> int Lista<T>::getSize() {
    return listaDatos.size();
}

template<class T> bool Lista<T>::insert(T value) {
    //Todo: Missing exception
    listaDatos.push_back(value);
    return true;
}

template<class T> bool Lista<T>::erase() {
    cout << listaDatos[this->getSize()-1] << endl;
    if(this->getSize() > 0){
        //Todo: Missing exception
        listaDatos.pop_back();
        return true;
    } else {
        cout << "List is empty, nothing to delete" << endl;
        return false;
    }
}

template<class T> T Lista<T>::getData(int index) {
    int size = this->getSize();
    if(index > 0 && index < size){
        return listaDatos[index];
    } else {
        cout << "Index not valid" << endl;
    }
}

template<class T> void Lista<T>::print() {
    if(this->getSize() == 0) {
        cout << "List is empty, nothing to print" << endl;
    } else {
        int index = 0;
        for(T data : listaDatos){
            cout << '[' << index << ']' << '-' << data << endl;
            index++;
        }
    }
}

//To work separately you have to tell the compiler at the end of this file which types are goint to be used
//Then the compiler can access those types and create the template: https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

template class Lista<int>;
template class Lista<string>;

