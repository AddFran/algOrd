#include <iostream>
#include <algorithm>
using namespace std;

// Función para verificar si el arreglo está ordenado
bool esta_ordenado(int arreglo[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arreglo[i] > arreglo[i + 1]) {
            return false;
        }
    }
    return true;
}

// Función recursiva de backtracking para contar los mapas de intercambio mínimo
int contar_caminos_minimos(int arreglo[], int n) {
    // Caso base: si el arreglo está ordenado, encontramos un mapa válido
    if (esta_ordenado(arreglo, n)) {
        return 1;
    }
    
    int contador = 0;
    
    // Intentar todos los intercambios de pares adyacentes
    for (int i = 0; i < n - 1; i++) {
        // Solo intercambiamos si ayuda a ordenar (reducir inversiones)
        if (arreglo[i] > arreglo[i + 1]) {
            // Realizar el intercambio
            swap(arreglo[i], arreglo[i + 1]);
            
            // Llamada recursiva para el siguiente paso
            contador += contar_caminos_minimos(arreglo, n);
            
            // Retroceso (Backtrack): deshacer el intercambio
            swap(arreglo[i], arreglo[i + 1]);
        }
    }
    
    return contador;
}

int main() {
    // Redirigir entrada desde archivo
    freopen("input.txt", "r", stdin);
    // Redirigir salida a archivo
    freopen("output.txt", "w", stdout);
    
    int n;
    int case_num = 1;
    
    // Leer mientras haya casos
    while (cin >> n && n != 0) {
        int arreglo[5]; // n ≤ 5
        
        for (int i = 0; i < n; i++) {
            cin >> arreglo[i];
        }
        
        // Regla especial: si ya está ordenado, el resultado es 0
        if (esta_ordenado(arreglo, n)) {
            cout << "There are 0 swap maps for input data set " << case_num << ".\n";
        } else {
            int total = contar_caminos_minimos(arreglo, n);
            cout << "There are " << total << " swap maps for input data set " << case_num << ".\n";
        }
        
        case_num++;
    }
    
    return 0;
}