#include <iostream>   // Permite usar cin y cout
using namespace std;  

int main(){
    int N,M; // Cantidad de CDs de Jack y Jill

    // Procesa todos los casos de prueba
    while(cin>>N>>M){

        // Si ambos son 0, termina la entrada
        if(N==0 && M==0){
            break;
        }

        // Reserva memoria para ambas colecciones
        int *jack=new int[N];
        int *jill=new int[M];

        // Lee los CDs de Jack
        for(int i=0;i<N;i++){
            cin>>jack[i];
        }

        // Lee los CDs de Jill
        for(int i=0;i<M;i++){
            cin>>jill[i];
        }

        int i=0; // Puntero para Jack
        int j=0; // Puntero para Jill
        int comunes=0; // Cantidad de CDs en comun

        // Recorre ambas listas mientras queden elementos
        while(i<N && j<M){
            // Si ambos tienen el mismo catalogo, se encontro un CD en comun
            if(jack[i]==jill[j]){
                comunes++; // Incrementa el contador
                i++; // Avanza en la lista de Jack
                j++; // Avanza en la lista de Jill
            }
            // Si el catalogo de Jack es menor, avanza Jack
            else if(jack[i]<jill[j]){
                i++;
            }
            // Si el catalogo de Jill es menor, avanza Jill
            else{
                j++;
            }
        }

        // Imprime la cantidad de CDs en comun
        cout<<comunes<<"\n";

        // Libera la memoria reservada
        delete[] jack;
        delete[] jill;
    }

    return 0; 
}