#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&,int);
void sacarPila(Nodo *&, int &);

int main(){
	Nodo *pila=NULL;
	int dato, limite; // Añadimos 'limite' para saber cuántos ingresar
	
	cout<<"¿Cuantos elementos desea ingresar a la pila?: ";
	cin>>limite;
	
	// Bucle dinámico para agregar elementos
	for(int i = 0; i < limite; i++){
		cout<<"Digite un Numero ("<<(i+1)<<"): ";
		cin>>dato;
		agregarPila(pila, dato);
	}
	
	cout<<"\nSacando los Elementos de la pila: ";
	while(pila != NULL){
		sacarPila(pila,dato);
		if(pila != NULL){
			cout<<dato<<", ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	getch();
	return 0;
}

void agregarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\tElemento "<<n<<" agregado a PILA"<<endl;
}

void sacarPila(Nodo *&pila,int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}