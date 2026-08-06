#include <iostream> // Permite usar cin y cout
#include <string>   // Permite usar string y sus funciones
using namespace std;

int main(){
    int n;  // Cantidad de instrucciones
    cin>>n; // Lee la cantidad de instrucciones

    cin.ignore(); // Descarta el salto de linea que quedo despues de leer n

    string linea;                // Almacena cada instruccion
    string inicio="Simon says "; // Prefijo que debe tener una instruccion valida

    // Procesa las n instrucciones
    for(int i=0;i<n;i++){
        getline(cin,linea); // Lee la instruccion completa, incluyendo espacios

        // Verifica si la linea comienza exactamente con "Simon says "
        if(linea.substr(0,inicio.size())==inicio){
            // Imprime el resto de la instruccion, sin el prefijo
            cout<<linea.substr(inicio.size())<<"\n";
        }
    }

    return 0;
}