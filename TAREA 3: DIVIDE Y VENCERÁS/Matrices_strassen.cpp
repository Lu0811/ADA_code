#include <iostream>
#include <vector>

using namespace std;

// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// Función para multiplicar matrices utilizando el algoritmo de Strassen
vector<vector<int>> multiplicarMatricesStrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Caso base: matrices 1x1
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // Dividir las matrices en submatrices
    int mid = n / 2;

    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));

    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Calcular los productos de Strassen
    vector<vector<int>> P1 = multiplicarMatricesStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    vector<vector<int>> P2 = multiplicarMatricesStrassen(sumarMatrices(A21, A22), B11);
    vector<vector<int>> P3 = multiplicarMatricesStrassen(A11, restarMatrices(B12, B22));
    vector<vector<int>> P4 = multiplicarMatricesStrassen(A22, restarMatrices(B21, B11));
    vector<vector<int>> P5 = multiplicarMatricesStrassen(sumarMatrices(A11, A12), B22);
    vector<vector<int>> P6 = multiplicarMatricesStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    vector<vector<int>> P7 = multiplicarMatricesStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // Calcular las submatrices del resultado
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(P1, P4), P5), P7);
    vector<vector<int>> C12 = sumarMatrices(P3, P5);
    vector<vector<int>> C21 = sumarMatrices(P2, P4);
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(P1, P3), P2), P6);

    // Combinar las submatrices en la matriz resultado
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    cout << "Matriz A:" << endl;
    imprimirMatriz(A);
    cout << endl;

    cout << "Matriz B:" << endl;
    imprimirMatriz(B);
    cout << endl;

    vector<vector<int>> C = multiplicarMatricesStrassen(A, B);

    cout << "Resultado de la multiplicación:" << endl;
    imprimirMatriz(C);

    return 0;
}

