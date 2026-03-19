#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	
	int numero;
	cout<<"Ingrese el Numero: ";
	cin>>numero;
	
	if(numero & 1 == 0){
		cout<<"El Numero"<<numero<<" es par"<<endl;
			}
	else{
		cout<<"El Numero "<<numero<<" es impar"<<endl;
		}
		
		getch();
		return 0;
	
}														