#include <iostream>   // Permite usar cin y cout
#include <algorithm>  // Permite usar sort()
using namespace std; 

int main(){
    int num[3]; // Arreglo donde se almacenan los tres numeros

    // Lee los tres numeros de entrada
    for(int i=0;i<3;i++){
        cin>>num[i];
    }

    sort(num,num+3); // Ordena los numeros de menor a mayor
    string orden;    // Cadena que contiene el orden solicitado (ABC, CAB...)
    cin>>orden;

    // Recorre los tres caracteres de la cadena
    for(int i=0;i<3;i++){
        // Si la letra es A, imprime el menor numero
        if(orden[i]=='A'){
            cout<<num[0];
        }
        // Si la letra es B, imprime el número intermedio
        else if(orden[i]=='B'){
            cout<<num[1];
        }
        // Si la letra es C, imprime el mayor numero
        else{
            cout<<num[2];
        }
        // Imprime un espacio entre numeros, excepto después del último
        if(i!=2){
            cout<<" ";
        }
    }
    return 0; 
}