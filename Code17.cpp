#include <iostream>
#include <string>
using namespace std;

// Estructura del producto
struct Producto {
    int id;
    string descripcion;
    int cantidad;
    float precio;
};

// Función para ordenar alfabéticamente (por descripción)
void ordenarProductos(Producto *productos, int n) {
    Producto temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (productos[j].descripcion > productos[j + 1].descripcion) {
                temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

// Función para mostrar productos
void mostrarProductos(Producto *productos, int n) {
    cout << "\n=== INVENTARIO ORDENADO ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << i + 1 << endl;
        cout << "ID: " << productos[i].id << endl;
        cout << "Descripcion: " << productos[i].descripcion << endl;
        cout << "Cantidad: " << productos[i].cantidad << endl;
        cout << "Precio: $" << productos[i].precio << endl;
    }
}

int main() {
    int n;

    cout << "Ingrese la cantidad de productos: ";
    cin >> n;

    // Arreglo dinámico con puntero
    Producto *productos = new Producto[n];

    // Entrada de datos
    for (int i = 0; i < n; i++) {
        cout << "\n--- Producto " << i + 1 << " ---\n";
        cout << "ID: ";
        cin >> productos[i].id;

        cin.ignore(); // limpiar buffer

        cout << "Descripcion: ";
        getline(cin, productos[i].descripcion);

        cout << "Cantidad: ";
        cin >> productos[i].cantidad;

        cout << "Precio: ";
        cin >> productos[i].precio;
    }

    // Ordenar productos
    ordenarProductos(productos, n);

    // Mostrar productos
    mostrarProductos(productos, n);

    // Liberar memoria
    delete[] productos;

    return 0;
}