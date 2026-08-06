#include <iostream> // Permite usar cin y cout
#include <string>   // Permite usar string
using namespace std;  

int main(){
    string jugadas; // Almacena la secuencia completa de anotaciones
    cin>>jugadas;   // Lee la secuencia

    int A=0; // Puntaje de Alicia
    int B=0; // Puntaje de Barbara

    // Recorre la cadena de dos en dos caracteres (Jugador + Puntos)
    for(int i=0;i<jugadas.size();i+=2){
        // Obtiene el jugador que anoto
        char jugador=jugadas[i];
        // Convierte el caracter '1' o '2' al entero 1 o 2
        int puntos=jugadas[i+1]-'0';
        // Suma los puntos al jugador correspondiente
        if(jugador=='A'){
            A+=puntos;
        }
        else{
            B+=puntos;
        }

        // Si ambos tienen al menos 10 puntos aplica la regla de ventaja de 2
        if(A>=10 && B>=10){
            // Si Alicia tiene ventaja de 2 o mas, gana
            if(A-B>=2){
                cout<<"A\n";
                return 0;
            }
            // Si Barbara tiene ventaja de 2 o mas, gana
            if(B-A>=2){
                cout<<"B\n";
                return 0;
            }
        }
        else{
            // Antes del 10-10, gana quien llegue primero a 11 puntos
            if(A>=11){
                cout<<"A\n";
                return 0;
            }
            // Antes del 10-10, gana quien llegue primero a 11 puntos
            if(B>=11){
                cout<<"B\n";
                return 0;
            }
        }
    }

    return 0; 
}