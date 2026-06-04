#include <iostream>
#include <algorithm>
using namespace std;

bool esta_ordenado(int arreglo[],int n){
    for(int i=0;i<n-1;i++){
        if(arreglo[i]>arreglo[i+1]){
            return false;
        }
    }
    return true;
}

int contar_caminos_minimos(int arreglo[],int n){
    if(esta_ordenado(arreglo,n)){
        return 1;
    }
    
    int contador=0;
    
    for(int i=0;i<n-1;i++){
        if(arreglo[i]>arreglo[i+1]){
            swap(arreglo[i],arreglo[i+1]);
            contador+=contar_caminos_minimos(arreglo,n);
            swap(arreglo[i],arreglo[i+1]);
        }
    }
    
    return contador;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    int case_num=1;
    
    while(cin>>n && n!=0){
        int arreglo[5]; 
        
        for(int i=0;i<n;i++){
            cin>>arreglo[i];
        }
        
        if(esta_ordenado(arreglo,n)){
            cout<<"There are 0 swap maps for input data set "<<case_num<<".\n";
        }else{
            int total=contar_caminos_minimos(arreglo,n);
            cout<<"There are "<<total<<" swap maps for input data set "<<case_num<<".\n";
        }
        case_num++;
    }
    
    return 0;
}