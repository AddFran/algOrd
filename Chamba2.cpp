#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using namespace chrono;

struct Resultado{
    string nombre;
    long long pasos;
    long long tiempo_ns;
};

class AlgOrd{
    public:
        static void bubbleSort(vector<int>&,long long&);
        static void selectionSort(vector<int>&,long long&);
        static void insertionSort(vector<int>&,long long&);
        // merge
        static void merge(vector<int>&, int,int,int,long long&);
        static void mergeSort(vector<int>&,int,int,long long&);
        // quick
        static int partition(vector<int>&,int,int,long long&);
        static void quickSort(vector<int>&,int,int,long long&);
};
void AlgOrd::bubbleSort(vector<int>& arr,long long& pasos){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            pasos++;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                pasos++;
            }
        }
    }
}
void AlgOrd::selectionSort(vector<int>& arr,long long& pasos){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            pasos++;
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        swap(arr[i],arr[min_idx]);
        pasos++;
    }
}
void AlgOrd::insertionSort(vector<int>& arr,long long& pasos){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            pasos++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        pasos++;
    }
}
void AlgOrd::merge(vector<int>& arr,int l,int m,int r,long long& pasos){
    int n1=m-l+1;
    int n2=r-m;
    vector<int> L(n1),R(n2);

    for(int i=0;i<n1;i++) 
        L[i]=arr[l+i];
    for(int j=0;j<n2;j++) 
        R[j]=arr[m+1+j];

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        pasos++;
        if(L[i]<=R[j]) 
            arr[k++]=L[i++];
        else 
            arr[k++]=R[j++];
    }
    while(i<n1){ 
        arr[k++]=L[i++]; 
        pasos++; 
    }
    while(j<n2){ 
        arr[k++]=R[j++]; 
        pasos++; 
    }
}
void AlgOrd::mergeSort(vector<int>& arr,int l,int r,long long& pasos){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m,pasos);
        mergeSort(arr,m+1,r,pasos);
        merge(arr,l,m,r,pasos);
    }
}
int AlgOrd::partition(vector<int>& arr,int low,int high,long long& pasos){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        pasos++;
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            pasos++;
        }
    }
    swap(arr[i+1],arr[high]);
    pasos++;
    return i+1;
}
void AlgOrd::quickSort(vector<int>& arr,int low,int high,long long& pasos){
    if(low<high){
        int pi=partition(arr,low,high,pasos);
        quickSort(arr,low,pi-1,pasos);
        quickSort(arr,pi+1,high,pasos);
    }
}

class AlgController{
    private:
        vector<int> original;
    public:
        void generarArray(int,int,int);
        void mostrarArray();
        Resultado ejecutar(string,void(*func)(vector<int>&,long long&));
        Resultado ejecutarMerge();
        Resultado ejecutarQuick();
        vector<Resultado> ejecutarTodos();
};
void AlgController::generarArray(int n,int min_val,int max_val){
    srand(static_cast<unsigned int>(time(nullptr)));
    original.assign(n,0);
    for(int i=0;i<n;i++){
        original[i]=min_val+(rand()%(max_val-min_val+1));
    }
}
void AlgController::mostrarArray(){
    cout<<"Array generado ("<<original.size()<<" elementos)"<<endl;
    if(original.size()<=20){
        for(int x:original) 
            cout<<x<<" ";
        cout<<endl;
    }else
        cout<<"Array demasiado grande para mostrar"<<endl;
    cout<<endl;
}
Resultado AlgController::ejecutar(string nombre, void(*func)(vector<int>&, long long&)){
    vector<int> arr = original;
    long long pasos = 0;
    auto inicio = high_resolution_clock::now();
    func(arr, pasos);
    auto fin = high_resolution_clock::now();
    long long tiempo = duration_cast<nanoseconds>(fin - inicio).count();
    return {nombre, pasos, tiempo};
}
Resultado AlgController::ejecutarMerge(){
    vector<int> arr = original;
    long long pasos = 0;
    auto inicio = high_resolution_clock::now();
    AlgOrd::mergeSort(arr, 0, (int)arr.size() - 1, pasos);
    auto fin = high_resolution_clock::now();
    long long tiempo = duration_cast<nanoseconds>(fin - inicio).count();
    return {"Merge Sort", pasos, tiempo};
}
Resultado AlgController::ejecutarQuick(){
    vector<int> arr = original;
    long long pasos = 0;
    auto inicio = high_resolution_clock::now();
    AlgOrd::quickSort(arr, 0, (int)arr.size() - 1, pasos);
    auto fin = high_resolution_clock::now();
    long long tiempo = duration_cast<nanoseconds>(fin - inicio).count();
    return {"Quick Sort", pasos, tiempo};
}
vector<Resultado> AlgController::ejecutarTodos(){
    vector<Resultado> resultados;
    resultados.push_back(ejecutar("Bubble Sort", AlgOrd::bubbleSort));
    resultados.push_back(ejecutar("Selection Sort", AlgOrd::selectionSort));
    resultados.push_back(ejecutar("Insertion Sort", AlgOrd::insertionSort));
    resultados.push_back(ejecutarMerge());
    resultados.push_back(ejecutarQuick());
    sort(resultados.begin(), resultados.end(), [](const Resultado& a, const Resultado& b) {
        return a.tiempo_ns < b.tiempo_ns;
    });
    return resultados;
}

int main() {
    AlgController controller;
    int n,min_val,max_val;

    cout<<"---------------------------------------------------------"<<endl;
    cout<<" -- Comparacion entre Algoritmos de Ordenamiento V1.0 --"<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    cout<<"Numero de numeros: ";
    cin>>n;
    cout<<"Rango minimo: ";
    cin>>min_val;
    cout<<"Rango maximo: ";
    cin>>max_val;

    controller.generarArray(n,min_val,max_val);
    controller.mostrarArray();

    vector<Resultado> resultados=controller.ejecutarTodos();

    cout<<"Resultados (ordenados por tiempo):\n\n";
    cout<<left<<setw(5)<<"Pos"
        <<setw(20)<<"Algoritmo"
        <<setw(20)<<"Pasos"
        <<setw(20)<<"Tiempo (ns)"<<endl;
    cout<<string(65,'-')<<endl;

    for(int i=0;i<(int)resultados.size();i++) {
        cout<<left<<setw(5)<<i+1
            <<setw(20)<<resultados[i].nombre
            <<setw(20)<<resultados[i].pasos
            <<setw(20)<<resultados[i].tiempo_ns<<endl;
    }

    return 0;
}