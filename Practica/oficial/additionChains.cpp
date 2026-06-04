#include <iostream>
#include <algorithm>
using namespace std;

int n;             
int cadena[100];  
int limite;        

bool buscar(int pos){
    int actual=cadena[pos]; 
    if(pos==limite){ 
        if(actual==n){
            return true;
        }else{
            return false;
        }
    }

    int maximo=actual;             
    int pasosRestantes=limite-pos; 

    for(int i=0;i<pasosRestantes;i++){
        maximo=maximo*2; 
    }

    if(maximo<n){ 
        return false;
    }


    int candidatos[10000]; 
    int cantidad=0;
    bool usado[10001];  

    for(int i=0;i<=10000;i++){
        usado[i]=false;
    }

    for(int i=pos;i>=0;i--){
        for (int j=i;j>=0;j--){
            int suma=cadena[i]+cadena[j];
            if(suma>actual && suma<=n && usado[suma]==false){ 
                usado[suma]=true; 
                candidatos[cantidad]=suma;
                cantidad++;
            }
        }
    }

    sort(candidatos,candidatos+cantidad,greater<int>());

    for(int i=0;i<cantidad;i++){ 
        cadena[pos+1]=candidatos[i];
        if(buscar(pos+1)==true){
            return true;
        }
    }
    return false;
}

int main(){
    while(cin>>n){
        if(n==0){
            break;
        }

        if(n==1){
            cout<<"1"<<endl;
            continue;
        }

        cadena[0]=1;

        /*
            Probamos con límite 0, 1, 2, 3...
            hasta encontrar la cadena más corta.
        */
        for (limite = 0; ; limite++) {
            if (buscar(0) == true) {
                for (int i = 0; i <= limite; i++) {
                    if (i > 0) {
                        cout << " ";
                    }
                    cout << cadena[i];
                }
                cout << endl;
                break;
            }
        }
    }

    return 0;
}