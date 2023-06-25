#include <iostream>
#include <vector>

using namespace std;

// Función para intercambiar dos elementos en un vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función para colocar el pivote en la posición correcta y dividir el vector en dos subvectores
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Elegimos el último elemento como pivote
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high); // Colocamos el pivote en su posición correcta
    return i + 1;
}

// Función recursiva para aplicar Quick Sort en un vector
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Índice del pivote

        // Ordenamos los elementos antes y después del pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir un vector
void imprimirVector(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Vector original: ";
    imprimirVector(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Vector ordenado: ";
    imprimirVector(arr);

    return 0;
}

