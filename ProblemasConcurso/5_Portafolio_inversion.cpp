#include <iostream>   // Permite usar cin y cout
using namespace std;  

int C,N;         // Capital objetivo y cantidad de ETFs
int precio[20];  // Arreglo con los precios de los ETFs
int respuesta=0; // Cantidad de combinaciones validas

// Funcion de backtracking
void bt(int pos,int suma){
    // Si la suma supera el capital, esta rama ya no sirve
    if(suma>C){
        return;
    }
    // Si ya se revisaron todos los ETFs
    if(pos==N){
        // Si la suma es exactamente el capital, se encontro una combinacion valida
        if(suma==C){
            respuesta++;
        }
        // Termina esta rama
        return;
    }

    // Caso 1: No comprar el ETF actual
    bt(pos+1,suma);
    // Caso 2: Comprar el ETF actual
    bt(pos+1,suma+precio[pos]);
}

int main(){
    // Lee el capital y la cantidad de ETFs
    cin>>C>>N;

    // Lee el precio de cada ETF
    for(int i=0;i<N;i++){
        cin>>precio[i];
    }

    // Inicia el backtracking desde el primer ETF con suma 0
    bt(0,0);
    // Imprime la cantidad de combinaciones encontradas
    cout<<respuesta<<endl;

    return 0; 
}