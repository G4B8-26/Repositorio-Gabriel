#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int x = 50, y = 10;

    cout << "Antes: x=" << x << ", y=" << y << endl;

    swap(&x, &y);

    cout << "Despues: x=" << x << ", y=" << y << endl;

    return 0;
}

    