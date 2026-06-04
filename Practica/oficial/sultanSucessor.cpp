#include <iostream>
#include <iomanip>

using namespace std;

int tablero[8][8]; 
bool columna[8];
bool diag1[15]; 
bool diag2[15]; 
int mejorSuma; 

void backtracking(int fila,int sumaActual){ 
    if(fila==8){
        if(sumaActual>mejorSuma)
            mejorSuma=sumaActual;
        return;
    }

    for(int col=0;col<8;col++){
        if(!columna[col] && !diag1[fila-col+7] && !diag2[fila+col]){ 
            columna[col]=true;
            diag1[fila-col+7]=true;
            diag2[fila+col]=true;

            backtracking(fila+1,sumaActual+tablero[fila][col]);

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
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>tablero[i][j];
            }
        }

        for(int i=0;i<8;i++)
            columna[i]=false;
        for(int i=0;i<15;i++){
            diag1[i]=false;
            diag2[i]=false;
        }
        mejorSuma=0;

        backtracking(0,0);

        cout<<mejorSuma<<endl;
    }

    return 0;
}