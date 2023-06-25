#include<iostream>
using namespace std;

void imprimir_cant_instrucciones(int N) {
    int c = 0;

    for(int i = 0; i <= N; i++) {
        c++;
        for(int j = i; j <= N; j++) {
            c++;
            cout<<i<<" , "<<j<<endl;
            c++;
        }
        c++;
    }
    c++;

    cout<<endl<<"Número total de instrucciones: "<<c<<endl;
}
int main() {
    imprimir_cant_instrucciones(4);
    return 0;
}
