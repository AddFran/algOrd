/*
    Problema del caballo

    El objetivo es encontrar un recorrido valido de un caballo de ajedrez sobre un tablero, de tal forma que:
     - El caballo visite todas las casillas solo una vez
     - Se respete el movimiento del caballe de ajedrez (en forma de L)
    No buscamos el camino mas corto ni nada asi, buscamos responder si existe un recorrido que permita visitar todas las casillas una sola vez

    Restricciones
     - No podemos salir del tablero
     - No visitar una casilla mas de una vez
    
    Resolver con backtracking
*/

#include <iostream>
using namespace std;

const int N = 5;
int tablero[N][N];

int movFila[8]={-2,-2,-1,-1,1,1,2,2};
int movColumna[8]={-1,1,-2,2,-2,2,-1,1};

bool esValido(int fila,int columna){
    if(fila<0 || fila>=N)
        return false;
    if(columna<0 || columna>=N)
        return false;
    if(tablero[fila][columna]!=0)
        return false;
    return true;
}

bool caballo(int fila,int columna,int visitadas){
    if(visitadas == N*N){
        return true;
    }

    for(int i=0;i<8;i++){
        int nuevaFila=fila+movFila[i];
        int nuevaColumna=columna+movColumna[i];

        if(esValido(nuevaFila,nuevaColumna)){
            // Tomar decision
            tablero[nuevaFila][nuevaColumna]=visitadas+1;

            // Recursion
            if(caballo(nuevaFila,nuevaColumna,visitadas+1)){
                return true;
            }

            // backtracking
            tablero[nuevaFila][nuevaColumna]=0;
        }
    }
    return false;
}

void imprimirTablero(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout << endl;
    }
}

int main(){
    // Inicializar tablero
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tablero[i][j]=0;
        }
    }

    // Posición inicial
    tablero[0][0]=1;

    if(caballo(0,0,1)){
        cout<<"Se encontro un recorrido:"<<endl;
        imprimirTablero();
    }
    else{
        cout<<"No existe solucion"<<endl;
    }

    return 0;
}