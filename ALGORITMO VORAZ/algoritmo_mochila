#include <iostream>
#include <limits>

void mochila(int M, int V[], int W[], int X[], int N) {
    for (int i = 0; i < N; i++) {
        X[i] = 0;
    }

    int peso_act = 0;
    while (peso_act < M) {
        int j = -1;
        double mejor_valor_peso = -std::numeric_limits<double>::infinity();

        for (int i = 0; i < N; i++) {
            if (X[i] == 0 && static_cast<double>(V[i]) / W[i] > mejor_valor_peso) {
                mejor_valor_peso = static_cast<double>(V[i]) / W[i];
                j = i;
            }
        }

        if (j == -1) {
            break;
        }

        if (peso_act + W[j] <= M) {
            X[j] = 1;
            peso_act += W[j];
        } else {
            X[j] = (M - peso_act) / W[j];
            peso_act = M;
        }
    }
}

int main() {
    const int N = 4;
    int M = 10;
    int V[N] = { 40, 100, 50, 60 };
    int W[N] = { 2, 5, 10, 4 };
    int X[N];

    mochila(M, V, W, X, N);

    std::cout << "Objetos seleccionados: " << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "Objeto " << i + 1 << ": " << X[i] << std::endl;
    }

    return 0;
}
