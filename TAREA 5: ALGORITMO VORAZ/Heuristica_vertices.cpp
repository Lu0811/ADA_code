#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para encontrar el siguiente vecino más cercano por vértices
int encontrarVecinoMasCercanoPorVertices(int ciudadActual, vector<bool>& visitado, vector<vector<int>>& distancias) {
    int numCiudades = visitado.size();
    int vecinoMasCercano = -1;
    int distanciaMinima = INT_MAX;

    for (int i = 0; i < numCiudades; ++i) {
        if (!visitado[i] && distancias[ciudadActual][i] < distanciaMinima) {
            distanciaMinima = distancias[ciudadActual][i];
            vecinoMasCercano = i;
        }
    }

    return vecinoMasCercano;
}

// Función principal para resolver el TSP utilizando la heurística del vecino más cercano por vértices
vector<int> resolverTSPPorVertices(vector<vector<int>>& distancias) {
    int numCiudades = distancias.size();
    vector<bool> visitado(numCiudades, false);
    vector<int> ruta;
    int ciudadActual = 0; // Selecciona la ciudad inicial

    visitado[ciudadActual] = true;
    ruta.push_back(ciudadActual);

    while (ruta.size() < numCiudades) {
        int siguienteCiudad = encontrarVecinoMasCercanoPorVertices(ciudadActual, visitado, distancias);
        visitado[siguienteCiudad] = true;
        ruta.push_back(siguienteCiudad);
        ciudadActual = siguienteCiudad;
    }

    // Regresar a la ciudad inicial
    ruta.push_back(0);

    return ruta;
}

// Ejemplo de uso
int main() {
    vector<vector<int>> distancias = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<int> rutaOptima = resolverTSPPorVertices(distancias);

    // Imprimir la ruta óptima
    cout << "Ruta óptima: ";
    for (int ciudad : rutaOptima) {
        cout << ciudad << " ";
    }
    cout << endl;

    return 0;
}

