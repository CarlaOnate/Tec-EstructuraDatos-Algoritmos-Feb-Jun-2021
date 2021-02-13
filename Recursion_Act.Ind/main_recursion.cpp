#include <iostream>
using namespace std;

#include "Fibonacci.h"
#include "Bacteria.h"
#include "Interes.h"
#include "Potencia.h"



int main_recursion() {
    Fibonacci ex1;
    int number;
    cout << "Choose a number: " << endl;
    cin >> number;
    ex1.fibonacciIterativo(number);
    cout << ex1.fibonacciRecursivo(number) << endl;

    Bacteria ex2;
    int dias;
    cout << "Ingresa días " << endl;
    cin >> dias;
    cout << "Bacterias: " << ex2.bateriaIterativa(dias) << endl;
    cout << "Bacterias recursivas: " << ex2.bacteriaRecursiva(dias) << endl;

    Interes ex3;
    double monto;
    int meses;
    cout << "Ingrese monto y meses" << endl;
    cin >> monto, meses;
    cout << ex3.interesIterativo(meses, monto) << endl;
    cout << ex3.interesRecursivo(meses, monto) << endl;

    Potencia ex4;
    int x, y;
    cout << "Ingresa x" << endl;
    cin >> x, y;
    cout << ex4.potenciaIterativa(x,y) << endl;
    cout << ex4.potenciaRecursiva(x,y) << endl;


    return 0;
}
