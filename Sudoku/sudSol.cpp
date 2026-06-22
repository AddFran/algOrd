#include <iostream>
#define MAX 9
using namespace std;

int tablero[9][9];
bool fija[9][9];

bool EsValido(int fila,int col,int num){
    for(int i=0;i<9;i++){
        if(tablero[fila][i]==num){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(tablero[i][col]==num){
            return false;
        }
    }

    int inicioFila=(fila/3)*3;
    int inicioCol=(col/3)*3;

    for(int i=inicioFila;i<inicioFila+3;i++){
        for(int j=inicioCol;j<inicioCol+3;j++){
            if(tablero[i][j]==num){
                return false;
            }
        }
    }

    return true;
}

bool SolucionarSudoku(int fila,int col){
    if(fila==9){
        return true;
    }

    int sigFila=fila;
    int sigCol=col+1;

    if(sigCol==9){
        sigCol=0;
        sigFila++;
    }

    if(fija[fila][col]){
        return SolucionarSudoku(sigFila,sigCol);
    }

    for(int num=1;num<=9;num++){
        if(EsValido(fila,col,num)){
            tablero[fila][col]=num;
            if(SolucionarSudoku(sigFila,sigCol)){
                return true;
            }
            tablero[fila][col]=0;
        }
    }
    return false;
}

void Imprimir(){
    for(int fila=0;fila<9;fila++){
        if(fila%3==0 && fila!=0){
            cout<<"------+-------+------"<<endl;
        }
        for(int col=0;col<9;col++){
            if(col%3==0 && col!=0){
                cout<<"| ";
            }
            cout<<tablero[fila][col]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    freopen("in.txt","r",stdin);

    int pos_x,pos_y,valor;

    while(cin>>pos_x>>pos_y>>valor){
        tablero[pos_x-1][pos_y-1]=valor;
        fija[pos_x-1][pos_y-1]=true;
    }

    Imprimir();
    SolucionarSudoku(0,0);
    cout<<"========================"<<endl;
    Imprimir();

    return 0;
}