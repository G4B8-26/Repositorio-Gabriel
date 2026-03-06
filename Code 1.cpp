#include<iostream>
using namespace std;
int main(){
    int notas []={15, 18, 20, 12};
    int *p= notas;
    cout <<"Recomiendo la calle de las Notas:"<< endl;
    for(int i=0; i<4; i++){
        cout << "Nota" << i << ": " << *(p+i) << "(Direccion: " << (p+i) << ")" << endl;
    }
    return 0;
}    
