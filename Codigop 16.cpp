#include <iostream>
using namespace std;

int main() {
    int numeros[10];

    // Llenar el arreglo
    cout << "Ingrese 10 numeros:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> numeros[i];
    }

    // Puntero al arreglo
    int *ptr = numeros;

    cout << "\nNumeros pares y su direccion en memoria:\n";

    for (int i = 0; i < 10; i++) {
        // Verificar si es par usando AND binario
        if ((*(ptr + i) & 1) == 0) {
            cout << "Numero: " << *(ptr + i)
                 << " | Direccion: " << (ptr + i) << endl;
        }
    }

    return 0;
}