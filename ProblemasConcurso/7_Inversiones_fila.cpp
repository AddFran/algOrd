#include <iostream>   // Permite usar cin y cout
using namespace std; 

int a[200000];           // Arreglo original
int aux[200000];         // Arreglo auxiliar para el Merge Sort
long long inversiones=0; // Almacena la cantidad de inversiones

// Funcion que mezcla dos mitades ordenadas y cuenta inversiones
void merge(int izq,int medio,int der){
    int i=izq;     // Recorre la mitad izquierda
    int j=medio+1; // Recorre la mitad derecha
    int k=izq;     // Recorre el arreglo auxiliar

    // Mezcla ambas mitades
    while(i<=medio && j<=der){
        // Si el elemento izquierdo es menor o igual, no genera inversiones
        if(a[i]<=a[j]){
            aux[k]=a[i];
            i++;
        }
        else{
            aux[k]=a[j];             // Si el elemento derecho es menor, genera inversiones
            inversiones+=medio-i+1;  // Todos los elementos restantes de la izquierda forman inversiones
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de la mitad izquierda
    while(i<=medio){
        aux[k]=a[i];
        i++;
        k++;
    }

    // Copia los elementos restantes de la mitad derecha
    while(j<=der){
        aux[k]=a[j];
        j++;
        k++;
    }

    // Copia nuevamente al arreglo original
    for(int x=izq;x<=der;x++){
        a[x]=aux[x];
    }
}

// Funcion Merge Sort
void mergeSort(int izq,int der){
    // Caso base, un solo elemento
    if(izq>=der){
        return;
    }

    int medio=(izq+der)/2;  // Calcula el punto medio  
    mergeSort(izq,medio);   // Ordena la mitad izquierda    
    mergeSort(medio+1,der); // Ordena la mitad derecha   
    merge(izq,medio,der);   // Mezcla ambas mitades
}

int main(){
    int n; // Cantidad de estudiantes
    cin>>n;

    // Lee las estaturas
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    mergeSort(0,n-1);        // Ejecuta el Merge Sort
    cout<<inversiones<<endl; // Imprime la cantidad de inversiones

    return 0; 
}