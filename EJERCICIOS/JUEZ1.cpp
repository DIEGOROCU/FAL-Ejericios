//DIEGO RODRIGUEZ CUBERO FAL-DG30

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

void calculaPicosValles(const vector<int> &v, int &picos, int &valles) {

    // Establecemos los valores a 0
    picos = 0;
    valles = 0;

    // Recorremos el vector, teniendo en cuenta que el primer y último elemento no pueden ser picos ni valles
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) picos++;
        if (v[i] < v[i - 1] && v[i] < v[i + 1]) valles++;
    }
}

void resuelveCaso() {
 
    // Leemos el tamaño del vector, y lo declaramos;
    int tam;
    std::cin >> tam;
    std::vector<int> alturas(tam);

    // Leemos el vector
    for (int i = 0; i < tam; i++){
        std::cin >> alturas[i];
    }

    // Calculamos los picos y valles
    int picos, valles;
    calculaPicosValles(alturas, picos, valles);

    // Devolvemos el resultado
    std::cout << picos << " " << valles << '\n';

    
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