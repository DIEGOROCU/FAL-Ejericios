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

int segmentosIgualCerosUnos(const std::vector<int> &v, int longitud) {
    // Variables que vamos a necesitar
    int cant = 1;
    int difUnosCeros = 0;
    int i = longitud;

    while (i < v.size()) {
        
        // Actualizamos la diferencia de unos y ceros
        difUnosCeros += ((v[i] == 1) - (v[i - longitud] == 1)) - ((v[i] == 0) - (v[i - longitud] == 0)); 

        // Si hay la misma cantidad de unos que de ceros, sumamos 1 al resultado
        if (difUnosCeros == 0) {
            cant++;
        }

        i++;

    }

    // Devolvemos el resultado
    return cant;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    //Lee los datos
    int longitud, tam;
    std::cin >> longitud >> tam;
    std::vector<int> v(tam);
    for (int i = 0; i < tam; ++i) {
        std::cin >> v[i];
    }

    // Devolvemos el resultado
    std::cout << segmentosIgualCerosUnos(v, longitud) << '\n';

    //Calcula el resultado
    //Escribe el resultado
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