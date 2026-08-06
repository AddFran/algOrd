#include <iostream>   // Permite usar cin y cout
#include <string>     // Permite usar string
using namespace std; 

int R,C;                   // Cantidad de filas y columnas
string mapa[1000];         // Almacena el mapa
bool visitado[1000][1000]; // Indica si una celda ya fue visitada

// Movimientos posibles: arriba, abajo, izquierda y derecha
int df[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

// Funcion DFS para recorrer una isla completa
void dfs(int f,int c){
    // Marca la celda actual como visitada
    visitado[f][c]=true;
    // Recorre las cuatro direcciones posibles
    for(int i=0;i<4;i++){
        int nf=f+df[i]; // Calcula la nueva fila
        int nc=c+dc[i]; // Calcula la nueva columna

        // Verifica que la nueva posicion este dentro del mapa
        if(nf>=0 && nf<R && nc>=0 && nc<C){
            // Si es tierra y aun no fue visitada
            if(mapa[nf][nc]=='1' && !visitado[nf][nc]){
                dfs(nf,nc); // Continua recorriendo la misma isla
            }
        }
    }
}

int main(){
    // Lee las dimensiones del mapa
    cin>>R>>C;
    // Lee cada fila del mapa
    for(int i=0;i<R;i++){
        cin>>mapa[i];
    }

    int islas=0; // Contador de islas

    // Recorre todas las celdas del mapa
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            // Si encuentra tierra no visitada
            if(mapa[i][j]=='1' && !visitado[i][j]){
                islas++;  // Encontro una nueva isla
                dfs(i,j); // Marca toda la isla como visitada
            }
        }
    }

    // Imprimimos la cantidad de islas
    cout<<islas<<endl;

    return 0; 
}