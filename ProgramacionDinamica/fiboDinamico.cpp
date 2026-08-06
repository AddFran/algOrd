#include <iostream>
using namespace std;

long array[100]={0};

int fibonacci(int numero){
    if(numero<=2)
        return 1;

    if(array[numero]!=0)
        return array[numero];

    array[numero]=fibonacci(numero-1)+fibonacci(numero-2);

    return array[numero];
}

int main(){
    cout<<fibonacci(5)<<endl;
    for(int i=0;i<100;i++){
        cout<<i<<": "<<array[i]<<endl;
    }
    return 0;
}