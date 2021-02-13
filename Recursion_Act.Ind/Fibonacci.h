//
// Created by Carla Onate on 12/02/21.
//

#ifndef ACT_IND_RECURSION_FIBONACCI_H
#define ACT_IND_RECURSION_FIBONACCI_H

#include <vector>
#include <iostream>

using namespace std;

class Fibonacci {
    private:
        vector<int> lista;
    public:
        void fibonacciIterativo(int);
        int fibonacciRecursivo(int);

};

#endif //ACT_IND_RECURSION_FIBONACCI_H
