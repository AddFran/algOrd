#include <iostream>
using namespace std;

int a=1;

const int N = 5; // Tamaño del tablero
int tablero[N][N]; // Tablero (inicialmente contendra todos 0)
    // Cada casilla del tablero contendra el orden en el cual el caballo visito dicha casilla, osea, el numero indicara "esta casilla fue visitada en el paso X"

// Movimientos posibles del caballo
// El caballo solo posee 8 movimientos validos en el ajedrez
// No son  8 posiciones, son 8 desplazamientos  
int movFila[8]={-2,-2,-1,-1,1,1,2,2}; // - es hacia arriba, + hacia abajo
int movColumna[8]={-1,1,-2,2,-2,2,-1,1}; // - es izquierda, + derecha   

/// @brief Funcion para verificar que no nos pasamos (true si el movimiento es valido, false si no lo es)
/// @param fila Casilla en la fila a la que queremos mover el caballo
/// @param columna Casilla en la columna a la que queremos mover el caballo
/// @return true si el movimiento es valido, false si no lo es
bool esValido(int fila,int columna){ 
    if(fila<0 || fila>=N) // Si la fila esta dentro del tablero
        return false;
    if(columna<0 || columna>=N) // Si la columna esta dentro del tablero
        return false;
    if(tablero[fila][columna]!=0) // Si la casilla ya fue visitada
        return false;
    return true;
}

void imprimirTablero(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout << endl;
    }
}

/// @brief Funcion principal para resolver el problema
/// @param fila Indica la fila actual donde se encuetra el caballo
/// @param columna Inidca la columna actual donde se encuentra el caballo
/// @param visitadas Indica cuantas casillas hemos visitado hasta el momento
/// @return true si ya recorrimos todo el tablero
bool caballo(int fila,int columna,int visitadas){
    // Caso base
    if(visitadas == N*N){
        return true;
    }

    // Bucle principal
    for(int i=0;i<8;i++){ // Una iteracion por cada movimiento del caballo
        // Calcular la nueva posicion del caballo o a donde saltaria (segun nuestro array)
        int nuevaFila=fila+movFila[i];
        int nuevaColumna=columna+movColumna[i];

        // Comporbamos si el movimiento es valido
        if(esValido(nuevaFila,nuevaColumna)){
            // Tomar decisión
            tablero[nuevaFila][nuevaColumna]=visitadas+1; // Guardamos el moviemiento

            if(a<=2){
                a++;
                imprimirTablero();
                cout<<endl;
            }
            //cout<<endl;

            // Llamada recursiva
            if(caballo(nuevaFila,nuevaColumna,visitadas+1)){
                return true;
            }

            // Backtracking
            tablero[nuevaFila][nuevaColumna]=0;
        }
    }
    return false;
}



int main(){
    // Inicializar tablero
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tablero[i][j]=0; // Todas las casillas son marcadas con 0
        }
    }

    // Posición inicial
    tablero[0][0]=1;

    if(caballo(0,0,1)){
        cout<<"Se encontro un recorrido"<<endl;
        imprimirTablero();
    }
    else{
        cout<<"No existe solucion"<<endl;
    }

    return 0;
}