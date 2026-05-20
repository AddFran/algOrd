#include <iostream>
using namespace std;

void bubbleSort(int n, int array[]){
    int aux;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                aux=array[j];
                array[j]=array[j+1];
                array[j+1]=aux;
            }
        }
    }
}
// Tendremos dos listas, el de los numeros N y el de las consultas Q
void llenarArray(int n,int array[]){
    for(int i=0;i<n;i++)
        cin>>array[i];
}

void buscarNum(int nQ,int nN,int arrayQ[],int arrayN[],int arrayR[]){
    for(int i=0;i<nQ;i++){
        bool flag=true;
        int j=0;
        while(flag && j<nN){
            if(arrayQ[i]==arrayN[j]){
                arrayR[i]=j;
                flag=false;
            }
            else
                arrayR[i]=-1;
            j++;
        }
    }
}

void mostrarRespuesta(int nQ,int arrayQ[],int arrayR[]){
    for(int i=0;i<nQ;i++){
        if(arrayR[i]!=-1)
            cout<<arrayQ[i]<<" found at "<<arrayR[i]+1;
        else
            cout<<arrayQ[i]<<" not found";
        cout<<endl;
    }
}

int main(){
    int numCanicas;
    int numPreguntas;
    int i=1;

    while(true){
        cin>>numCanicas;
        cin>>numPreguntas;

        int arrayCanicas[numCanicas];
        int arrayPreguntas[numPreguntas];
        int arrayRespuestas[numPreguntas];

        llenarArray(numCanicas,arrayCanicas);
        llenarArray(numPreguntas,arrayPreguntas);
        bubbleSort(numCanicas,arrayCanicas);

        buscarNum(numPreguntas,numCanicas,arrayPreguntas,arrayCanicas,arrayRespuestas);
        cout<<"CASE# "<<i<<":"<<endl;
        mostrarRespuesta(numPreguntas,arrayPreguntas,arrayRespuestas);
        i++;
    }

    return 0;
}