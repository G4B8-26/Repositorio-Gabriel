#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    int numeros[10], *dir_numeros;
	
	for(int i=0;i<10;i++){
		cout<<"Digite un Numero["<<i<<"]: ";
		cin>>numeros[i];
	}
    dir_numeros= numeros;//Posicion de Memoria comienza numeros
	
	for(int i=0;i<10;i++){
		if(*dir_numeros%2==0){
			cout<<"El Numero "<<*dir_numeros<<" es Par"<<endl;
			cout<<"Posicion: "<<dir_numeros<<endl;
		}
		else{
			cout<<"El Numero "<<*dir_numeros<<" es Impar"<<endl;
			cout<<"Posicion: "<<dir_numeros<<endl;
		}
		dir_numeros++;

	}
	
	getch();
	return 0;
	

}
