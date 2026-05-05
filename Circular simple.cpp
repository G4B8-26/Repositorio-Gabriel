#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarCircular(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};

    if (!cabeza) {
        //  Si está vacía, el nuevo nodo es la cabeza
        cabeza = nuevo;
        // Como es circular, debe apuntar a sí mismo para cerrar el ciclo
        nuevo->siguiente = cabeza;
    } else {
        Nodo* temp = cabeza;
        // Recorremos hasta el nodo cuyo siguiente NO sea la cabeza 
        while (temp->siguiente != cabeza) temp = temp->siguiente;
        
        // El último ahora apunta al nuevo nodo
        temp->siguiente = nuevo;
        // El nuevo nodo apunta a la cabeza para mantener la circularidad
        nuevo->siguiente = cabeza;
    }
}

int main() {
    Nodo* lista = nullptr;
    insertarCircular(lista, 1);
    insertarCircular(lista, 2);
    cout << "Lista Circular: " << lista->dato << " -> " << lista->siguiente->dato;
    cout << " -> (vuelve a) " << lista->siguiente->siguiente->dato <<endl;
    return 0;
}