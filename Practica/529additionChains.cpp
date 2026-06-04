#include <iostream>
#include <algorithm>
using namespace std;

// Variables globales
int n;              // Numero objetivo, al que queremos llegar
int cadena[100];    // Almacena la Addition Chain
int limite;         // Maxima profunidad permitida

/// @brief Funcion principal de backtracking, completar la cadena hasta llegar a n
/// @param pos Posicion actual
/// @return Booleano indicando
bool buscar(int pos){
    int actual=cadena[pos]; // Obtenemos el valor actual de la cadena
    // Si ya llegamos al límite de pasos, caso base
    if(pos==limite){ // verificamos si el último número es n.
        if(actual==n){
            return true;
        }else{
            return false;
        }
    }

    /*
        Poda:
        Si aunque dupliquemos el número actual en todos los pasos restantes
        no llegamos a n, este camino no sirve.
    */
    int maximo=actual;              // Numero mas grande actual
    int pasosRestantes=limite-pos;  // Pasos restantes

    // Simulamos mejor caso posible, el mayor + el mayor
    for(int i=0;i<pasosRestantes;i++){
        maximo=maximo*2; // Lo mas rapido es sumar m + m
    }

    // Poda, si ni yendo de mayor en mayor seguimos sin acercarnos al objetivo, descartamos esta rama
    if(maximo<n){ 
        return false;
    }


    int candidatos[10000]; // Guardara todos los posibles numeros que podemos agregar
    int cantidad=0;
    bool usado[10001];     // Para evitar guardar el mismo numero

    // Inicializamos usado en false
    for(int i=0;i<=10000;i++){
        usado[i]=false;
    }

    // Recorremos todos los numeros existentes de la cadena
    /* 1 2 4 5
        5+5
        5+4
        5+2
        5+1

        4+4
        4+2
        4+1

        2+2
        2+1

        1+1
    */
    for(int i=pos;i>=0;i--){
        for (int j=i;j>=0;j--){
            int suma=cadena[i]+cadena[j]; // Creamos la suma, generando un nuevo numero
            if(suma>actual && suma<=n && usado[suma]==false){ // Validamos, debe crecer && es menor al objetivo && no hay duplicados
                // Guardamos el candidato
                usado[suma]=true; 
                candidatos[cantidad]=suma;
                cantidad++;
            }
        }
    }

    // Ordenamos de mayor a menor para llegar más rápido a n
    sort(candidatos,candidatos+cantidad,greater<int>()); // Mayor prioridad a los mayores porq buscamos la ruta mas corta

    // Probamos cada candidato
    for(int i=0;i<cantidad;i++){ // Explora todas las opciones disponibles
        cadena[pos+1]=candidatos[i]; // Agrega la 
        if(buscar(pos+1)==true){ // ¿Puedo completar la cadena desde aqui?
            return true;
        }
    }
    return false;
}

int main(){
    while(cin>>n){
        if(n==0){
            break;
        }

        if(n==1){
            cout<<"1"<<endl;
            continue;
        }

        cadena[0]=1;

        /*
            Probamos con límite 0, 1, 2, 3...
            hasta encontrar la cadena más corta.
        */
        for (limite = 0; ; limite++) {
            if (buscar(0) == true) {
                for (int i = 0; i <= limite; i++) {
                    if (i > 0) {
                        cout << " ";
                    }
                    cout << cadena[i];
                }
                cout << endl;
                break;
            }
        }
    }

    return 0;
}