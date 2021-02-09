//
// Created by Carla Onate on 08/02/21.
//

#include "TemplateClassExample.h"

template<class T> Lista<T>::Lista() {
    size = 0;
}

template<class T> int Lista<T>::posicion(T data) {
    int index = -1;
    for(int i; i < size; i++){
        if(listaDatos[i] == data){
            index = i;
        }
    }
    return index;
}

template<class T> T Lista<T>::getElement(int i) {
    return listaDatos[i];
}

template<class T> int Lista<T>::getSize() {
    return listaDatos.size();
}

template<class T> bool Lista<T>::agrega(T data) {
    return listaDatos[this->getSize()+1];
}