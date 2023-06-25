#include<iostream>
using namespace std;

void imprimir_cant_instrucciones() {
     int c = 0;

    int N = 1000;
    c++;

    c++;
    if(N % 2 == 0) {
        c++;
        cout<<"Par"<<endl;
    }

    else {
        c++;
        cout<<"Impar"<<endl;
    }
    c++;


    cout<<endl<<"Número total de instrucciones: "<<c<<endl;
}

int main() {

    imprimir_cant_instrucciones();

    return 0;
}
