#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

// 1. Estructura del cliente ampliada con más atributos
struct Cliente {
    int id;
    string nombre;
    int edad;           // Nuevo campo
    string motivo;      // Nuevo campo
};

int main() {
    queue<Cliente> colaClientes;
    ifstream archivo("clientes_masivo.txt");

    // 2. Cargar clientes en lote desde el archivo (si el archivo existe)
    if (archivo.is_open()) {
        int id, edad;
        string nombre, motivo;
        cout << "--- Cargando clientes desde archivo ---" << endl;
        
        // El archivo debe tener el formato: ID Nombre Edad Motivo (sin espacios en las palabras)
        while (archivo >> id >> nombre >> edad >> motivo) {
            Cliente c;
            c.id = id;
            c.nombre = nombre;
            c.edad = edad;
            c.motivo = motivo;
            
            colaClientes.push(c);
            cout << "Cliente cargado: " << c.nombre << " (ID: " << c.id << ")" << endl;
        }
        archivo.close();
    } else {
        cout << "Aviso: No se pudo abrir 'clientes.txt'. Iniciando con cola vacia." << endl;
    }

    // 3. Bucle para pedir MÁS DATOS manualmente al usuario
    char continuar;
    cout << "\n--- Ingreso manual de nuevos clientes ---" << endl;
    do {
        Cliente cNuevo;
        
        cout << "Ingrese ID: ";
        cin >> cNuevo.id;
        
        // Es crucial limpiar el buffer de memoria antes de leer strings con espacios
        cin.ignore(); 
        
        cout << "Ingrese Nombre: ";
        getline(cin, cNuevo.nombre); // getline permite guardar nombres con espacios
        
        cout << "Ingrese Edad: ";
        cin >> cNuevo.edad;
        
        cin.ignore(); // Limpiar el buffer nuevamente
        
        cout << "Ingrese Motivo de visita: ";
        getline(cin, cNuevo.motivo);

        colaClientes.push(cNuevo); // Agrega el nuevo cliente al final de la cola
        cout << "-> Cliente " << cNuevo.nombre << " encolado exitosamente.\n" << endl;

        cout << "¿Desea registrar otro cliente manualmente? (s/n): ";
        cin >> continuar;
        
    } while (continuar == 's' || continuar == 'S');

    // 4. Procesar clientes (FIFO: el primero en llegar es el primero en salir)
    cout << "\n--- Procesando cola de clientes (FIFO) ---" << endl;
    while (!colaClientes.empty()) {
        Cliente clienteActual = colaClientes.front(); // Obtiene el elemento al frente
        
        // Imprimir todos los datos del cliente
        cout << "Atendiendo a: " << clienteActual.nombre 
             << " | ID: " << clienteActual.id 
             << " | Edad: " << clienteActual.edad 
             << " | Motivo: " << clienteActual.motivo << endl;
        
        colaClientes.pop(); // Elimina el elemento que acaba de ser atendido
    }

    cout << "\nTodos los clientes han sido atendidos." << endl;

    return 0;
}