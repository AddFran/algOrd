/*
    Dado dos numeros y un signo + o /, tal que tengan la siguiente forma:
        num1 + num2
    Indicar si uno de los numeros o el resultado de la operacion entre ambos da como resultado un numero mayor al valor maximo permitido
    por el tipo primitivo int
        int = (2^31)-1

*/

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    while(true){
        unsigned long long int num1;
        unsigned long long int num2;
        char signo;

        cin>>num1;
        cin>>signo;
        cin>>num2;

        cout<<num1<<" "<<signo<<" "<<num2<<endl;

        if(num1>INT_MAX)
            cout<<"num1 es muy grande"<<endl;
        if(num2>INT_MAX)
            cout<<"num2 es muy grande"<<endl;

        switch(signo){
            case '+':
                if(num1+num2>INT_MAX)
                    cout<<"resultado es muy grande"<<endl;
                break;
            case '*':
                if(num1*num2>INT_MAX)
                    cout<<"resultado es muy grande"<<endl;
                break;
            default:
                break;
        }

    }
    return 0;
}

/*

100 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
*/