#include <iostream>
using namespace std;

const int N=4;

int tablero[N][N];
bool columna[N];
bool diag1[2*N-1];
bool diag2[2*N-1];
bool encontrado;

void backtracking(int fila){
    if(fila==N){
        encontrado=true;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout<<tablero[i][j]<<" ";
            cout<<endl;
        }
        return;
    }

    for(int col=0;col<N;col++){
        if(!columna[col] && !diag1[fila-col+N-1] && !diag2[fila+col]){
            columna[col]=true;
            diag1[fila-col+N-1]=true;
            diag2[fila+col]=true;
            tablero[fila][col]=1;

            backtracking(fila+1);

            if(encontrado)
                return;

            tablero[fila][col]=0;
            columna[col]=false;
            diag1[fila-col+N-1]=false;
            diag2[fila+col]=false;
        }
    }
}

int main(){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tablero[i][j]=0;
        }
    }

    for(int i=0;i<N;i++)
        columna[i]=false;

    for(int i=0;i<2*N-1;i++){
        diag1[i]=false;
        diag2[i]=false;
    }

    encontrado=false;

    backtracking(0);

    if(!encontrado)
        cout<<"No existe solucion"<<endl;

    return 0;
}