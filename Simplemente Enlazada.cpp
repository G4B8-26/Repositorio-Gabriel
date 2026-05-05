#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};


void insertar(Nodo*& cabeza, int valor) {
    // Reservamos memoria para el nuevo nodo se le asigna un dato
    // El siguiente de este nuevo nodo siempre será nullptr porque va al final
    Nodo* nuevo = new Nodo{valor, nullptr};

    if (!cabeza) {
        // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
        cabeza = nuevo;
    } else {
        // Si hay elementos, creamos un puntero temporal para no perder la cabeza
        Nodo* temp = cabeza;
        // Recorremos la lista hasta llegar al último nodo 
        while (temp->siguiente) temp = temp->siguiente;
        // El antiguo último nodo ahora apunta al nuevo nodo.
        temp->siguiente = nuevo;
    }
}

int main() {
    Nodo* lista = nullptr;
    insertar(lista, 10);
    insertar(lista, 20);
    cout << "Lista Simple: " << lista->dato << " -> " << lista->siguiente->dato << " -> NULL" <<endl;
    return 0;
}