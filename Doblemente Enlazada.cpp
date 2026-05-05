#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarDoble(Nodo*& cabeza, int valor) {
    // Creamos el nodo  sus punteros no señalan a ninguna parte
    Nodo* nuevo = new Nodo{valor, nullptr, nullptr};

    if (!cabeza) {
        // El primero en ingresar es la cabeza y no tiene ni anterior ni siguiente 
        cabeza = nuevo;
    } else {
        Nodo* temp = cabeza;
        // Buscamos el final de la lista
        while (temp->siguiente) temp = temp->siguiente;
        
        // El último nodo actual apunta hacia adelante al nuevo nodo
        temp->siguiente = nuevo;
        // El nuevo nodo apunta hacia atrás al que era el último
        nuevo->anterior = temp;
    }
}

int main() {
    Nodo* lista = nullptr;
    insertarDoble(lista, 50);
    insertarDoble(lista, 100);
    cout << "Lista Doble (hacia adelante): " << lista->dato << " -> " << lista->siguiente->dato <<endl;
    cout << "Lista Doble (hacia atras): " << lista->siguiente->dato << " -> " << lista->siguiente->anterior->dato <<endl;
    return 0;
}