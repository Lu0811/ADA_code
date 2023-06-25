#include <iostream>

using namespace std;

// Función para calcular la potencia de un número de forma recursiva
double potencia(double base, int exponente) {
    if (exponente == 0) {
        return 1.0;
    } else if (exponente > 0) {
        return base * potencia(base, exponente - 1);
    } else {
        return 1.0 / potencia(base, -exponente);
    }
}

int main() {
    double base;
    int exponente;

    cout << "Ingrese la base: ";
    cin >> base;

    cout << "Ingrese el exponente: ";
    cin >> exponente;

    double resultado = potencia(base, exponente);

    cout << "El resultado de " << base << " elevado a la " << exponente << " es: " << resultado << endl;

    return 0;
}

