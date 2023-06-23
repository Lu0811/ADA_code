#include <iostream>
#include <limits>

void devolver_cambio(int P, int C[], int X[], int N) {
    for (int i = 0; i < N; i++) {
        X[i] = 0;
    }

    int act = 0;
    int i = 0;
    while (act != P && i < N) {
        if (C[i] <= (P - act)) {
            X[i] = (P - act) / C[i];
            act += C[i] * X[i];
        }
        i++;
    }

    if (act != P) {
        std::cout << "No existe solución" << std::endl;
        return;
    }
}

int main() {
    const int N = 3;
    int P = 180;
    int C[N] = { 100, 90, 1 };
    int X[N];

    devolver_cambio(P, C, X, N);

    std::cout << "Monedas utilizadas: " << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << C[i] << " centavos (" << X[i] << " moneda(s)) ";
    }

    return 0;
}
