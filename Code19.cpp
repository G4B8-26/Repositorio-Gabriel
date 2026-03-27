#include <iostream>
#include <string>

using namespace std;

struct Producto {
    int id;
    string descripcion;
    int cantidad;
    float precio;
};

// Función para ordenar por descripción
void ordenarProductos(Producto *productos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (productos[j].precio > productos[j + 1].precio) {
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

// Función para mostrar el inventario
void mostrarProductos(Producto *productos, int n) {
    cout << "\n=== INVENTARIO ORDENADO ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << i + 1 << endl;
        cout << "ID: " << productos[i].id << endl;
        cout << "Descripcion: " << productos[i].descripcion << endl;
        cout << "Cantidad: " << productos[i].cantidad << endl;
        cout << "Precio: " << productos[i].precio <<"$"<< endl;
    }
}
   

int main() {
    int n;
    cout << "Ingrese la cantidad inicial de productos: ";
    cin >> n;

    // Creación del arreglo dinámico
    Producto *productos = new Producto[n];

    // 1. Entrada de datos
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << i + 1 << ":" << endl;
        cout << "ID: "; cin >> productos[i].id;
        cin.ignore();
        cout << "Descripcion: "; getline(cin, productos[i].descripcion);
        cout << "Cantidad: "; cin >> productos[i].cantidad;
        cout << "Precio: "; cin >> productos[i].precio;
    }

    // 2. Ordenar y mostrar
    ordenarProductos(productos, n);
    mostrarProductos(productos, n);

    
    int idEliminar;
    cout << "\nIngrese el ID del producto que desea eliminar: ";
    cin >> idEliminar;

    int indiceEncontrado = -1;
    for (int i = 0; i < n; i++) {
        if (productos[i].id = idEliminar) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        for (int i = indiceEncontrado; i < n - 1; i++) {
            productos[i] = productos[i + 1];
        }
        n--; 
        cout << "\n---Producto eliminado con exito---\n" << endl;
    } 
    
    

    // 4. Mostrar resultado final y liberar memoria
    mostrarProductos(productos, n);

    delete[] productos;
    return 0;
}