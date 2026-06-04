#include <iostream>
using namespace std;

// Numero objetivo que queremos alcanzar
int n;

// Aqui iremos almacenando la cadena de sumas
int cadena[25];

bool backtracking(int posicion,int limite){
    // Si llegamos a la profundidad maxima permitida
    if(posicion==limite){
        // Solo es solucion si el ultimo numero es n
        return cadena[posicion]==n;
    }

    // El mayor numero generado hasta ahora
    int maximo=cadena[posicion];

    // PODA:
    // Aunque dupliquemos el valor maximo en cada paso restante,
    // ¿podemos llegar a n?
    //
    // Ejemplo:
    // maximo = 8
    // quedan 2 niveles
    //
    // 8 -> 16 -> 32
    //
    // Si n fuera 100, no vale la pena seguir explorando.
    if(maximo*(1<<(limite-posicion))<n){
        return false;
    }

    // Evita probar varias veces el mismo numero
    bool usado[20001]={false};

    // Elegimos dos numeros ya existentes en la cadena
    for (int i=posicion; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            // Nuevo numero generado
            int siguiente = cadena[i] + cadena[j];

            // La cadena debe ser estrictamente creciente
            if (siguiente <= maximo)
                continue;

            // No tiene sentido generar numeros mayores que n
            if (siguiente > n)
                continue;

            // Ya probamos este numero antes
            if (usado[siguiente])
                continue;

            usado[siguiente] = true;

            // Agregamos el nuevo numero a la cadena
            cadena[posicion + 1] = siguiente;

            // Intentamos completar el resto de la cadena
            if (backtracking(posicion + 1, limite))
                return true;
        }
    }

    // Ninguna opcion funciono
    return false;
}

int main()
{
    // Leer casos hasta encontrar 0
    while (cin >> n && n)
    {
        // Caso especial
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        // Toda cadena empieza con 1
        cadena[0] = 1;

        // Longitud maxima permitida actualmente
        int limite = 0;

        // Iterative Deepening DFS
        //
        // Primero buscamos soluciones de longitud 0
        // luego de longitud 1
        // luego de longitud 2
        // ...
        //
        // La primera encontrada sera minima.
        while (!backtracking(0, limite))
        {
            limite++;
        }

        // Imprimir la cadena encontrada
        for (int i = 0; i <= limite; i++)
        {
            if (i)
                cout << " ";

            cout << cadena[i];
        }

        cout << "\n";
    }

    return 0;
}