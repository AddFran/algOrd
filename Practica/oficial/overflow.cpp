#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;


bool verificar(string s){
    return s.length()>10 || (s.length()==10 && s>"2147483647");
}

int main(){
    string num1, num2;
    char signo;

    while(cin>>num1>>signo>>num2){
        cout<<num1<<" "<<signo<<" "<<num2<<endl;
        if(verificar(num1))
            cout<<"first number too big"<<endl;
        if(verificar(num2))
            cout<<"second number too big"<<endl;

        long double a=stold(num1);
        long double b=stold(num1);

        switch(signo){
            case '+':
                if(a+b>INT_MAX)
                    cout<<"result too big"<<endl;
                break;
            case '*':
                if(a*b>INT_MAX)
                    cout<<"result too big"<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}