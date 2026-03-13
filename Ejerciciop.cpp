#include<iostream>
#include<conio.h>
#include <string>
using namespace std;

struct Corredor {
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
}C1;

int main(){
	char categoria[20];
	
	
	
	cout<<"Nombre: ";
	cin.getline(C1.nombre,20,'\n');
	cout<<"Edad: ";
	cin>>C1.edad;
	fflush(stdin);
	cout<<"Sexo: ";
	cin.getline(C1.sexo,10,'\n');
	cout<<"Club: ";
	cin.getline(C1.club,20,'\n');
	
	if(C1.edad <=18){
		strcpy(categoria,"Juvenil");
	}
	else if(C1.edad<=40){
		strcpy(categoria,"Mayor");
	}
	else{
		strcpy(categoria,"Veterano");
	}
	cout<<"\n\n Datos Del Corredor: "<<endl;
	cout<<"Nombre: "<<C1.nombre<<endl;
	cout<<"Sexo: "<<C1.sexo<<endl;
	cout<<"Edad: "<<C1.edad<<endl;
	cout<<"Club: "<<C1.club<<endl;
	cout<<"Categoria: "<<categoria<<endl;
	
	
	getch();
	return 0;

}
