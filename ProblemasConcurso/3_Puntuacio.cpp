#include <iostream>   // Permite usar cin y cout
#include <map>        // Permite asociar informacion a cada problema
#include <string>     // Permite usar string
using namespace std; 

int main(){
    map<char,int>intentos;  // Guarda la cantidad de intentos incorrectos por problema
    map<char,bool>resuelto; // Indica si un problema ya fue resuelto

    int resueltos=0;   // Cantidad de problemas resueltos
    int tiempoTotal=0; // Tiempo total con penalizaciones

    int minuto;       // Minuto del envio
    char problema;    // Letra del problema
    string resultado; // Resultado del envio

    // Procesa todos los envios hasta encontrar -1
    while(cin>>minuto){
        // Si el minuto es -1, termina la entrada
        if(minuto==-1){
            break;
        }
        // Lee la letra del problema y el resultado del envio
        cin>>problema>>resultado;
        // Si el problema ya fue resuelto, ignora este envio
        if(resuelto[problema]){
            continue;
        }
        // Si el envio fue correcto
        if(resultado=="right"){
            resuelto[problema]=true;                    // Marca el problema como resuelto         
            resueltos++;                                // Incrementa la cantidad de problemas resueltos
            tiempoTotal+=minuto+intentos[problema]*20;  // Suma el tiempo del envio mas la penalizacion por intentos incorrectos
        }
        else{
            // Si el envio fue incorrecto, aumenta el contador de intentos
            intentos[problema]++;
        }
    }

    // Imprime la cantidad de problemas resueltos y el tiempo total
    cout<<resueltos<<" "<<tiempoTotal<<"\n";

    return 0;
}