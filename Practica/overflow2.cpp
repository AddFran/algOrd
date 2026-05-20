/*
    Dado dos numeros num1 y num2, verificar si estos no exceden el limite impuesto junto al resultado de la opracion entre ambos
*/
#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

// Funcion para verificar que el "numero" no excede el limite
// Si s excede el limite establecido se retorna true, si s esta en el rango se retorna false
bool verificar(string s){
    return s.length()>10 || (s.length()==10 && s>"2147483647"); // Cada expresion indica lo que debe pasar para que s exceda el limite, basta con que uno sea verdadero para que s se haya excedido
    /*
        s.lenght()>10 : Obtenemos la longitud de s y si excede los 10 elementos consideramos directamente que es mayor al limite
        (s.length()==10 && s>"2147483647") : Si la longitud es igual a la del limite, entonces verificamos si s es mayor al limite ya que analizamos caracter por caracter, por ejemplo:
            "2147483648" > "2147483647"
            "2" = "2"
            "1" = "1"
            "4" = "4"
            ...
            "8" > "7"
        Por ende, "2147483648" es mayor a "2147483647".  
    */
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

        // stold() : Convierte un string de numeros a un double 
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