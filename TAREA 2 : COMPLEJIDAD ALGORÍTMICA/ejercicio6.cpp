#include<iostream>
using namespace std;

void imprimir_cant_instrucciones(int N) {
    int c = 0;

    int i = 1;
    c++;

    while (i < N)
    {
        c++;
        cout<<i<<" ";
        c++;
        i *= 2;
        c++;
    }
    c++;

    cout<<endl<<"Número total de instrucciones: "<<c<<endl;
}

int main() {

    imprimir_cant_instrucciones(5);
    return 0;
}
