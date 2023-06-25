#include<iostream>
using namespace std;

void imprimir_cant_instrucciones(int N) {

    int c = 0;

    for(int i = 0; i <= N; i++) {
        c++;
        int j = 1;
        c++;
        while (j < N)
        {
            c++;
            cout<<j<<" ";
            c++;
            j *= 2;
            c++;
        }
        c++;
    }
    c++;

    cout<<endl<<"Número total de instrucciones: "<<c<<endl;
}

int main() {

    imprimir_cant_instrucciones(6);
    return 0;
}
