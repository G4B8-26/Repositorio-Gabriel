#include <iostream>
using namespace std;

// Definición de la estructura
struct Empleado {
    string nombre;
    int edad;
    float salario;
};

int main() {
    int N;

    cout << "Ingrese la cantidad de empleados: ";
    cin >> N;

    // Arreglo de estructuras
    Empleado empleados[N];

    // Lectura de datos
    for (int i = 0; i < N; i++) {
        cout << "\nEmpleado " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> empleados[i].nombre;
        cout << "Edad: ";
        cin >> empleados[i].edad;
        cout << "Salario: ";
        cin >> empleados[i].salario;
    }

    // Inicializar mayor y menor
    int posMayor = 0, posMenor = 0;

    // Buscar mayor y menor salario
    for (int i = 1; i < N; i++) {
        if (empleados[i].salario > empleados[posMayor].salario) {
            posMayor = i;
        }
        if (empleados[i].salario < empleados[posMenor].salario) {
            posMenor = i;
        }
    }

    // Mostrar resultados
    cout << "\n--- Empleado con MAYOR salario ---" << endl;
    cout << "Nombre: " << empleados[posMayor].nombre << endl;
    cout << "Edad: " << empleados[posMayor].edad << endl;
    cout << "Salario: " << empleados[posMayor].salario << endl;

    cout << "\n--- Empleado con MENOR salario ---" << endl;
    cout << "Nombre: " << empleados[posMenor].nombre << endl;
    cout << "Edad: " << empleados[posMenor].edad << endl;
    cout << "Salario: " << empleados[posMenor].salario << endl;

    return 0;
}