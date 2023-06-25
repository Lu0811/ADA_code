#include <iostream>
#include <vector>

using namespace std;

// Función para fusionar dos subarreglos ordenados en un solo arreglo ordenado
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear arreglos temporales para almacenar los subarreglos
    vector<int> L(n1);
    vector<int> R(n2);

    // Copiar los datos a los arreglos temporales
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Fusionar los arreglos temporales en el arreglo original
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L, si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R, si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función de ordenamiento Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar la mitad izquierda
        mergeSort(arr, left, mid);
        // Ordenar la mitad derecha
        mergeSort(arr, mid + 1, right);

        // Fusionar las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Arreglo original: ";
    imprimirArreglo(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Arreglo ordenado: ";
    imprimirArreglo(arr);

    return 0;
}

