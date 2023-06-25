#include<iostream>
using namespace std;

template<int lenA, int lenB>
void imprimir_cant_instrucciones(int A[lenA], int B[lenB]) {

    int c = 0;

    for(int i = 0; i < lenA; i++) {
        c++;
        for(int j = 0; j < lenB; j++) {
            c++;
            cout<<A[i]<<" , "<<B[j]<<endl;
            c++;
        }
        c++;
    }
    c++;


    cout<<endl<<"Número total de instrucciones: "<<c<<endl;
}

int main() {

    
    int a[3] = {3,4,6};
    int b[2] = {7,2};
    imprimir_cant_instrucciones<3,2>(a,b);

    return 0;
}
