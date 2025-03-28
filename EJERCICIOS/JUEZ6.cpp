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

int equilibrio(vector<int> const& v) {
    // Inicializamos los contadores
    int numCeros = 0, numUnos = 0;
    int pmax = -1;
    // Recorremos el vector
    for (int i = 0; i < v.size(); ++i) {
        // Actualizamos los contadores si es necesario
        if (v[i] == 0) {
            ++numCeros;
        } else if(v[i] == 1) {
            ++numUnos;
        }
        // Actualizamos la maxima posición p donde hay la misma cantidad de ceros que de unos hasta p
        if (numCeros == numUnos) {
            pmax = i;
        }
    }
    // Devolvemos la posición máxima
    return pmax;
}

void resuelveCaso() {
 
    // Leemos los datos de la entrada
    int tam;
    cin >> tam;
    vector<int> vector(tam);
    for (int i = 0; i < tam; ++i) {
        cin >> vector[i];
    }

    // Calculamos la solución
    int sol = equilibrio(vector);

    // Escribimos la solución
    std::cout << sol << '\n';

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}