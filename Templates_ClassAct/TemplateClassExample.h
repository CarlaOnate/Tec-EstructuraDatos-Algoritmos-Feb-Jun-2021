//
// Created by Carla Onate on 08/02/21.
//

#ifndef MAIN_CLION_SCHOOLNOTES_TEMPLATECLASSEXAMPLE_H
#define MAIN_CLION_SCHOOLNOTES_TEMPLATECLASSEXAMPLE_H

const int MAX = 20;

template <class T>
class Lista {
    private:
        int size;
        T listaDatos[MAX];
    public:
        Lista();
        bool agrega(T);
        int getSize();
        T getElement(int i);
        int posicion(T);
};


#endif //MAIN_CLION_SCHOOLNOTES_TEMPLATECLASSEXAMPLE_H
