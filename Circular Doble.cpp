#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente, *anterior;
};

void insertarCircularDoble(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr, nullptr};

    if (!cabeza) {
        cabeza = nuevo;
        // Un solo nodo apunta a sí mismo por delante y por detrás
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        // Gracias a la circularidad doble, el último nodo es cabeza->anterior
        Nodo* ultimo = cabeza->anterior; 

        // El nuevo nodo se coloca entre el "ultimo" y la "cabeza"
        ultimo->siguiente = nuevo; // El viejo último apunta al nuevo
        nuevo->anterior = ultimo;  // El nuevo apunta atrás al viejo último
        nuevo->siguiente = cabeza; // El nuevo apunta adelante a la cabeza
        cabeza->anterior = nuevo;  // La cabeza apunta atrás al nuevo que pasa a ser el ultimo
    }
}

int main() {
    Nodo* lista = nullptr;
    insertarCircularDoble(lista, 7);
    insertarCircularDoble(lista, 14);
    cout << "Circular Doble: " << lista->dato << " <-> " << lista->siguiente->dato << std::endl;
    cout << "Prueba de cierre: El anterior de " << lista->dato << " es " << lista->anterior->dato << std::endl;
    return 0;
}