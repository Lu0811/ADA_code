
#include <iostream>
#include <vector>

using namespace std;

// Función de búsqueda binaria
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Si el elemento medio es igual al objetivo, se ha encontrado
        if (arr[mid] == target) {
            return mid;
        }

        // Si el elemento medio es mayor que el objetivo, se busca en la mitad izquierda
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // Si el elemento medio es menor que el objetivo, se busca en la mitad derecha
        else {
            left = mid + 1;
        }
    }

    // Si no se encuentra el objetivo, se devuelve -1
    return -1;
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;

    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "El elemento " << target << " se encuentra en el índice " << index << endl;
    } else {
        cout << "El elemento " << target << " no se encuentra en el arreglo" << endl;
    }

    return 0;
}
