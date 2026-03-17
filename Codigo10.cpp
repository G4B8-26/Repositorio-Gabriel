#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numero,*dir_numero;
	
	
	cout<<"Digite un numero: ";
	cin>>numero;
	dir_numero = &numero;// Guarda la posicion de memoria
	
	if(*dir_numero%2==0){
		cout<<"El Numero "<<*dir_numero<<" es par"<<endl;
		cout<<"Posicion:"<<dir_numero<<endl;
	}
	else{
		cout<<"El Numero "<<*dir_numero<<" es impar"<<endl;
		cout<<"Posicion:"<<dir_numero<<endl;
	}
	getch();
	return 0;
	

}
