#include<iostream>
using namespace std;

void intercambiar(int *ptrA, int *ptrB) {
    int auxiliar = *ptrA; // Guardar el valor de ptrA en una variable temporal
    *ptrA = *ptrB;    // Asignar el valor de ptrB a ptrA
    *ptrB = auxiliar;     // Asignar el valor temporal (original de ptrA) a ptrB
}
int main () {
    int x = 5, y = 10;
    
    cout << "Original: x = " << x << ", y = " << y << endl;
    
    intercambiar(&x, &y); // Pasar las direcciones de x y y
    
    cout << "Intercambiado: x = " << x << ", y = " << y << endl;
    
    return 0;
}   