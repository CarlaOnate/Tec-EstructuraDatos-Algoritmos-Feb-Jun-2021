#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int result;

    result = factorial(3);

    cout << result << endl;

    return 0;
}
