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

int haceCuantoGanado(int numCiclistas, std::vector<std::string>& ciclistas, string nacionalidad) {
    // Buscamos la nacionalidad indicada desde el final del vector
    while (numCiclistas >= 0 && ciclistas[numCiclistas] != nacionalidad) {
        --numCiclistas;
    }
    return numCiclistas;
}

bool resuelveCaso() {
    
    int numCiclistas;
    std::cin >> numCiclistas;
    
    if (numCiclistas == 0) {
        return false;
    }
    
    else {

        // Leemos los datos
        std::string nacionalidad;
        std::cin >> nacionalidad;
        std::vector<std::string> ciclistas(numCiclistas);
        for (int i = 0; i < numCiclistas; i++) {
            std::cin >> ciclistas[i];
        }

        // Buscamos el ciclista con la nacionalidad indicada
        int pos = haceCuantoGanado(numCiclistas - 1, ciclistas, nacionalidad);

        if (pos == -1) {
            std::cout << "NUNCA" << '\n';
        }
        else {
            std::cout << numCiclistas - pos << '\n';
        }

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