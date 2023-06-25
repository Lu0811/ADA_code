#include<iostream>
using namespace std;

void imprimir_cant_instrucciones(int N) {

    int c = 0;
    
    for(int i = 0; i <= N; i++) {
        c++;
        if(i % 2 == 0) {
            c++;
            cout<<i<<" ";
        }
        c++;
    }
    c++;

    cout<<endl<<"Número total de instrucciones: "<<c<<endl;
}

int main() {

    funcion1(5);
    return 0;
}
