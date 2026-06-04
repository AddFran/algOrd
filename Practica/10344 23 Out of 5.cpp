#include <iostream>
using namespace std;

// Variables globales
int a[5];       // Guarda los 5 numeros originales ingresados
int usado[5];   // Indica los numeros que ya fueron utilizados al construir la permutacion
int p[5];       // Guarda la permutacion actual de numeros
bool posible;   // true si se encontro una solucion, false si no

/// @brief Prueba todas las combinaciones posibles de operadores
/// @param pos Indica en que posicion de p[] estamos
/// @param resultado Guarda el resultado acumulado hasta el momento
void operar(int pos,int resultado){ 
    // Caso base
    if(pos==5){ // Ya usamos los 5 numeros?
        if(resultado==23) // Ya que usamos todos, el resultado es 23?
            posible=true; // Encontramos la solucion
        return; // Si no F
    }
    // Llamamos recursivamente a las 3 operaciones posibles con el numero que le sigue
    operar(pos+1,resultado+p[pos]);
    operar(pos+1,resultado-p[pos]);
    operar(pos+1,resultado*p[pos]);
    // Con esto se genera una especie de arbol de posibilidades
    /*
                        |---1 + 2 + 3 ...
            |---1 + 2 --|---1 + 2 * 3 ...
            |           |---1 + 2 - 3 ...
            |
            |           |---1 * 2 + 3 ... 
        1 --|---1 * 2 --|---1 * 2 * 3 ...
            |           |---1 * 2 - 3 ...
            |
            |           |---1 - 2 + 3 ...
            |---1 - 2 --|---1 - 2 * 3 ...
                        |---1 - 2 - 3 ...
    */
}

/// @brief Genera todas las permutaciones posibles de los 5 numeros, osea, todas las combinacione posibles  
/// @param pos Indica la posicion de p[] en la que estamos
void permutar(int pos){ // Posicion que vamos a llenar
    // Caso base
    if(pos==5){ // Ya llegamos formamos la permutacion completa
        // Con la permutacion ya hecha ( p[] = {a,b,c,d,e} )...
        operar(1,p[0]); // Procedemos a probar todas las combinaciones posibles de operaciones sobre esta permutacion
        // Recuerda, el primer numero (p[0]) es el primer resultado, ya despues se va acumulando
        return;
    }

    // Recorremos todos los numeros
    for(int i=0;i<5;i++){
        // En usado[], indicamos que el numero fue usado con un 1, mientras que no fue usado con un 0
        if(!usado[i]){ // Si el numero aun no fue usado...
            usado[i]=1; // Marcamos el numero como usado
            p[pos]=a[i]; // Obtenemos el numero y lo guardamos en la permutacion actual
            permutar(pos+1); // Llenamos la siguiente posicion
            usado[i]=0; // Hacemos backtracking
        }
    } 
    /*
        a     = {1,2,3,4,5}
        usado = {1,0,1,0,0}
        p     = {1,3,2,5,4}
    */
    /*                                |-- 1,2,3,4 --|-- 1,2,3,4,5 -> operar({1,2,3,4,5})
                          |-- 1,2,3 --|
                          |           |-- 1,2,3,5 --|-- 1,2,3,5,4
                          |
                          |           |-- 1,2,4,3 --|-- 1,2,4,3,5
                |-- 1,2 --|-- 1,2,4 --|
                |         |           |-- 1,2,4,5 --|-- 1,2,4,5,3
                |         |
                |         |           |-- 1,2,5,3 --|-- 1,2,5,3,4
                |         |-- 1,2,5 --|
                |                     |-- 1,2,5,4 --|-- 1,2,5,4,3
                |-- 1,3 ...
        |-- 1 --|-- 1,4 ...
        |       |-- 1,5 ...
        |-- 2 ...
    [] -|-- 3 ...
        |-- 4 ...
        |-- 5 ...

    */
}

int main(){
    while(true){
        int suma=0;

        for(int i=0;i<5;i++){
            cin>>a[i];
            suma+=a[i];
        }

        if(suma==0)
            break;

        posible=false;

        for (int i=0;i<5;i++)
            usado[i]=0; // Inicializamos usado con puros 0, ya que aun no usamos ninguno

        permutar(0);

        if(posible)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }

    return 0;
}