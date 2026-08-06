#include <iostream>
using namespace std;

int fibonacci(int numero){
    if(numero<=2)
        return 1;
    return fibonacci(numero-1)+fibonacci(numero-2);
}

int main(){
    cout<<fibonacci(6);
    return 0;
}