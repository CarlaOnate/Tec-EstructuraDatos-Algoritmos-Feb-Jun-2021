//
// Created by Carla Onate on 08/02/21.
//

#include <iostream>
using namespace std;

template <class T>
T suma(T n1, T n2, T n3){
    return n1 + n2 +n3;
}

template <class D>
D sumaFrac(D n1, D n2, D d1, D d2){
    return (n1 + n2)/(d1 + d2);
}

//Todo: Make clase fraction separate form main and sum those fractions with a template

int exampleMain() {
    int a = 2, b = 10, c = 4;
    double a1 = 1.1, a2 = 2.2, a3 = 3.3;
    T doubleSum = suma(a1,a2,a3);
    T intSum = suma(a,b,c);
}
