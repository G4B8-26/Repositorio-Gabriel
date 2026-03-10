#include<iostream>
#include <string>
using namespace std;

int main (){
int tam;
cout<<"Cuantos Elementos quieres?";
cin>>tam;

int* arreglo = new int[tam];

delete [] arreglo;

return 0;

}

	

    