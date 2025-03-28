// Diego Rodriguez Cubero DG30 FAL

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

void tiempoOptimo(vector<vector<int>> trabajadores, vector<bool> tareasHechas, int tam, int cont, int& tiempoMinimo, int tiempoActual, int const& mini){
    
    // Si hemos hecho todas las tareas, comprobamos si el tiempo actual es menor que el minimo
    if (cont == tam) {
        tiempoMinimo = min(tiempoMinimo, tiempoActual);
        return;
    }
    // Si no, seguimos calculando el tiempo
    else {
        // Podamos si no vamos a poder encontrar un tiempo menor
        if (tiempoActual + (tam - cont) * mini >= tiempoMinimo) return;
        for (int i = 0; i < tam; i++){
            // Si la tarea no ha sido asignada a nadie, la asignamos
            if (!tareasHechas[i]){
                tareasHechas[i] = true;
                tiempoOptimo(trabajadores, tareasHechas, tam, cont + 1, tiempoMinimo, tiempoActual + trabajadores[cont][i], mini);
                tareasHechas[i] = false;
            }
        }
    }
    return;
}

bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    if (n == 0){
        return false;
    }
    
    else{
        
        // Leemos los datos de entrada guardando el minimo y el maximo
        vector<vector<int>> trabajadores (n, vector<int>(n));
        vector<bool> tareasHechas(n, false);
        int maxi, mini;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int aux;
                std::cin >> aux;
                trabajadores[i][j] = aux;
                maxi = max(maxi, aux);
                mini = min(mini, aux);
            }
        }

        int tiempoMinimo = maxi * n;
        tiempoOptimo(trabajadores, tareasHechas, n, 0, tiempoMinimo, 0, mini);

        std::cout << tiempoMinimo<< std::endl;

        return true;
    }
}

int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}