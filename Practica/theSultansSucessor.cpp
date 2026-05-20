/*
    Basicamente el objetivo es colocar sobre unb tablero de ajedrez 8 reinas, tal que ninguna de estas amenaze con comerse
    a otra reina, solo que ahora cada casilla del tablero tiene una puntuacion, cada reina colocada sumara la puntuacion de la 
    casilla a un total. Deberemos buscar cual es la combinacion de posiciones de las reinas que suman la mayor cantidad de puntos
    en el tablero, recuerda que al inicio ingresaremos k, que sera el numero de tableros que existiran
*/

#include <iostream>
#include <iomanip>

using namespace std;

int tablero[8][8]; // Guardamos los valores del tablero

bool columna[8]; // Para verificar si la columna ya esta ocupada con una reina
bool diag1[15]; // Diagona \, lo mismo, para verificar si en una diagonal ya existe una reina
                // Usaremos fila - columna + 7 para la diagonal \ para identificar en que diagonal esta la posicion (fila,columna) 
bool diag2[15]; // Diagona /, lo mismo, para verificar si en una diagonal ya existe una reina
                // Usaremos fila + columna para la diagonal / para identificar en que diagonal esta la posicion (fila,columna) 
int mejorSuma; // Para almacenar la mejor respuesta

// Funcion para el backtracking (si algo male sal, el algoritmo regresa un paso antes y prueba otra solucion)
void backtracking(int fila,int sumaActual){ // Recibe: En que fila estamos intentando colocar la reina | suma de las reinas colocadas hasta ahora
    // Si ya colocamos las 8 reinas, entonces estaremos en la fila 8
    if(fila==8){
        if(sumaActual>mejorSuma)
            mejorSuma=sumaActual; // Obtenemos la suma directamenete
        return;
    }

    // Intentar colocar reina en cada columna
    for(int col=0;col<8;col++){
        // Verificar si la posicion es valida, es decir, si la columna esta libre
        if(!columna[col] && !diag1[fila-col+7] && !diag2[fila+col]){ // columna libre? | diagonal libre? | otra diagonal libre
            // Si esta todo libre entonces marcamos posición ocupada
            columna[col]=true;
            diag1[fila-col+7]=true;
            diag2[fila+col]=true;

            // Continuar con la siguiente fila
            backtracking(fila+1,sumaActual+tablero[fila][col]); // Siguiente fila | argegamos el valor de la casilla donde pusimos la reina

            // Deshacer cambios (backtracking)
            // Si salimos de la recursion es porque no encontramos una casilla libre, por ende debemos probar otra solucion
            columna[col]=false;
            diag1[fila-col+7]=false;
            diag2[fila+col]=false;
        }
    }
}

int main(){
    int k;
    cin>>k;

    while(k--){
        // Leer tablero
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>tablero[i][j];
            }
        }

        // Reiniciar estructuras
        for(int i=0;i<8;i++)
            columna[i]=false;
        for(int i=0;i<15;i++){
            diag1[i]=false;
            diag2[i]=false;
        }
        mejorSuma=0;

        // Buscar mejor solucion
        backtracking(0,0); // Iniciamos en la fila 0 con una suma de 0

        // Salida con ancho 5
        cout<<mejorSuma<<endl;
    }

    return 0;
}